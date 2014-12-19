#include "qtqmlandroidviewanimator_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidViewAnimator::QtQmlAndroidViewAnimator(QtQmlAndroidView *parent) :
    QtQmlAndroidFrameLayout(parent)
{
}

int QtQmlAndroidViewAnimator::displayedChild() const
{
    if (m_displayedChild.isNull())
        return 0;
    return m_displayedChild.value();
}

void QtQmlAndroidViewAnimator::setDisplayedChild(int child)
{
    if (child != displayedChild()) {
        m_displayedChild = child;
        QtQmlAndroid::callIntMethod(instance(), "setDisplayedChild", child);
        emit displayedChildChanged();
    }
}

int QtQmlAndroidViewAnimator::inAnimation() const
{
    if (m_inAnimation.isNull())
        return -1;
    return m_inAnimation.value();
}

void QtQmlAndroidViewAnimator::setInAnimation(int animation)
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

int QtQmlAndroidViewAnimator::outAnimation() const
{
    if (m_outAnimation.isNull())
        return -1;
    return m_outAnimation.value();
}

void QtQmlAndroidViewAnimator::setOutAnimation(int animation)
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

void QtQmlAndroidViewAnimator::showNext()
{
    QtQmlAndroid::callVoidMethod(instance(), "showNext");
}

void QtQmlAndroidViewAnimator::showPrevious()
{
    QtQmlAndroid::callVoidMethod(instance(), "showPrevious");
}

QAndroidJniObject QtQmlAndroidViewAnimator::onCreate()
{
    return QAndroidJniObject("android/widget/ViewAnimator",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidViewAnimator::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidFrameLayout::onInflate(instance);

    if (!m_displayedChild.isNull())
        instance.callMethod<void>("setDisplayedChild", "(I)V", m_displayedChild.value());
    if (!m_inAnimation.isNull())
        instance.callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_inAnimation.value());
    if (!m_outAnimation.isNull())
        instance.callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_outAnimation.value());
}

QT_END_NAMESPACE
