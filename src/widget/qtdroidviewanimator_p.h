#ifndef QTANDROIDVIEWANIMATOR_P_H
#define QTANDROIDVIEWANIMATOR_P_H

#include "qtdroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidViewAnimator : public QtAndroidFrameLayout
{
    Q_OBJECT
    Q_PROPERTY(int displayedChild READ displayedChild WRITE setDisplayedChild NOTIFY displayedChildChanged)
    Q_PROPERTY(int inAnimation READ inAnimation WRITE setInAnimation NOTIFY inAnimationChanged)
    Q_PROPERTY(int outAnimation READ outAnimation WRITE setOutAnimation NOTIFY outAnimationChanged)

public:
    explicit QtAndroidViewAnimator(QtAndroidView *parent = 0);

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
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<int> m_displayedChild;
    QtAndroidOptional<int> m_inAnimation;
    QtAndroidOptional<int> m_outAnimation;
};

QT_END_NAMESPACE

#endif // QTANDROIDVIEWANIMATOR_P_H
