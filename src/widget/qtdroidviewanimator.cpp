#include "qtdroidviewanimator_p.h"
#include "qtdroidfunctions_p.h"

QtDroidViewAnimator::QtDroidViewAnimator(QtDroidView *parent) : QtDroidFrameLayout(parent)
{
}

int QtDroidViewAnimator::displayedChild() const
{
    if (m_displayedChild.isNull())
        return 0;
    return m_displayedChild.value();
}

void QtDroidViewAnimator::setDisplayedChild(int child)
{
    if (child != displayedChild()) {
        m_displayedChild = child;
        QtDroid::callIntMethod(instance(), "setDisplayedChild", child);
        emit displayedChildChanged();
    }
}

int QtDroidViewAnimator::inAnimation() const
{
    if (m_inAnimation.isNull())
        return -1;
    return m_inAnimation.value();
}

void QtDroidViewAnimator::setInAnimation(int animation)
{
    if (animation != inAnimation()) {
        m_inAnimation = animation;
        if (instance().isValid()) {
            QtDroid::callFunction([=]() {
                instance().callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtDroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

int QtDroidViewAnimator::outAnimation() const
{
    if (m_outAnimation.isNull())
        return -1;
    return m_outAnimation.value();
}

void QtDroidViewAnimator::setOutAnimation(int animation)
{
    if (animation != outAnimation()) {
        m_outAnimation = animation;
        if (instance().isValid()) {
            QtDroid::callFunction([=]() {
                instance().callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtDroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

void QtDroidViewAnimator::showNext()
{
    QtDroid::callVoidMethod(instance(), "showNext");
}

void QtDroidViewAnimator::showPrevious()
{
    QtDroid::callVoidMethod(instance(), "showPrevious");
}

QAndroidJniObject QtDroidViewAnimator::construct()
{
    return QAndroidJniObject("android/widget/ViewAnimator",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidViewAnimator::inflate()
{
    QtDroidFrameLayout::inflate();

    if (!m_displayedChild.isNull())
        QtDroid::callIntMethod(instance(), "setDisplayedChild", m_displayedChild.value());
    if (!m_inAnimation.isNull())
        instance().callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_inAnimation.value());
    if (!m_outAnimation.isNull())
        instance().callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_outAnimation.value());
}
