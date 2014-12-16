#ifndef QTANDROIDACTIVITY_P_H
#define QTANDROIDACTIVITY_P_H

#include "qtandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidView;
class QtAndroidMenu;
class QtAndroidWindow;
class QtAndroidActionBar;

class QtAndroidActivity : public QtAndroidContextWrapper
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidWindow *window READ window CONSTANT)
    Q_PROPERTY(QtAndroidActionBar *actionBar READ actionBar WRITE setActionBar)
    Q_PROPERTY(QtAndroidMenu *optionsMenu READ optionsMenu WRITE setOptionsMenu)
    Q_PROPERTY(QtAndroidView *contentView READ contentView WRITE setContentView)
    Q_CLASSINFO("DefaultProperty", "contentView")

public:
    explicit QtAndroidActivity(QObject *parent = 0);

    QtAndroidWindow *window() const;

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
    void setupWindow();
    void setupActionBar();
    void updateOptionsMenu();
    void updateContentView();

private:
    QtAndroidWindow *m_window;
    QtAndroidView *m_contentView;
    QtAndroidMenu *m_optionsMenu;
    QtAndroidActionBar *m_actionBar;
};

QT_END_NAMESPACE

#endif // QTANDROIDACTIVITY_P_H
