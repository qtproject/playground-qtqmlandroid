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
#include "qnativeandroidview_p_p.h"
#include "qnativeandroiddrawable_p.h"
#include "qnativeandroidcolordrawable_p.h"
#include "qnativeandroidlayoutparams_p.h"
#include "qnativeandroidanimation_p.h"
#include "qtnativeandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qhash.h>

QT_BEGIN_NAMESPACE

void QNativeAndroidViewPrivate::init()
{
    Q_Q(QNativeAndroidView);
    static int nextId = 0;
    id = ++nextId;

    if (context)
        q->setContext(context);

    // TODO: find a better place for this (upon construction of the native control perhaps?)
    q->requestPolish();
}

QNativeAndroidView::QNativeAndroidView(QNativeAndroidContext *context)
    : QNativeAndroidContextual(*(new QNativeAndroidViewPrivate), context)
{
    Q_D(QNativeAndroidView);
    d->init();
}

QNativeAndroidView::QNativeAndroidView(QNativeAndroidViewPrivate &dd, QNativeAndroidContext *context)
    : QNativeAndroidContextual(dd, context)
{
    Q_D(QNativeAndroidView);
    d->init();
}

QNativeAndroidView::~QNativeAndroidView()
{
    Q_D(QNativeAndroidView);
    foreach (QNativeAndroidView *child, d->children)
        child->setParentView(0);
    if (d->parent)
        setParentView(0);
}

int QNativeAndroidView::identifier() const
{
    Q_D(const QNativeAndroidView);
    return d->id;
}

void QNativeAndroidView::setIdentifier(int identifier)
{
    Q_D(QNativeAndroidView);
    d->id = identifier;
}

QNativeAndroidView *QNativeAndroidView::parentView() const
{
    Q_D(const QNativeAndroidView);
    return d->parent;
}

void QNativeAndroidView::setParentView(QNativeAndroidView *parent)
{
    Q_D(QNativeAndroidView);
    if (d->parent != parent) {
        if (d->parent)
            d->parent->removeChild(this);
        d->parent = parent;
        viewChange(ViewParentChange, parent);
        if (parent)
            parent->addChild(this);
        emit parentChanged();
    }
}

QList<QNativeAndroidView *> QNativeAndroidView::childViews() const
{
    Q_D(const QNativeAndroidView);
    return d->children;
}

QQmlListProperty<QNativeAndroidView> QNativeAndroidView::children()
{
    Q_D(QNativeAndroidView);
    return QQmlListProperty<QNativeAndroidView>(this, d, &QNativeAndroidView::children_append, &QNativeAndroidView::children_count,
                                                   &QNativeAndroidView::children_at, &QNativeAndroidView::children_clear);
}

QNativeAndroidLayoutParams *QNativeAndroidView::layoutParams() const
{
    Q_D(const QNativeAndroidView);
    return d->layoutParams;
}

void QNativeAndroidView::setLayoutParams(QNativeAndroidLayoutParams *params)
{
    Q_D(QNativeAndroidView);
    if (d->layoutParams != params) {
        if (d->layoutParams) {
            disconnect(d->layoutParams, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateLayoutParams);
            d->layoutParams->destruct();
        }
        d->layoutParams = params;
        if (d->layoutParams) {
            connect(d->layoutParams, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateLayoutParams);
            if (isValid())
                d->layoutParams->construct();
        }
    }
}

QNativeAndroidDrawable *QNativeAndroidView::background() const
{
    Q_D(const QNativeAndroidView);
    return d->background;
}

void QNativeAndroidView::setBackground(QNativeAndroidDrawable *background, int resource)
{
    Q_D(QNativeAndroidView);
    if (d->background != background) {
        if (d->background) {
            disconnect(d->background, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateBackground);
            d->background->destruct();
        }
        d->background = background;
        d->backgroundResource = resource;
        if (d->background) {
            connect(d->background, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateBackground);
            if (!resource)
                d->background->construct();
        }
        emit backgroundChanged();
    }
}

QNativeAndroidAnimation *QNativeAndroidView::animation() const
{
    Q_D(const QNativeAndroidView);
    return d->animation;
}

void QNativeAndroidView::setAnimation(QNativeAndroidAnimation *animation)
{
    Q_D(QNativeAndroidView);
    if (d->animation != animation) {
        if (d->animation) {
            disconnect(d->animation, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateAnimation);
            d->animation->destruct();
        }
        d->animation = animation;
        if (d->animation) {
            connect(d->animation, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidView::updateAnimation);
            if (isValid())
                d->animation->construct();
        }
        emit animationChanged();
    }
}

int QNativeAndroidView::backgroundColor() const
{
    Q_D(const QNativeAndroidView);
    QNativeAndroidColorDrawable *drawable = qobject_cast<QNativeAndroidColorDrawable *>(d->background);
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
    Q_D(const QNativeAndroidView);
    return d->backgroundResource;
}

void QNativeAndroidView::setBackgroundResource(int resource)
{
    Q_D(QNativeAndroidView);
    if (d->backgroundResource != resource) {
        setBackground(new QNativeAndroidDrawable(this), resource);
        emit backgroundResourceChanged();
    }
}

bool QNativeAndroidView::isVisible() const
{
    Q_D(const QNativeAndroidView);
    return d->visible;
}

void QNativeAndroidView::setVisible(bool visible)
{
    Q_D(QNativeAndroidView);
    if (d->visible != visible) {
        d->visible = visible;
        // TODO: VISIBLE(0), INVISIBLE(4), GONE(8)
        QtNativeAndroid::callIntMethod(instance(), "setVisibility", visible ? 0 : 4);
        emit visibleChanged();
    }
}

bool QNativeAndroidView::hasFocus() const
{
    Q_D(const QNativeAndroidView);
    if (d->focus.isNull())
        return false;
    return d->focus;
}

bool QNativeAndroidView::updateFocus(bool arg)
{
    Q_D(QNativeAndroidView);
    if (arg != hasFocus()) {
        d->focus = arg;
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
    Q_D(const QNativeAndroidView);
    if (d->top.isNull())
        return 0;
    return d->top;
}

void QNativeAndroidView::setTop(int top)
{
    Q_D(QNativeAndroidView);
    if (d->top.isNull() || d->top != top) {
        d->top = top;
        QtNativeAndroid::callIntMethod(instance(), "setTop", top);
        emit topChanged();
        emit yChanged();
    }
}

int QNativeAndroidView::left() const
{
    Q_D(const QNativeAndroidView);
    if (d->left.isNull())
        return 0;
    return d->left;
}

void QNativeAndroidView::setLeft(int left)
{
    Q_D(QNativeAndroidView);
    if (d->left.isNull() || d->left != left) {
        d->left = left;
        QtNativeAndroid::callIntMethod(instance(), "setLeft", left);
        emit leftChanged();
        emit xChanged();
    }
}

int QNativeAndroidView::right() const
{
    Q_D(const QNativeAndroidView);
    if (d->right.isNull())
        return 0;
    return d->right;
}

void QNativeAndroidView::setRight(int right)
{
    Q_D(QNativeAndroidView);
    if (d->right.isNull() || d->right != right) {
        d->right = right;
        QtNativeAndroid::callIntMethod(instance(), "setRight", right);
        emit rightChanged();
    }
}

int QNativeAndroidView::bottom() const
{
    Q_D(const QNativeAndroidView);
    if (d->bottom.isNull())
        return 0;
    return d->bottom;
}

void QNativeAndroidView::setBottom(int bottom)
{
    Q_D(QNativeAndroidView);
    if (d->bottom.isNull() || d->bottom != bottom) {
        d->bottom = bottom;
        QtNativeAndroid::callIntMethod(instance(), "setBottom", bottom);
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
    Q_D(QNativeAndroidView);
    if (t != top()) {
        d->top = t;
        emit topChanged();
        emit yChanged();
    }
    if (l != left()) {
        d->left = l;
        emit leftChanged();
        emit xChanged();
    }
    if (r != right()) {
        d->right = r;
        emit rightChanged();
        emit widthChanged();
    }
    if (b != bottom()) {
        d->bottom = b;
        emit bottomChanged();
        emit heightChanged();
    }
}

int QNativeAndroidView::padding() const
{
    Q_D(const QNativeAndroidView);
    if (!d->padding.isNull())
        return d->padding;
    return 0;
}

void QNativeAndroidView::setPadding(int padding)
{
    Q_D(QNativeAndroidView);
    if (d->padding.isNull() || d->padding != padding) {
        d->padding = padding;
        emit paddingChanged();
    }
}

int QNativeAndroidView::paddingTop() const
{
    Q_D(const QNativeAndroidView);
    if (d->paddingTop.isNull())
        return padding();
    return d->paddingTop;
}

void QNativeAndroidView::setPaddingTop(int padding)
{
    Q_D(QNativeAndroidView);
    if (d->paddingTop.isNull() || d->paddingTop != padding) {
        d->paddingTop = padding;
        emit paddingTopChanged();
    }
}

int QNativeAndroidView::paddingLeft() const
{
    Q_D(const QNativeAndroidView);
    if (d->paddingLeft.isNull())
        return padding();
    return d->paddingLeft;
}

void QNativeAndroidView::setPaddingLeft(int padding)
{
    Q_D(QNativeAndroidView);
    if (d->paddingLeft.isNull() || d->paddingLeft != padding) {
        d->paddingLeft = padding;
        emit paddingLeftChanged();
    }
}

int QNativeAndroidView::paddingRight() const
{
    Q_D(const QNativeAndroidView);
    if (d->paddingRight.isNull())
        return padding();
    return d->paddingRight;
}

void QNativeAndroidView::setPaddingRight(int padding)
{
    Q_D(QNativeAndroidView);
    if (d->paddingRight.isNull() || d->paddingRight != padding) {
        d->paddingRight = padding;
        emit paddingRightChanged();
    }
}

int QNativeAndroidView::paddingBottom() const
{
    Q_D(const QNativeAndroidView);
    if (d->paddingBottom.isNull())
        return padding();
    return d->paddingBottom;
}

void QNativeAndroidView::setPaddingBottom(int padding)
{
    Q_D(QNativeAndroidView);
    if (d->paddingBottom.isNull() || d->paddingBottom != padding) {
        d->paddingBottom = padding;
        emit paddingBottomChanged();
    }
}

qreal QNativeAndroidView::alpha() const
{
    Q_D(const QNativeAndroidView);
    if (!d->alpha.isNull())
        return d->alpha;
    return 0;
}

void QNativeAndroidView::setAlpha(qreal alpha)
{
    Q_D(QNativeAndroidView);
    if (d->alpha.isNull() || d->alpha != alpha) {
        d->alpha = alpha;
        QtNativeAndroid::callRealMethod(instance(), "setAlpha", alpha);
        emit alphaChanged();
    }
}

qreal QNativeAndroidView::scaleX() const
{
    Q_D(const QNativeAndroidView);
    if (!d->scaleX.isNull())
        return d->scaleX;
    return 0;
}

void QNativeAndroidView::setScaleX(qreal scaleX)
{
    Q_D(QNativeAndroidView);
    if (d->scaleX.isNull() || d->scaleX != scaleX) {
        d->scaleX = scaleX;
        QtNativeAndroid::callRealMethod(instance(), "setScaleX", scaleX);
        emit scaleXChanged();
    }
}

qreal QNativeAndroidView::scaleY() const
{
    Q_D(const QNativeAndroidView);
    if (!d->scaleY.isNull())
        return d->scaleY;
    return 0;
}

void QNativeAndroidView::setScaleY(qreal scaleY)
{
    Q_D(QNativeAndroidView);
    if (d->scaleY.isNull() || d->scaleY != scaleY) {
        d->scaleY = scaleY;
        QtNativeAndroid::callRealMethod(instance(), "setScaleY", scaleY);
        emit scaleYChanged();
    }
}

qreal QNativeAndroidView::pivotX() const
{
    Q_D(const QNativeAndroidView);
    if (!d->pivotX.isNull())
        return d->pivotX;
    return 0;
}

void QNativeAndroidView::setPivotX(qreal pivotX)
{
    Q_D(QNativeAndroidView);
    if (d->pivotX.isNull() || d->pivotX != pivotX) {
        d->pivotX = pivotX;
        QtNativeAndroid::callRealMethod(instance(), "setPivotX", pivotX);
        emit pivotXChanged();
    }
}

qreal QNativeAndroidView::pivotY() const
{
    Q_D(const QNativeAndroidView);
    if (!d->pivotY.isNull())
        return d->pivotY;
    return 0;
}

void QNativeAndroidView::setPivotY(qreal pivotY)
{
    Q_D(QNativeAndroidView);
    if (d->pivotY.isNull() || d->pivotY != pivotY) {
        d->pivotY = pivotY;
        QtNativeAndroid::callRealMethod(instance(), "setPivotY", pivotY);
        emit pivotYChanged();
    }
}

qreal QNativeAndroidView::rotation() const
{
    Q_D(const QNativeAndroidView);
    if (!d->rotation.isNull())
        return d->rotation;
    return 0;
}

void QNativeAndroidView::setRotation(qreal rotation)
{
    Q_D(QNativeAndroidView);
    if (d->rotation.isNull() || d->rotation != rotation) {
        d->rotation = rotation;
        QtNativeAndroid::callRealMethod(instance(), "setRotation", rotation);
        emit rotationChanged();
    }
}

qreal QNativeAndroidView::rotationX() const
{
    Q_D(const QNativeAndroidView);
    if (!d->rotationX.isNull())
        return d->rotationX;
    return 0;
}

void QNativeAndroidView::setRotationX(qreal rotationX)
{
    Q_D(QNativeAndroidView);
    if (d->rotationX.isNull() || d->rotationX != rotationX) {
        d->rotationX = rotationX;
        QtNativeAndroid::callRealMethod(instance(), "setRotationX", rotationX);
        emit rotationXChanged();
    }
}

qreal QNativeAndroidView::rotationY() const
{
    Q_D(const QNativeAndroidView);
    if (!d->rotationY.isNull())
        return d->rotationY;
    return 0;
}

void QNativeAndroidView::setRotationY(qreal rotationY)
{
    Q_D(QNativeAndroidView);
    if (d->rotationY.isNull() || d->rotationY != rotationY) {
        d->rotationY = rotationY;
        QtNativeAndroid::callRealMethod(instance(), "setRotationY", rotationY);
        emit rotationYChanged();
    }
}

qreal QNativeAndroidView::translationX() const
{
    Q_D(const QNativeAndroidView);
    if (!d->translationX.isNull())
        return d->translationX;
    return 0;
}

void QNativeAndroidView::setTranslationX(qreal translationX)
{
    Q_D(QNativeAndroidView);
    if (d->translationX.isNull() || d->translationX != translationX) {
        d->translationX = translationX;
        QtNativeAndroid::callRealMethod(instance(), "setTranslationX", translationX);
        emit translationXChanged();
        emit xChanged();
    }
}

qreal QNativeAndroidView::translationY() const
{
    Q_D(const QNativeAndroidView);
    if (!d->translationY.isNull())
        return d->translationY;
    return 0;
}

void QNativeAndroidView::setTranslationY(qreal translationY)
{
    Q_D(QNativeAndroidView);
    if (d->translationY.isNull() || d->translationY != translationY) {
        d->translationY = translationY;
        QtNativeAndroid::callRealMethod(instance(), "setTranslationY", translationY);
        emit translationYChanged();
        emit yChanged();
    }
}

qreal QNativeAndroidView::translationZ() const
{
    Q_D(const QNativeAndroidView);
    if (!d->translationZ.isNull())
        return d->translationZ;
    return 0;
}

void QNativeAndroidView::setTranslationZ(qreal translationZ)
{
    Q_D(QNativeAndroidView);
    if (d->translationZ.isNull() || d->translationZ != translationZ) {
        d->translationZ = translationZ;
        QtNativeAndroid::callRealMethod(instance(), "setTranslationZ", translationZ);
        emit translationZChanged();
        emit zChanged();
    }
}

qreal QNativeAndroidView::elevation() const
{
    Q_D(const QNativeAndroidView);
    if (!d->elevation.isNull())
        return d->elevation;
    return 0;
}

void QNativeAndroidView::setElevation(qreal elevation)
{
    Q_D(QNativeAndroidView);
    if (d->elevation.isNull() || d->elevation != elevation) {
        d->elevation = elevation;
        QtNativeAndroid::callRealMethod(instance(), "setElevation", elevation);
        emit elevationChanged();
        emit zChanged();
    }
}

void QNativeAndroidView::viewChange(ViewChange change, const ViewChangeData &data)
{
    Q_UNUSED(data);
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
    Q_D(QNativeAndroidView);
    if (!d->children.contains(child)) {
        d->children.append(child);
        viewChange(ViewChildAddedChange, child);
        emit childrenChanged();
    }
}

void QNativeAndroidView::removeChild(QNativeAndroidView *child)
{
    Q_D(QNativeAndroidView);
    if (d->children.removeOne(child)) {
        viewChange(ViewChildRemovedChange, child);
        emit childrenChanged();
    }
}

void QNativeAndroidView::children_append(QQmlListProperty<QNativeAndroidView> *list, QNativeAndroidView *child)
{
    if (QNativeAndroidView *view = qobject_cast<QNativeAndroidView *>(list->object))
        view->addChild(child);
}

int QNativeAndroidView::children_count(QQmlListProperty<QNativeAndroidView> *list)
{
    if (QNativeAndroidViewPrivate *d = static_cast<QNativeAndroidViewPrivate *>(list->data))
        return d->children.count();
    return 0;
}

QNativeAndroidView *QNativeAndroidView::children_at(QQmlListProperty<QNativeAndroidView> *list, int index)
{
    if (QNativeAndroidViewPrivate *d = static_cast<QNativeAndroidViewPrivate *>(list->data))
        return d->children.at(index);
    return nullptr;
}

void QNativeAndroidView::children_clear(QQmlListProperty<QNativeAndroidView> *list)
{
    if (QNativeAndroidViewPrivate *d = static_cast<QNativeAndroidViewPrivate *>(list->data)) {
        while (!d->children.isEmpty())
            d->children.first()->setParentView(0);
    }
}

QAndroidJniObject QNativeAndroidView::onCreate()
{
    Q_ASSERT(!QtNativeAndroid::isMainQtThread());

    return QAndroidJniObject("android/view/View",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidView::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidView);
    Q_ASSERT(!QtNativeAndroid::isMainQtThread());

    QNativeAndroidContextual::onInflate(instance);

    d->listener = QAndroidJniObject("org/qtproject/qt5/android/bindings/view/QtNativeViewListener",
                                    "(Landroid/view/View;J)V",
                                    instance.object(),
                                    reinterpret_cast<jlong>(this));

    instance.callMethod<void>("setId", "(I)V", d->id);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(d->listener.object());
        nativeMethodsRegistered = true;
    }

    // TODO: VISIBLE(0), INVISIBLE(4), GONE(8)
    instance.callMethod<void>("setVisibility", "(I)V", d->visible ? 0 : 4);
    if (!d->padding.isNull() || !d->paddingTop.isNull() || !d->paddingLeft.isNull() || !d->paddingRight.isNull() || !d->paddingBottom.isNull())
        instance.callMethod<void>("setPadding", "(IIII)V", paddingLeft(), paddingTop(), paddingRight(), paddingBottom());
    if (!d->top.isNull())
        instance.callMethod<void>("setTop", "(I)V", d->top);
    if (!d->left.isNull())
        instance.callMethod<void>("setLeft", "(I)V", d->left);
    if (!d->right.isNull())
        instance.callMethod<void>("setRight", "(I)V", d->right);
    if (!d->bottom.isNull())
        instance.callMethod<void>("setBottom", "(I)V", d->bottom);
    if (!d->alpha.isNull())
        instance.callMethod<void>("setAlpha", "(F)V", d->alpha);
    if (!d->scaleX.isNull())
        instance.callMethod<void>("setScaleX", "(F)V", d->scaleX);
    if (!d->scaleY.isNull())
        instance.callMethod<void>("setScaleY", "(F)V", d->scaleY);
    if (!d->pivotX.isNull())
        instance.callMethod<void>("setPivotX", "(F)V", d->pivotX);
    if (!d->pivotY.isNull())
        instance.callMethod<void>("setPivotY", "(F)V", d->pivotY);
    if (!d->rotation.isNull())
        instance.callMethod<void>("setRotation", "(F)V", d->rotation);
    if (!d->rotationX.isNull())
        instance.callMethod<void>("setRotationX", "(F)V", d->rotationX);
    if (!d->rotationY.isNull())
        instance.callMethod<void>("setRotationY", "(F)V", d->rotationY);
    if (!d->translationX.isNull())
        instance.callMethod<void>("setTranslationX", "(F)V", d->translationX);
    if (!d->translationY.isNull())
        instance.callMethod<void>("setTranslationY", "(F)V", d->translationY);
    if (!d->translationZ.isNull())
        instance.callMethod<void>("setTranslationZ", "(F)V", d->translationZ);
    if (!d->elevation.isNull())
        instance.callMethod<void>("setElevation", "(F)V", d->elevation);

    if (d->backgroundResource != 0) {
        QAndroidJniObject background = ctx().callObjectMethod("getDrawable", "(I)Landroid/graphics/drawable/Drawable;", d->backgroundResource);
        d->background->inflate(background);
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
    Q_D(QNativeAndroidView);
    if (!d->polishing) {
        d->polishing = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::PolishRequest));
    }
}

void QNativeAndroidView::polish()
{
}

bool QNativeAndroidView::event(QEvent *event)
{
    Q_D(QNativeAndroidView);
    if (event->type() == QEvent::PolishRequest) {
        QNativeAndroidView *view = qobject_cast<QNativeAndroidView *>(parent());
        if (view)
            setParentView(view);
        polish();
        d->polishing = false;
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
    Q_D(QNativeAndroidView);
    if (!isValid() || !d->background)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject background = d->background->instance();
    QtNativeAndroid::callFunction([=]() {
        view.callMethod<void>("setBackground", "(Landroid/graphics/drawable/Drawable;)V", background.object());
    });
}

void QNativeAndroidView::updateAnimation()
{
    Q_D(QNativeAndroidView);
    if (!isValid() || !d->animation || !d->animation->isValid())
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject animation = d->animation->instance();
    QtNativeAndroid::callFunction([=]() {
        view.callMethod<void>("startAnimation", "(Landroid/view/animation/Animation;)V", animation.object());
    });
}

void QNativeAndroidView::updateLayoutParams()
{
    Q_D(QNativeAndroidView);
    if (!isValid() || !d->layoutParams)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject params = d->layoutParams->instance();
    QtNativeAndroid::callFunction([=]() {
        view.callMethod<void>("setLayoutParams",
                              "(Landroid/view/ViewGroup$LayoutParams;)V",
                              params.object());
    });
}

QT_END_NAMESPACE
