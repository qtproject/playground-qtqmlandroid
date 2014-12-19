#include "qtqmlandroidview_p.h"
#include "qtqmlandroiddrawable_p.h"
#include "qtqmlandroidcolordrawable_p.h"
#include "qtqmlandroidlayoutparams_p.h"
#include "qtqmlandroidanimation_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qhash.h>

QT_BEGIN_NAMESPACE

QtQmlAndroidView::QtQmlAndroidView(QtQmlAndroidView *parent) :
    QtQmlAndroidContextual(parent), m_parent(0), m_background(0), m_backgroundResource(0),
    m_animation(0), m_polishing(false), m_visible(true), m_layoutParams(0),
    m_top(0), m_left(0), m_right(0), m_bottom(0)
{
    static int id = 0;
    m_id = ++id;

    if (parent)
        setParentView(parent);

    // TODO: find a better place for this (upon construction of the native control perhaps?)
    requestPolish();
}

QtQmlAndroidView::~QtQmlAndroidView()
{
    foreach (QtQmlAndroidView *child, m_children)
        child->setParentView(0);
    if (m_parent)
        setParentView(0);
}

int QtQmlAndroidView::identifier() const
{
    return m_id;
}

void QtQmlAndroidView::setIdentifier(int identifier)
{
    m_id = identifier;
}

QtQmlAndroidView *QtQmlAndroidView::parentView() const
{
    return m_parent;
}

void QtQmlAndroidView::setParentView(QtQmlAndroidView *parent)
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

QList<QtQmlAndroidView *> QtQmlAndroidView::childViews() const
{
    return m_children;
}

QQmlListProperty<QtQmlAndroidView> QtQmlAndroidView::children()
{
    return QQmlListProperty<QtQmlAndroidView>(this, 0, &QtQmlAndroidView::children_append, &QtQmlAndroidView::children_count,
                                                   &QtQmlAndroidView::children_at, &QtQmlAndroidView::children_clear);
}

QtQmlAndroidLayoutParams *QtQmlAndroidView::layoutParams() const
{
    return m_layoutParams;
}

void QtQmlAndroidView::setLayoutParams(QtQmlAndroidLayoutParams *params)
{
    if (m_layoutParams != params) {
        if (m_layoutParams) {
            disconnect(m_layoutParams, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidView::updateLayoutParams);
            m_layoutParams->destruct();
        }
        m_layoutParams = params;
        if (m_layoutParams) {
            connect(m_layoutParams, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidView::updateLayoutParams);
            if (isValid())
                m_layoutParams->construct();
        }
    }
}

QtQmlAndroidDrawable *QtQmlAndroidView::background() const
{
    return m_background;
}

void QtQmlAndroidView::setBackground(QtQmlAndroidDrawable *background, int resource)
{
    if (m_background != background) {
        if (m_background) {
            disconnect(m_background, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidView::updateBackground);
            m_background->destruct();
        }
        m_background = background;
        m_backgroundResource = resource;
        if (m_background) {
            connect(m_background, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidView::updateBackground);
            if (!resource)
                m_background->construct();
        }
        emit backgroundChanged();
    }
}

QtQmlAndroidAnimation *QtQmlAndroidView::animation() const
{
    return m_animation;
}

void QtQmlAndroidView::setAnimation(QtQmlAndroidAnimation *animation)
{
    if (m_animation != animation) {
        if (m_animation) {
            disconnect(m_animation, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidView::updateAnimation);
            m_animation->destruct();
        }
        m_animation = animation;
        if (m_animation) {
            connect(m_animation, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidView::updateAnimation);
            if (isValid())
                m_animation->construct();
        }
        emit animationChanged();
    }
}

int QtQmlAndroidView::backgroundColor() const
{
    QtQmlAndroidColorDrawable *drawable = qobject_cast<QtQmlAndroidColorDrawable *>(m_background);
    if (drawable)
        return drawable->color();
    return 0; // TODO
}

void QtQmlAndroidView::setBackgroundColor(int color)
{
    setBackground(new QtQmlAndroidColorDrawable(color, this));
}

int QtQmlAndroidView::backgroundResource() const
{
    return m_backgroundResource;
}

void QtQmlAndroidView::setBackgroundResource(int resource)
{
    if (m_backgroundResource != resource) {
        setBackground(new QtQmlAndroidDrawable(this), resource);
        emit backgroundResourceChanged();
    }
}

bool QtQmlAndroidView::isVisible() const
{
    return m_visible;
}

void QtQmlAndroidView::setVisible(bool visible)
{
    if (m_visible != visible) {
        m_visible = visible;
        // TODO: VISIBLE(0), INVISIBLE(4), GONE(8)
        QtQmlAndroid::callIntMethod(instance(), "setVisibility", visible ? 0 : 4);
        emit visibleChanged();
    }
}

bool QtQmlAndroidView::hasFocus() const
{
    if (m_focus.isNull())
        return false;
    return m_focus.value();
}

bool QtQmlAndroidView::updateFocus(bool arg)
{
    if (arg != hasFocus()) {
        m_focus = arg;
        emit focusChanged();
        return true;
    }
    return false;
}

qreal QtQmlAndroidView::x() const
{
    return left(); // TODO: + translationX
}

qreal QtQmlAndroidView::y() const
{
    return top(); // TODO: + translationY
}

int QtQmlAndroidView::top() const
{
    if (m_top.isNull())
        return 0;
    return m_top.value();
}

void QtQmlAndroidView::setTop(int top)
{
    if (m_top.isNull() || m_top.value() != top) {
        m_top = top;
        QtQmlAndroid::callIntMethod(instance(), "setTop", top);
        emit topChanged();
    }
}

int QtQmlAndroidView::left() const
{
    if (m_left.isNull())
        return 0;
    return m_left.value();
}

void QtQmlAndroidView::setLeft(int left)
{
    if (m_left.isNull() || m_left.value() != left) {
        m_left = left;
        QtQmlAndroid::callIntMethod(instance(), "setLeft", left);
        emit leftChanged();
    }
}

int QtQmlAndroidView::right() const
{
    if (m_right.isNull())
        return 0;
    return m_right.value();
}

void QtQmlAndroidView::setRight(int right)
{
    if (m_right.isNull() || m_right.value() != right) {
        m_right = right;
        QtQmlAndroid::callIntMethod(instance(), "setRight", right);
        emit rightChanged();
    }
}

int QtQmlAndroidView::bottom() const
{
    if (m_bottom.isNull())
        return 0;
    return m_bottom.value();
}

void QtQmlAndroidView::setBottom(int bottom)
{
    if (m_bottom.isNull() || m_bottom.value() != bottom) {
        m_bottom = bottom;
        QtQmlAndroid::callIntMethod(instance(), "setBottom", bottom);
        emit bottomChanged();
    }
}

int QtQmlAndroidView::width() const
{
    return right() - left();
}

void QtQmlAndroidView::setWidth(int width)
{
    setRight(left() + width);
}

int QtQmlAndroidView::height() const
{
    return bottom() - top();
}

void QtQmlAndroidView::setHeight(int height)
{
    setBottom(top() + height);
}

void QtQmlAndroidView::updateGeometry(int t, int l, int r, int b)
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

int QtQmlAndroidView::padding() const
{
    if (!m_padding.isNull())
        return m_padding.value();
    return 0;
}

void QtQmlAndroidView::setPadding(int padding)
{
    if (m_padding.isNull() || m_padding.value() != padding) {
        m_padding = padding;
        emit paddingChanged();
    }
}

int QtQmlAndroidView::paddingTop() const
{
    if (m_paddingTop.isNull())
        return padding();
    return m_paddingTop.value();
}

void QtQmlAndroidView::setPaddingTop(int padding)
{
    if (m_paddingTop.isNull() || m_paddingTop.value() != padding) {
        m_paddingTop = padding;
        emit paddingTopChanged();
    }
}

int QtQmlAndroidView::paddingLeft() const
{
    if (m_paddingLeft.isNull())
        return padding();
    return m_paddingLeft.value();
}

void QtQmlAndroidView::setPaddingLeft(int padding)
{
    if (m_paddingLeft.isNull() || m_paddingLeft.value() != padding) {
        m_paddingLeft = padding;
        emit paddingLeftChanged();
    }
}

int QtQmlAndroidView::paddingRight() const
{
    if (m_paddingRight.isNull())
        return padding();
    return m_paddingRight.value();
}

void QtQmlAndroidView::setPaddingRight(int padding)
{
    if (m_paddingRight.isNull() || m_paddingRight.value() != padding) {
        m_paddingRight = padding;
        emit paddingRightChanged();
    }
}

int QtQmlAndroidView::paddingBottom() const
{
    if (m_paddingBottom.isNull())
        return padding();
    return m_paddingBottom.value();
}

void QtQmlAndroidView::setPaddingBottom(int padding)
{
    if (m_paddingBottom.isNull() || m_paddingBottom.value() != padding) {
        m_paddingBottom = padding;
        emit paddingBottomChanged();
    }
}

void QtQmlAndroidView::viewChange(ViewChange change, const ViewChangeData &data)
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

void QtQmlAndroidView::addChild(QtQmlAndroidView *child)
{
    if (!m_children.contains(child)) {
        m_children.append(child);
        viewChange(ViewChildAddedChange, child);
        emit childrenChanged();
    }
}

void QtQmlAndroidView::removeChild(QtQmlAndroidView *child)
{
    if (m_children.removeOne(child)) {
        viewChange(ViewChildRemovedChange, child);
        emit childrenChanged();
    }
}

void QtQmlAndroidView::children_append(QQmlListProperty<QtQmlAndroidView> *list, QtQmlAndroidView *child)
{
    if (QtQmlAndroidView *that = qobject_cast<QtQmlAndroidView *>(list->object))
        that->addChild(child);
}

int QtQmlAndroidView::children_count(QQmlListProperty<QtQmlAndroidView> *list)
{
    if (QtQmlAndroidView *that = qobject_cast<QtQmlAndroidView *>(list->object))
        return that->m_children.count();
    return 0;
}

QtQmlAndroidView *QtQmlAndroidView::children_at(QQmlListProperty<QtQmlAndroidView> *list, int index)
{
    if (QtQmlAndroidView *that = qobject_cast<QtQmlAndroidView *>(list->object))
        return that->m_children.at(index);
    return 0;
}

void QtQmlAndroidView::children_clear(QQmlListProperty<QtQmlAndroidView> *list)
{
    if (QtQmlAndroidView *that = qobject_cast<QtQmlAndroidView *>(list->object)) {
        while (!that->m_children.isEmpty())
            that->m_children.first()->setParentView(0);
    }
}

QAndroidJniObject QtQmlAndroidView::onCreate()
{
    Q_ASSERT(!QtQmlAndroid::isMainQtThread());

    return QAndroidJniObject("android/view/View",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidView::onInflate(QAndroidJniObject &instance)
{
    Q_ASSERT(!QtQmlAndroid::isMainQtThread());

    QtQmlAndroidContextual::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/view/QtViewListener",
                                   "(Landroid/view/View;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    instance.callMethod<void>("setId", "(I)V", m_id);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    // TODO: VISIBLE(0), INVISIBLE(4), GONE(8)
    instance.callMethod<void>("setVisibility", "(I)V", m_visible ? 0 : 4);
    if (!m_padding.isNull() || !m_paddingTop.isNull() || !m_paddingLeft.isNull() || !m_paddingRight.isNull() || !m_paddingBottom.isNull())
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

void QtQmlAndroidView::onRegisterNativeMethods(jobject listener)
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

void QtQmlAndroidView::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidView *view = reinterpret_cast<QtQmlAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection);
}

void QtQmlAndroidView::onFocusChange(JNIEnv *env, jobject object, jlong instance, jboolean hasFocus)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidView *view = reinterpret_cast<QtQmlAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "updateFocus", Qt::QueuedConnection, Q_ARG(bool, hasFocus));
}

void QtQmlAndroidView::onLayoutChange(JNIEnv *env, jobject object, jlong instance, jint left, jint top, jint right, jint bottom)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidView *view = reinterpret_cast<QtQmlAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "updateGeometry", Qt::QueuedConnection, Q_ARG(int, top), Q_ARG(int, left), Q_ARG(int, right), Q_ARG(int, bottom));
}

bool QtQmlAndroidView::onLongClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidView *view = reinterpret_cast<QtQmlAndroidView *>(instance);
    if (view) {
        //qDebug() << "onLongClick:" << view;
        QMetaObject::invokeMethod(view, "longClick", Qt::QueuedConnection);
    }
    return true; // TODO: accept
}

void QtQmlAndroidView::requestPolish()
{
    if (!m_polishing) {
        m_polishing = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::PolishRequest));
    }
}

void QtQmlAndroidView::polish()
{
}

bool QtQmlAndroidView::event(QEvent *event)
{
    if (event->type() == QEvent::PolishRequest) {
        QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView *>(parent());
        if (view)
            setParentView(view);
        polish();
        m_polishing = false;
    }
    return QtQmlAndroidContextual::event(event);
}

void QtQmlAndroidView::objectChange(ObjectChange change)
{
    QtQmlAndroidContextual::objectChange(change);
    if (change == InstanceChange) {
        updateLayoutParams();
        updateBackground();
        updateAnimation();
    }
}

void QtQmlAndroidView::updateBackground()
{
    if (!isValid() || !m_background)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject background = m_background->instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("setBackground", "(Landroid/graphics/drawable/Drawable;)V", background.object());
    });
}

void QtQmlAndroidView::updateAnimation()
{
    if (!isValid() || !m_animation || !m_animation->isValid())
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject animation = m_animation->instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("startAnimation", "(Landroid/view/animation/Animation;)V", animation.object());
    });
}

void QtQmlAndroidView::updateLayoutParams()
{
    if (!isValid() || !m_layoutParams)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject params = m_layoutParams->instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("setLayoutParams",
                              "(Landroid/view/ViewGroup$LayoutParams;)V",
                              params.object());
    });
}

QT_END_NAMESPACE
