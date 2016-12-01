#ifndef QQMLANDROIDVIEWANIMATOR_P_H
#define QQMLANDROIDVIEWANIMATOR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidViewAnimator : public QQmlAndroidFrameLayout
{
    Q_OBJECT
    Q_PROPERTY(int displayedChild READ displayedChild WRITE setDisplayedChild NOTIFY displayedChildChanged)
    Q_PROPERTY(int inAnimation READ inAnimation WRITE setInAnimation NOTIFY inAnimationChanged)
    Q_PROPERTY(int outAnimation READ outAnimation WRITE setOutAnimation NOTIFY outAnimationChanged)

public:
    explicit QQmlAndroidViewAnimator(QQmlAndroidView *parent = 0);

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
    QQmlAndroidOptional<int> m_displayedChild;
    QQmlAndroidOptional<int> m_inAnimation;
    QQmlAndroidOptional<int> m_outAnimation;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDVIEWANIMATOR_P_H
