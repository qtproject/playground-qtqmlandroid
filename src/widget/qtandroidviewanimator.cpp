#include "qtandroidviewanimator_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidViewAnimator::QtAndroidViewAnimator(QtAndroidView *parent) :
    QtAndroidFrameLayout(parent)
{
}

int QtAndroidViewAnimator::displayedChild() const
{
    if (m_displayedChild.isNull())
        return 0;
    return m_displayedChild.value();
}

void QtAndroidViewAnimator::setDisplayedChild(int child)
{
    if (child != displayedChild()) {
        m_displayedChild = child;
        QtAndroid::callIntMethod(instance(), "setDisplayedChild", child);
        emit displayedChildChanged();
    }
}

int QtAndroidViewAnimator::inAnimation() const
{
    if (m_inAnimation.isNull())
        return -1;
    return m_inAnimation.value();
}

void QtAndroidViewAnimator::setInAnimation(int animation)
{
    if (animation != inAnimation()) {
        m_inAnimation = animation;
        if (instance().isValid()) {
            QtAndroid::callFunction([=]() {
                instance().callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtAndroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

int QtAndroidViewAnimator::outAnimation() const
{
    if (m_outAnimation.isNull())
        return -1;
    return m_outAnimation.value();
}

void QtAndroidViewAnimator::setOutAnimation(int animation)
{
    if (animation != outAnimation()) {
        m_outAnimation = animation;
        if (instance().isValid()) {
            QtAndroid::callFunction([=]() {
                instance().callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtAndroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

void QtAndroidViewAnimator::showNext()
{
    QtAndroid::callVoidMethod(instance(), "showNext");
}

void QtAndroidViewAnimator::showPrevious()
{
    QtAndroid::callVoidMethod(instance(), "showPrevious");
}

QAndroidJniObject QtAndroidViewAnimator::onCreate()
{
    return QAndroidJniObject("android/widget/ViewAnimator",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidViewAnimator::onInflate(QAndroidJniObject &instance)
{
    QtAndroidFrameLayout::onInflate(instance);

    if (!m_displayedChild.isNull())
        instance.callMethod<void>("setDisplayedChild", "(I)V", m_displayedChild.value());
    if (!m_inAnimation.isNull())
        instance.callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_inAnimation.value());
    if (!m_outAnimation.isNull())
        instance.callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_outAnimation.value());
}
