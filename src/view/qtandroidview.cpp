#include "qtandroidview_p.h"
#include "qtandroiddrawable_p.h"
#include "qtandroidcolordrawable_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidlayoutparams_p.h"
#include <QtCore/qcoreevent.h>
#include <QtCore/qhash.h>

QtAndroidView::QtAndroidView(QtAndroidView *parent) :
    QtAndroidContextual(parent), m_parent(0), m_background(0), m_backgroundResource(0),
    m_visible(true), m_layoutParams(0), m_top(0), m_left(0), m_right(0), m_bottom(0)
{
    static int id = 0;
    m_id = ++id;

    if (parent)
        setParentView(parent);

    connect(this, SIGNAL(instanceChanged()), this, SLOT(updateLayoutParams()));
    connect(this, SIGNAL(instanceChanged()), this, SLOT(updateBackground()));
}

QtAndroidView::~QtAndroidView()
{
    foreach (QtAndroidView *child, m_children)
        child->setParentView(0);
    if (m_parent)
        setParentView(0);
}

int QtAndroidView::identifier() const
{
    return m_id;
}

void QtAndroidView::setIdentifier(int identifier)
{
    m_id = identifier;
}

QtAndroidView *QtAndroidView::parentView() const
{
    return m_parent;
}

void QtAndroidView::setParentView(QtAndroidView *parent)
{
    if (m_parent != parent) {
        if (m_parent)
            m_parent->removeChild(this);
        m_parent = parent;
        viewChange(ViewParentChange, parent);
        if (parent)
            parent->addChild(this);
        emit parentChanged();
    }
}

QList<QtAndroidView *> QtAndroidView::childViews() const
{
    return m_children;
}

QQmlListProperty<QtAndroidView> QtAndroidView::children()
{
    return QQmlListProperty<QtAndroidView>(this, 0, &QtAndroidView::children_append, &QtAndroidView::children_count,
                                                   &QtAndroidView::children_at, &QtAndroidView::children_clear);
}

QtAndroidLayoutParams *QtAndroidView::layoutParams() const
{
    return m_layoutParams;
}

void QtAndroidView::setLayoutParams(QtAndroidLayoutParams *params)
{
    if (m_layoutParams != params) {
        if (m_layoutParams) {
            disconnect(m_layoutParams, SIGNAL(instanceChanged()), this, SLOT(updateLayoutParams()));
            m_layoutParams->destruct();
        }
        m_layoutParams = params;
        if (m_layoutParams) {
            connect(m_layoutParams, SIGNAL(instanceChanged()), this, SLOT(updateLayoutParams()));
            if (isValid())
                m_layoutParams->construct();
        }
    }
}

QtAndroidDrawable *QtAndroidView::background() const
{
    return m_background;
}

void QtAndroidView::setBackground(QtAndroidDrawable *background, int resource)
{
    if (m_background != background) {
        if (m_background) {
            disconnect(m_background, SIGNAL(instanceChanged()), this, SLOT(updateBackground()));
            m_background->destruct();
        }
        m_background = background;
        m_backgroundResource = resource;
        if (m_background) {
            connect(m_background, SIGNAL(instanceChanged()), this, SLOT(updateBackground()));
            if (!resource)
                m_background->construct();
        }
        emit backgroundChanged();
    }
}

int QtAndroidView::backgroundColor() const
{
    QtAndroidColorDrawable *drawable = qobject_cast<QtAndroidColorDrawable *>(m_background);
    if (drawable)
        return drawable->color();
    return 0; // TODO
}

void QtAndroidView::setBackgroundColor(int color)
{
    setBackground(new QtAndroidColorDrawable(color, this));
}

int QtAndroidView::backgroundResource() const
{
    return m_backgroundResource;
}

void QtAndroidView::setBackgroundResource(int resource)
{
    if (m_backgroundResource != resource) {
        setBackground(new QtAndroidDrawable(this), resource);
        emit backgroundResourceChanged();
    }
}

bool QtAndroidView::isVisible() const
{
    return m_visible;
}

void QtAndroidView::setVisible(bool visible)
{
    if (m_visible != visible) {
        m_visible = visible;
        // TODO: VISIBLE(0), INVISIBLE(4), GONE(8)
        QtAndroid::callIntMethod(instance(), "setVisibility", visible ? 0 : 4);
        emit visibleChanged();
    }
}

bool QtAndroidView::hasFocus() const
{
    if (m_focus.isNull())
        return false;
    return m_focus.value();
}

bool QtAndroidView::updateFocus(bool arg)
{
    if (arg != hasFocus()) {
        m_focus = arg;
        emit focusChanged();
        return true;
    }
    return false;
}

qreal QtAndroidView::x() const
{
    return left(); // TODO: + translationX
}

qreal QtAndroidView::y() const
{
    return top(); // TODO: + translationY
}

int QtAndroidView::top() const
{
    if (m_top.isNull())
        return 0;
    return m_top.value();
}

void QtAndroidView::setTop(int top)
{
    if (m_top.isNull() || m_top.value() != top) {
        m_top = top;
        QtAndroid::callIntMethod(instance(), "setTop", top);
        emit topChanged();
    }
}

int QtAndroidView::left() const
{
    if (m_left.isNull())
        return 0;
    return m_left.value();
}

void QtAndroidView::setLeft(int left)
{
    if (m_left.isNull() || m_left.value() != left) {
        m_left = left;
        QtAndroid::callIntMethod(instance(), "setLeft", left);
        emit leftChanged();
    }
}

int QtAndroidView::right() const
{
    if (m_right.isNull())
        return 0;
    return m_right.value();
}

void QtAndroidView::setRight(int right)
{
    if (m_right.isNull() || m_right.value() != right) {
        m_right = right;
        QtAndroid::callIntMethod(instance(), "setRight", right);
        emit rightChanged();
    }
}

int QtAndroidView::bottom() const
{
    if (m_bottom.isNull())
        return 0;
    return m_bottom.value();
}

void QtAndroidView::setBottom(int bottom)
{
    if (m_bottom.isNull() || m_bottom.value() != bottom) {
        m_bottom = bottom;
        QtAndroid::callIntMethod(instance(), "setBottom", bottom);
        emit bottomChanged();
    }
}

int QtAndroidView::width() const
{
    return right() - left();
}

void QtAndroidView::setWidth(int width)
{
    setRight(left() + width);
}

int QtAndroidView::height() const
{
    return bottom() - top();
}

void QtAndroidView::setHeight(int height)
{
    setBottom(top() + height);
}

void QtAndroidView::updateGeometry(int t, int l, int r, int b)
{
    if (t != top()) {
        m_top = t;
        emit topChanged();
        emit yChanged();
    }
    if (l != left()) {
        m_left = l;
        emit leftChanged();
        emit xChanged();
    }
    if (r != right()) {
        m_right = r;
        emit rightChanged();
        emit widthChanged();
    }
    if (b != bottom()) {
        m_bottom = b;
        emit bottomChanged();
        emit heightChanged();
    }
}

int QtAndroidView::padding() const
{
    if (!m_padding.isNull())
        return m_padding.value();
    return 0;
}

void QtAndroidView::setPadding(int padding)
{
    if (m_padding.isNull() || m_padding.value() != padding) {
        m_padding = padding;
        emit paddingChanged();
    }
}

int QtAndroidView::paddingTop() const
{
    if (m_paddingTop.isNull())
        return padding();
    return m_paddingTop.value();
}

void QtAndroidView::setPaddingTop(int padding)
{
    if (m_paddingTop.isNull() || m_paddingTop.value() != padding) {
        m_paddingTop = padding;
        emit paddingTopChanged();
    }
}

int QtAndroidView::paddingLeft() const
{
    if (m_paddingLeft.isNull())
        return padding();
    return m_paddingLeft.value();
}

void QtAndroidView::setPaddingLeft(int padding)
{
    if (m_paddingLeft.isNull() || m_paddingLeft.value() != padding) {
        m_paddingLeft = padding;
        emit paddingLeftChanged();
    }
}

int QtAndroidView::paddingRight() const
{
    if (m_paddingRight.isNull())
        return padding();
    return m_paddingRight.value();
}

void QtAndroidView::setPaddingRight(int padding)
{
    if (m_paddingRight.isNull() || m_paddingRight.value() != padding) {
        m_paddingRight = padding;
        emit paddingRightChanged();
    }
}

int QtAndroidView::paddingBottom() const
{
    if (m_paddingBottom.isNull())
        return padding();
    return m_paddingBottom.value();
}

void QtAndroidView::setPaddingBottom(int padding)
{
    if (m_paddingBottom.isNull() || m_paddingBottom.value() != padding) {
        m_paddingBottom = padding;
        emit paddingBottomChanged();
    }
}

void QtAndroidView::viewChange(ViewChange change, const ViewChangeData &data)
{
    switch (change) {
    case ViewParentChange:       // data.view
    case ViewChildAddedChange:   // data.view
    case ViewChildRemovedChange: // data.view
    case ViewVisibilityChange:   // data.boolean
    default:
        break;
    }
}

void QtAndroidView::addChild(QtAndroidView *child)
{
    if (!m_children.contains(child)) {
        m_children.append(child);
        viewChange(ViewChildAddedChange, child);
        emit childrenChanged();
    }
}

void QtAndroidView::removeChild(QtAndroidView *child)
{
    if (m_children.removeOne(child)) {
        viewChange(ViewChildRemovedChange, child);
        emit childrenChanged();
    }
}

void QtAndroidView::children_append(QQmlListProperty<QtAndroidView> *list, QtAndroidView *child)
{
    if (QtAndroidView *that = qobject_cast<QtAndroidView *>(list->object))
        that->addChild(child);
}

int QtAndroidView::children_count(QQmlListProperty<QtAndroidView> *list)
{
    if (QtAndroidView *that = qobject_cast<QtAndroidView *>(list->object))
        return that->m_children.count();
    return 0;
}

QtAndroidView *QtAndroidView::children_at(QQmlListProperty<QtAndroidView> *list, int index)
{
    if (QtAndroidView *that = qobject_cast<QtAndroidView *>(list->object))
        return that->m_children.at(index);
    return 0;
}

void QtAndroidView::children_clear(QQmlListProperty<QtAndroidView> *list)
{
    if (QtAndroidView *that = qobject_cast<QtAndroidView *>(list->object)) {
        while (!that->m_children.isEmpty())
            that->m_children.first()->setParentView(0);
    }
}

QAndroidJniObject QtAndroidView::onCreate()
{
    Q_ASSERT(!QtAndroid::isMainQtThread());

    return QAndroidJniObject("android/view/View",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidView::onInflate(QAndroidJniObject &instance)
{
    Q_ASSERT(!QtAndroid::isMainQtThread());

    QtAndroidContextual::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/view/QtViewListener",
                                   "(Landroid/view/View;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    instance.callMethod<void>("setId", "(I)V", m_id);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    // TODO: VISIBLE(0), INVISIBLE(4), GONE(8)
    instance.callMethod<void>("setVisibility", "(I)V", m_visible ? 0 : 4);
    instance.callMethod<void>("setPadding", "(IIII)V", paddingLeft(), paddingTop(), paddingRight(), paddingBottom());
    if (!m_top.isNull())
        instance.callMethod<void>("setTop", "(I)V", m_top.value());
    if (!m_left.isNull())
        instance.callMethod<void>("setLeft", "(I)V", m_left.value());
    if (!m_right.isNull())
        instance.callMethod<void>("setRight", "(I)V", m_right.value());
    if (!m_bottom.isNull())
        instance.callMethod<void>("setBottom", "(I)V", m_bottom.value());

    if (m_backgroundResource != 0) {
        QAndroidJniObject background = ctx().callObjectMethod("getDrawable", "(I)Landroid/graphics/drawable/Drawable;", m_backgroundResource);
        m_background->inflate(background);
    }
}

void QtAndroidView::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onClick", "(J)V", reinterpret_cast<void *>(onClick)},
                               {"onFocusChange", "(JZ)V", reinterpret_cast<void *>(onFocusChange)},
                               {"onLayoutChange", "(JIIII)V", reinterpret_cast<void *>(onLayoutChange)}
                               /*{"onLongClick", "(J)V", reinterpret_cast<void *>(onLongClick)}*/};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidView::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidView *view = reinterpret_cast<QtAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection);
}

void QtAndroidView::onFocusChange(JNIEnv *env, jobject object, jlong instance, jboolean hasFocus)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidView *view = reinterpret_cast<QtAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "updateFocus", Qt::QueuedConnection, Q_ARG(bool, hasFocus));
}

void QtAndroidView::onLayoutChange(JNIEnv *env, jobject object, jlong instance, jint left, jint top, jint right, jint bottom)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidView *view = reinterpret_cast<QtAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "updateGeometry", Qt::QueuedConnection, Q_ARG(int, top), Q_ARG(int, left), Q_ARG(int, right), Q_ARG(int, bottom));
}

bool QtAndroidView::onLongClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidView *view = reinterpret_cast<QtAndroidView *>(instance);
    if (view) {
        //qDebug() << "onLongClick:" << view;
        QMetaObject::invokeMethod(view, "longClick", Qt::QueuedConnection);
    }
    return true; // TODO: accept
}

bool QtAndroidView::event(QEvent *event)
{
    if (event->type() == QEvent::Polish) {
        QtAndroidView *view = qobject_cast<QtAndroidView *>(parent());
        if (view)
            setParentView(view);
    }
    return QtAndroidContextual::event(event);
}

void QtAndroidView::updateBackground()
{
    if (!isValid() || !m_background)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject background = m_background->instance();
    QtAndroid::callFunction([=]() {
        view.callMethod<void>("setBackground", "(Landroid/graphics/drawable/Drawable;)V", background.object());
    });
}

void QtAndroidView::updateLayoutParams()
{
    if (!isValid() || !m_layoutParams)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject params = m_layoutParams->instance();
    QtAndroid::callFunction([=]() {
        view.callMethod<void>("setLayoutParams",
                              "(Landroid/view/ViewGroup$LayoutParams;)V",
                              params.object());
    });
}
