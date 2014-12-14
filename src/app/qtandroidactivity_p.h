#ifndef QTANDROIDACTIVITY_P_H
#define QTANDROIDACTIVITY_P_H

#include "qtandroidcontext_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidView;
class QtAndroidMenu;
class QtAndroidActionBar;

class QtAndroidActivity : public QtAndroidContext
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidActionBar *actionBar READ actionBar WRITE setActionBar)
    Q_PROPERTY(QtAndroidMenu *optionsMenu READ optionsMenu WRITE setOptionsMenu)
    Q_PROPERTY(QtAndroidView *contentView READ contentView WRITE setContentView)
    Q_CLASSINFO("DefaultProperty", "contentView")

public:
    explicit QtAndroidActivity(QObject *parent = 0);

    QtAndroidActionBar *actionBar() const;
    void setActionBar(QtAndroidActionBar *bar);

    QtAndroidMenu *optionsMenu() const;
    void setOptionsMenu(QtAndroidMenu *menu);

    QtAndroidView *contentView() const;
    void setContentView(QtAndroidView *view);

protected:
    void classBegin() Q_DECL_OVERRIDE;
    void componentComplete() Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateActionBar();
    void updateOptionsMenu();
    void updateContentView();

private:
    QtAndroidView *m_contentView;
    QtAndroidMenu *m_optionsMenu;
    QtAndroidActionBar *m_actionBar;
};

QT_END_NAMESPACE

#endif // QTANDROIDACTIVITY_P_H
