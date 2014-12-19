#include "qqmlandroidviewanimator_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidViewAnimator::QQmlAndroidViewAnimator(QQmlAndroidView *parent) :
    QQmlAndroidFrameLayout(parent)
{
}

int QQmlAndroidViewAnimator::displayedChild() const
{
    if (m_displayedChild.isNull())
        return 0;
    return m_displayedChild.value();
}

void QQmlAndroidViewAnimator::setDisplayedChild(int child)
{
    if (child != displayedChild()) {
        m_displayedChild = child;
        QtQmlAndroid::callIntMethod(instance(), "setDisplayedChild", child);
        emit displayedChildChanged();
    }
}

int QQmlAndroidViewAnimator::inAnimation() const
{
    if (m_inAnimation.isNull())
        return -1;
    return m_inAnimation.value();
}

void QQmlAndroidViewAnimator::setInAnimation(int animation)
{
    if (animation != inAnimation()) {
        m_inAnimation = animation;
        if (instance().isValid()) {
            QtQmlAndroid::callFunction([=]() {
                instance().callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtQmlAndroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

int QQmlAndroidViewAnimator::outAnimation() const
{
    if (m_outAnimation.isNull())
        return -1;
    return m_outAnimation.value();
}

void QQmlAndroidViewAnimator::setOutAnimation(int animation)
{
    if (animation != outAnimation()) {
        m_outAnimation = animation;
        if (instance().isValid()) {
            QtQmlAndroid::callFunction([=]() {
                instance().callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtQmlAndroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

void QQmlAndroidViewAnimator::showNext()
{
    QtQmlAndroid::callVoidMethod(instance(), "showNext");
}

void QQmlAndroidViewAnimator::showPrevious()
{
    QtQmlAndroid::callVoidMethod(instance(), "showPrevious");
}

QAndroidJniObject QQmlAndroidViewAnimator::onCreate()
{
    return QAndroidJniObject("android/widget/ViewAnimator",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidViewAnimator::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidFrameLayout::onInflate(instance);

    if (!m_displayedChild.isNull())
        instance.callMethod<void>("setDisplayedChild", "(I)V", m_displayedChild.value());
    if (!m_inAnimation.isNull())
        instance.callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_inAnimation.value());
    if (!m_outAnimation.isNull())
        instance.callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_outAnimation.value());
}

QT_END_NAMESPACE
