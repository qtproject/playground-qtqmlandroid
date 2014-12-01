#include "qtdroidviewanimator_p.h"

QtDroidViewAnimator::QtDroidViewAnimator(QObject *parent) : QtDroidFrameLayout(parent)
{
}

int QtDroidViewAnimator::displayedChild() const
{
    if (m_displayedChild.isNull())
        return 0;
    return m_displayedChild.value();
}

static void callSetDisplayedChild(const QAndroidJniObject& animator, int child)
{
    if (animator.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            animator.callMethod<void>("setDisplayedChild", "(I)V", child);
        });
    }
}

void QtDroidViewAnimator::setDisplayedChild(int child)
{
    if (child != displayedChild()) {
        m_displayedChild = child;
        callSetDisplayedChild(instance(), child);
        emit displayedChildChanged();
    }
}

void QtDroidViewAnimator::showNext()
{
    QtDroidObject::callUiMethod([=]() {
        instance().callMethod<void>("showNext");
    });
}

void QtDroidViewAnimator::showPrevious()
{
    QtDroidObject::callUiMethod([=]() {
        instance().callMethod<void>("showPrevious");
    });
}

QAndroidJniObject QtDroidViewAnimator::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ViewAnimator",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidViewAnimator::inflate(jobject context)
{
    QtDroidFrameLayout::inflate(context);

    if (!m_displayedChild.isNull())
        callSetDisplayedChild(instance(), m_displayedChild.value());
}
