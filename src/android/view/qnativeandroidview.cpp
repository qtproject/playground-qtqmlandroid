/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt QML Android module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qnativeandroidview_p.h"
#include "qnativeandroiddrawable_p.h"
#include "qnativeandroidcolordrawable_p.h"
#include "qnativeandroidlayoutparams_p.h"
#include "qnativeandroidanimation_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qhash.h>

QT_BEGIN_NAMESPACE

QNativeAndroidView::QNativeAndroidView(QNativeAndroidView *parent) :
    QNativeAndroidContextual(parent), m_parent(0), m_background(0), m_backgroundResource(0),
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

QNativeAndroidView::~QNativeAndroidView()
{
    foreach (QNativeAndroidView *child, m_children)
        child->setParentView(0);
    if (m_parent)
        setParentView(0);
}

int QNativeAndroidView::identifier() const
{
    return m_id;
}

void QNativeAndroidView::setIdentifier(int identifier)
{
    m_id = identifier;
}

QNativeAndroidView *QNativeAndroidView::parentView() const
{
    return m_parent;
}

void QNativeAndroidView::setParentView(QNativeAndroidView *parent)
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

QList<QNativeAndroidView *> QNativeAndroidView::childViews() const
{
    return m_children;
}

QQmlListProperty<QNativeAndroidView> QNativeAndroidView::children()
{
    return QQmlListProperty<QNativeAndroidView>(this, 0, &QNativeAndroidView::children_append, &QNativeAndroidView::children_count,
                                                   &QNativeAndroidView::children_at, &QNativeAndroidView::children_clear);
}

QNativeAndroidLayoutParams *QNativeAndroidView::layoutParams() const
{
    return m_layoutParams;
}

void QNativeAndroidView::setLayoutParams(QNativeAndroidLayoutParams *params)
{
    if (m_layoutParams != params) {
        if (m_layoutParams) {
            disconnect(m_layoutParams, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateLayoutParams);
            m_layoutParams->destruct();
        }
        m_layoutParams = params;
        if (m_layoutParams) {
            connect(m_layoutParams, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateLayoutParams);
            if (isValid())
                m_layoutParams->construct();
        }
    }
}

QNativeAndroidDrawable *QNativeAndroidView::background() const
{
    return m_background;
}

void QNativeAndroidView::setBackground(QNativeAndroidDrawable *background, int resource)
{
    if (m_background != background) {
        if (m_background) {
            disconnect(m_background, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateBackground);
            m_background->destruct();
        }
        m_background = background;
        m_backgroundResource = resource;
        if (m_background) {
            connect(m_background, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateBackground);
            if (!resource)
                m_background->construct();
        }
        emit backgroundChanged();
    }
}

QNativeAndroidAnimation *QNativeAndroidView::animation() const
{
    return m_animation;
}

void QNativeAndroidView::setAnimation(QNativeAndroidAnimation *animation)
{
    if (m_animation != animation) {
        if (m_animation) {
            disconnect(m_animation, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateAnimation);
            m_animation->destruct();
        }
        m_animation = animation;
        if (m_animation) {
            connect(m_animation, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateAnimation);
            if (isValid())
                m_animation->construct();
        }
        emit animationChanged();
    }
}

int QNativeAndroidView::backgroundColor() const
{
    QNativeAndroidColorDrawable *drawable = qobject_cast<QNativeAndroidColorDrawable *>(m_background);
    if (drawable)
        return drawable->color();
    return 0; // TODO
}

void QNativeAndroidView::setBackgroundColor(int color)
{
    setBackground(new QNativeAndroidColorDrawable(color, this));
}

int QNativeAndroidView::backgroundResource() const
{
    return m_backgroundResource;
}

void QNativeAndroidView::setBackgroundResource(int resource)
{
    if (m_backgroundResource != resource) {
        setBackground(new QNativeAndroidDrawable(this), resource);
        emit backgroundResourceChanged();
    }
}

bool QNativeAndroidView::isVisible() const
{
    return m_visible;
}

void QNativeAndroidView::setVisible(bool visible)
{
    if (m_visible != visible) {
        m_visible = visible;
        // TODO: VISIBLE(0), INVISIBLE(4), GONE(8)
        QtQmlAndroid::callIntMethod(instance(), "setVisibility", visible ? 0 : 4);
        emit visibleChanged();
    }
}

bool QNativeAndroidView::hasFocus() const
{
    if (m_focus.isNull())
        return false;
    return m_focus;
}

bool QNativeAndroidView::updateFocus(bool arg)
{
    if (arg != hasFocus()) {
        m_focus = arg;
        emit focusChanged();
        return true;
    }
    return false;
}

qreal QNativeAndroidView::x() const
{
    return left() + translationX();
}

void QNativeAndroidView::setX(qreal x)
{
    setTranslationX(x - left());
}

qreal QNativeAndroidView::y() const
{
    return top() + translationY();
}

void QNativeAndroidView::setY(qreal y)
{
    setTranslationY(y - top());
}

qreal QNativeAndroidView::z() const
{
    return elevation() + translationZ();
}

void QNativeAndroidView::setZ(qreal z)
{
    setTranslationZ(z - elevation());
}

int QNativeAndroidView::top() const
{
    if (m_top.isNull())
        return 0;
    return m_top;
}

void QNativeAndroidView::setTop(int top)
{
    if (m_top.isNull() || m_top != top) {
        m_top = top;
        QtQmlAndroid::callIntMethod(instance(), "setTop", top);
        emit topChanged();
        emit yChanged();
    }
}

int QNativeAndroidView::left() const
{
    if (m_left.isNull())
        return 0;
    return m_left;
}

void QNativeAndroidView::setLeft(int left)
{
    if (m_left.isNull() || m_left != left) {
        m_left = left;
        QtQmlAndroid::callIntMethod(instance(), "setLeft", left);
        emit leftChanged();
        emit xChanged();
    }
}

int QNativeAndroidView::right() const
{
    if (m_right.isNull())
        return 0;
    return m_right;
}

void QNativeAndroidView::setRight(int right)
{
    if (m_right.isNull() || m_right != right) {
        m_right = right;
        QtQmlAndroid::callIntMethod(instance(), "setRight", right);
        emit rightChanged();
    }
}

int QNativeAndroidView::bottom() const
{
    if (m_bottom.isNull())
        return 0;
    return m_bottom;
}

void QNativeAndroidView::setBottom(int bottom)
{
    if (m_bottom.isNull() || m_bottom != bottom) {
        m_bottom = bottom;
        QtQmlAndroid::callIntMethod(instance(), "setBottom", bottom);
        emit bottomChanged();
    }
}

int QNativeAndroidView::width() const
{
    return right() - left();
}

void QNativeAndroidView::setWidth(int width)
{
    setRight(left() + width);
}

int QNativeAndroidView::height() const
{
    return bottom() - top();
}

void QNativeAndroidView::setHeight(int height)
{
    setBottom(top() + height);
}

void QNativeAndroidView::updateGeometry(int t, int l, int r, int b)
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

int QNativeAndroidView::padding() const
{
    if (!m_padding.isNull())
        return m_padding;
    return 0;
}

void QNativeAndroidView::setPadding(int padding)
{
    if (m_padding.isNull() || m_padding != padding) {
        m_padding = padding;
        emit paddingChanged();
    }
}

int QNativeAndroidView::paddingTop() const
{
    if (m_paddingTop.isNull())
        return padding();
    return m_paddingTop;
}

void QNativeAndroidView::setPaddingTop(int padding)
{
    if (m_paddingTop.isNull() || m_paddingTop != padding) {
        m_paddingTop = padding;
        emit paddingTopChanged();
    }
}

int QNativeAndroidView::paddingLeft() const
{
    if (m_paddingLeft.isNull())
        return padding();
    return m_paddingLeft;
}

void QNativeAndroidView::setPaddingLeft(int padding)
{
    if (m_paddingLeft.isNull() || m_paddingLeft != padding) {
        m_paddingLeft = padding;
        emit paddingLeftChanged();
    }
}

int QNativeAndroidView::paddingRight() const
{
    if (m_paddingRight.isNull())
        return padding();
    return m_paddingRight;
}

void QNativeAndroidView::setPaddingRight(int padding)
{
    if (m_paddingRight.isNull() || m_paddingRight != padding) {
        m_paddingRight = padding;
        emit paddingRightChanged();
    }
}

int QNativeAndroidView::paddingBottom() const
{
    if (m_paddingBottom.isNull())
        return padding();
    return m_paddingBottom;
}

void QNativeAndroidView::setPaddingBottom(int padding)
{
    if (m_paddingBottom.isNull() || m_paddingBottom != padding) {
        m_paddingBottom = padding;
        emit paddingBottomChanged();
    }
}

qreal QNativeAndroidView::alpha() const
{
    if (!m_alpha.isNull())
        return m_alpha;
    return 0;
}

void QNativeAndroidView::setAlpha(qreal alpha)
{
    if (m_alpha.isNull() || m_alpha != alpha) {
        m_alpha = alpha;
        QtQmlAndroid::callRealMethod(instance(), "setAlpha", alpha);
        emit alphaChanged();
    }
}

qreal QNativeAndroidView::scaleX() const
{
    if (!m_scaleX.isNull())
        return m_scaleX;
    return 0;
}

void QNativeAndroidView::setScaleX(qreal scaleX)
{
    if (m_scaleX.isNull() || m_scaleX != scaleX) {
        m_scaleX = scaleX;
        QtQmlAndroid::callRealMethod(instance(), "setScaleX", scaleX);
        emit scaleXChanged();
    }
}

qreal QNativeAndroidView::scaleY() const
{
    if (!m_scaleY.isNull())
        return m_scaleY;
    return 0;
}

void QNativeAndroidView::setScaleY(qreal scaleY)
{
    if (m_scaleY.isNull() || m_scaleY != scaleY) {
        m_scaleY = scaleY;
        QtQmlAndroid::callRealMethod(instance(), "setScaleY", scaleY);
        emit scaleYChanged();
    }
}

qreal QNativeAndroidView::pivotX() const
{
    if (!m_pivotX.isNull())
        return m_pivotX;
    return 0;
}

void QNativeAndroidView::setPivotX(qreal pivotX)
{
    if (m_pivotX.isNull() || m_pivotX != pivotX) {
        m_pivotX = pivotX;
        QtQmlAndroid::callRealMethod(instance(), "setPivotX", pivotX);
        emit pivotXChanged();
    }
}

qreal QNativeAndroidView::pivotY() const
{
    if (!m_pivotY.isNull())
        return m_pivotY;
    return 0;
}

void QNativeAndroidView::setPivotY(qreal pivotY)
{
    if (m_pivotY.isNull() || m_pivotY != pivotY) {
        m_pivotY = pivotY;
        QtQmlAndroid::callRealMethod(instance(), "setPivotY", pivotY);
        emit pivotYChanged();
    }
}

qreal QNativeAndroidView::rotation() const
{
    if (!m_rotation.isNull())
        return m_rotation;
    return 0;
}

void QNativeAndroidView::setRotation(qreal rotation)
{
    if (m_rotation.isNull() || m_rotation != rotation) {
        m_rotation = rotation;
        QtQmlAndroid::callRealMethod(instance(), "setRotation", rotation);
        emit rotationChanged();
    }
}

qreal QNativeAndroidView::rotationX() const
{
    if (!m_rotationX.isNull())
        return m_rotationX;
    return 0;
}

void QNativeAndroidView::setRotationX(qreal rotationX)
{
    if (m_rotationX.isNull() || m_rotationX != rotationX) {
        m_rotationX = rotationX;
        QtQmlAndroid::callRealMethod(instance(), "setRotationX", rotationX);
        emit rotationXChanged();
    }
}

qreal QNativeAndroidView::rotationY() const
{
    if (!m_rotationY.isNull())
        return m_rotationY;
    return 0;
}

void QNativeAndroidView::setRotationY(qreal rotationY)
{
    if (m_rotationY.isNull() || m_rotationY != rotationY) {
        m_rotationY = rotationY;
        QtQmlAndroid::callRealMethod(instance(), "setRotationY", rotationY);
        emit rotationYChanged();
    }
}

qreal QNativeAndroidView::translationX() const
{
    if (!m_translationX.isNull())
        return m_translationX;
    return 0;
}

void QNativeAndroidView::setTranslationX(qreal translationX)
{
    if (m_translationX.isNull() || m_translationX != translationX) {
        m_translationX = translationX;
        QtQmlAndroid::callRealMethod(instance(), "setTranslationX", translationX);
        emit translationXChanged();
        emit xChanged();
    }
}

qreal QNativeAndroidView::translationY() const
{
    if (!m_translationY.isNull())
        return m_translationY;
    return 0;
}

void QNativeAndroidView::setTranslationY(qreal translationY)
{
    if (m_translationY.isNull() || m_translationY != translationY) {
        m_translationY = translationY;
        QtQmlAndroid::callRealMethod(instance(), "setTranslationY", translationY);
        emit translationYChanged();
        emit yChanged();
    }
}

qreal QNativeAndroidView::translationZ() const
{
    if (!m_translationZ.isNull())
        return m_translationZ;
    return 0;
}

void QNativeAndroidView::setTranslationZ(qreal translationZ)
{
    if (m_translationZ.isNull() || m_translationZ != translationZ) {
        m_translationZ = translationZ;
        QtQmlAndroid::callRealMethod(instance(), "setTranslationZ", translationZ);
        emit translationZChanged();
        emit zChanged();
    }
}

qreal QNativeAndroidView::elevation() const
{
    if (!m_elevation.isNull())
        return m_elevation;
    return 0;
}

void QNativeAndroidView::setElevation(qreal elevation)
{
    if (m_elevation.isNull() || m_elevation != elevation) {
        m_elevation = elevation;
        QtQmlAndroid::callRealMethod(instance(), "setElevation", elevation);
        emit elevationChanged();
        emit zChanged();
    }
}

void QNativeAndroidView::viewChange(ViewChange change, const ViewChangeData &data)
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

void QNativeAndroidView::addChild(QNativeAndroidView *child)
{
    if (!m_children.contains(child)) {
        m_children.append(child);
        viewChange(ViewChildAddedChange, child);
        emit childrenChanged();
    }
}

void QNativeAndroidView::removeChild(QNativeAndroidView *child)
{
    if (m_children.removeOne(child)) {
        viewChange(ViewChildRemovedChange, child);
        emit childrenChanged();
    }
}

void QNativeAndroidView::children_append(QQmlListProperty<QNativeAndroidView> *list, QNativeAndroidView *child)
{
    if (QNativeAndroidView *that = qobject_cast<QNativeAndroidView *>(list->object))
        that->addChild(child);
}

int QNativeAndroidView::children_count(QQmlListProperty<QNativeAndroidView> *list)
{
    if (QNativeAndroidView *that = qobject_cast<QNativeAndroidView *>(list->object))
        return that->m_children.count();
    return 0;
}

QNativeAndroidView *QNativeAndroidView::children_at(QQmlListProperty<QNativeAndroidView> *list, int index)
{
    if (QNativeAndroidView *that = qobject_cast<QNativeAndroidView *>(list->object))
        return that->m_children.at(index);
    return 0;
}

void QNativeAndroidView::children_clear(QQmlListProperty<QNativeAndroidView> *list)
{
    if (QNativeAndroidView *that = qobject_cast<QNativeAndroidView *>(list->object)) {
        while (!that->m_children.isEmpty())
            that->m_children.first()->setParentView(0);
    }
}

QAndroidJniObject QNativeAndroidView::onCreate()
{
    Q_ASSERT(!QtQmlAndroid::isMainQtThread());

    return QAndroidJniObject("android/view/View",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidView::onInflate(QAndroidJniObject &instance)
{
    Q_ASSERT(!QtQmlAndroid::isMainQtThread());

    QNativeAndroidContextual::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/view/QmlViewListener",
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
        instance.callMethod<void>("setTop", "(I)V", m_top);
    if (!m_left.isNull())
        instance.callMethod<void>("setLeft", "(I)V", m_left);
    if (!m_right.isNull())
        instance.callMethod<void>("setRight", "(I)V", m_right);
    if (!m_bottom.isNull())
        instance.callMethod<void>("setBottom", "(I)V", m_bottom);
    if (!m_alpha.isNull())
        instance.callMethod<void>("setAlpha", "(F)V", m_alpha);
    if (!m_scaleX.isNull())
        instance.callMethod<void>("setScaleX", "(F)V", m_scaleX);
    if (!m_scaleY.isNull())
        instance.callMethod<void>("setScaleY", "(F)V", m_scaleY);
    if (!m_pivotX.isNull())
        instance.callMethod<void>("setPivotX", "(F)V", m_pivotX);
    if (!m_pivotY.isNull())
        instance.callMethod<void>("setPivotY", "(F)V", m_pivotY);
    if (!m_rotation.isNull())
        instance.callMethod<void>("setRotation", "(F)V", m_rotation);
    if (!m_rotationX.isNull())
        instance.callMethod<void>("setRotationX", "(F)V", m_rotationX);
    if (!m_rotationY.isNull())
        instance.callMethod<void>("setRotationY", "(F)V", m_rotationY);
    if (!m_translationX.isNull())
        instance.callMethod<void>("setTranslationX", "(F)V", m_translationX);
    if (!m_translationY.isNull())
        instance.callMethod<void>("setTranslationY", "(F)V", m_translationY);
    if (!m_translationZ.isNull())
        instance.callMethod<void>("setTranslationZ", "(F)V", m_translationZ);
    if (!m_elevation.isNull())
        instance.callMethod<void>("setElevation", "(F)V", m_elevation);

    if (m_backgroundResource != 0) {
        QAndroidJniObject background = ctx().callObjectMethod("getDrawable", "(I)Landroid/graphics/drawable/Drawable;", m_backgroundResource);
        m_background->inflate(background);
    }
}

void QNativeAndroidView::onRegisterNativeMethods(jobject listener)
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

void QNativeAndroidView::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidView *view = reinterpret_cast<QNativeAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection);
}

void QNativeAndroidView::onFocusChange(JNIEnv *env, jobject object, jlong instance, jboolean hasFocus)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidView *view = reinterpret_cast<QNativeAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "updateFocus", Qt::QueuedConnection, Q_ARG(bool, hasFocus));
}

void QNativeAndroidView::onLayoutChange(JNIEnv *env, jobject object, jlong instance, jint left, jint top, jint right, jint bottom)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidView *view = reinterpret_cast<QNativeAndroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "updateGeometry", Qt::QueuedConnection, Q_ARG(int, top), Q_ARG(int, left), Q_ARG(int, right), Q_ARG(int, bottom));
}

bool QNativeAndroidView::onLongClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidView *view = reinterpret_cast<QNativeAndroidView *>(instance);
    if (view) {
        //qDebug() << "onLongClick:" << view;
        QMetaObject::invokeMethod(view, "longClick", Qt::QueuedConnection);
    }
    return true; // TODO: accept
}

void QNativeAndroidView::requestPolish()
{
    if (!m_polishing) {
        m_polishing = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::PolishRequest));
    }
}

void QNativeAndroidView::polish()
{
}

bool QNativeAndroidView::event(QEvent *event)
{
    if (event->type() == QEvent::PolishRequest) {
        QNativeAndroidView *view = qobject_cast<QNativeAndroidView *>(parent());
        if (view)
            setParentView(view);
        polish();
        m_polishing = false;
    }
    return QNativeAndroidContextual::event(event);
}

void QNativeAndroidView::objectChange(ObjectChange change)
{
    QNativeAndroidContextual::objectChange(change);
    if (change == InstanceChange) {
        updateLayoutParams();
        updateBackground();
        updateAnimation();
    }
}

void QNativeAndroidView::updateBackground()
{
    if (!isValid() || !m_background)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject background = m_background->instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("setBackground", "(Landroid/graphics/drawable/Drawable;)V", background.object());
    });
}

void QNativeAndroidView::updateAnimation()
{
    if (!isValid() || !m_animation || !m_animation->isValid())
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject animation = m_animation->instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("startAnimation", "(Landroid/view/animation/Animation;)V", animation.object());
    });
}

void QNativeAndroidView::updateLayoutParams()
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
