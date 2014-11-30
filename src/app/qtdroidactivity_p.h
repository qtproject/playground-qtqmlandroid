#ifndef QTDROIDACTIVITY_P_H
#define QTDROIDACTIVITY_P_H

#include "qtdroidcontext_p.h"

QT_BEGIN_NAMESPACE

class QtDroidView;
class QtDroidActionBar;

class QtDroidActivity : public QtDroidContext
{
    Q_OBJECT
    Q_PROPERTY(QtDroidActionBar *actionBar READ actionBar WRITE setActionBar)
    Q_PROPERTY(QtDroidView *contentView READ contentView WRITE setContentView)
    Q_CLASSINFO("DefaultProperty", "contentView")

public:
    explicit QtDroidActivity(QObject *parent = 0);

    QtDroidActionBar *actionBar() const;
    void setActionBar(QtDroidActionBar *bar);

    QtDroidView *contentView() const;
    void setContentView(QtDroidView *view);

protected:
    void classBegin() Q_DECL_OVERRIDE;
    void componentComplete() Q_DECL_OVERRIDE;

private:
    QtDroidView *m_view;
    QtDroidActionBar *m_actionBar;
};

QT_END_NAMESPACE

#endif // QTDROIDACTIVITY_P_H
