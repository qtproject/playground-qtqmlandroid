#ifndef QTQMLANDROIDVIEWANIMATOR_P_H
#define QTQMLANDROIDVIEWANIMATOR_P_H

#include "qtqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidViewAnimator : public QtQmlAndroidFrameLayout
{
    Q_OBJECT
    Q_PROPERTY(int displayedChild READ displayedChild WRITE setDisplayedChild NOTIFY displayedChildChanged)
    Q_PROPERTY(int inAnimation READ inAnimation WRITE setInAnimation NOTIFY inAnimationChanged)
    Q_PROPERTY(int outAnimation READ outAnimation WRITE setOutAnimation NOTIFY outAnimationChanged)

public:
    explicit QtQmlAndroidViewAnimator(QtQmlAndroidView *parent = 0);

    int displayedChild() const;
    void setDisplayedChild(int child);

    int inAnimation() const;
    void setInAnimation(int animation);

    int outAnimation() const;
    void setOutAnimation(int animation);

public Q_SLOTS:
    void showNext();
    void showPrevious();

Q_SIGNALS:
    void displayedChildChanged();
    void inAnimationChanged();
    void outAnimationChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtQmlAndroidOptional<int> m_displayedChild;
    QtQmlAndroidOptional<int> m_inAnimation;
    QtQmlAndroidOptional<int> m_outAnimation;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDVIEWANIMATOR_P_H
