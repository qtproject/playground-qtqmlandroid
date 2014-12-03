#ifndef QTDROIDVIEWANIMATOR_P_H
#define QTDROIDVIEWANIMATOR_P_H

#include "qtdroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtDroidViewAnimator : public QtDroidFrameLayout
{
    Q_OBJECT
    Q_PROPERTY(int displayedChild READ displayedChild WRITE setDisplayedChild NOTIFY displayedChildChanged)

public:
    explicit QtDroidViewAnimator(QtDroidView *parent = 0);

    int displayedChild() const;
    void setDisplayedChild(int child);

public Q_SLOTS:
    void showNext();
    void showPrevious();

Q_SIGNALS:
    void displayedChildChanged();

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;

private:
    QtDroidOptional<int> m_displayedChild;
};

QT_END_NAMESPACE

#endif // QTDROIDVIEWANIMATOR_P_H
