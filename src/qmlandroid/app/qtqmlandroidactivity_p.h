#ifndef QTQMLANDROIDACTIVITY_P_H
#define QTQMLANDROIDACTIVITY_P_H

#include "qtqmlandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidView;
class QtQmlAndroidMenu;
class QtQmlAndroidWindow;
class QtQmlAndroidActionBar;

class QtQmlAndroidActivity : public QtQmlAndroidContextWrapper
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidWindow *window READ window CONSTANT)
    Q_PROPERTY(QtQmlAndroidActionBar *actionBar READ actionBar WRITE setActionBar)
    Q_PROPERTY(QtQmlAndroidMenu *optionsMenu READ optionsMenu WRITE setOptionsMenu)
    Q_PROPERTY(QtQmlAndroidView *contentView READ contentView WRITE setContentView)

public:
    explicit QtQmlAndroidActivity(QObject *parent = 0);

    QtQmlAndroidWindow *window() const;

    QtQmlAndroidActionBar *actionBar() const;
    void setActionBar(QtQmlAndroidActionBar *bar);

    QtQmlAndroidMenu *optionsMenu() const;
    void setOptionsMenu(QtQmlAndroidMenu *menu);

    QtQmlAndroidView *contentView() const;
    void setContentView(QtQmlAndroidView *view);

protected:
    void classBegin() Q_DECL_OVERRIDE;
    void componentComplete() Q_DECL_OVERRIDE;

private Q_SLOTS:
    void setupWindow();
    void setupActionBar();
    void updateOptionsMenu();
    void invalidateOptionsMenu();
    void updateContentView();

private:
    QtQmlAndroidWindow *m_window;
    QtQmlAndroidView *m_contentView;
    QtQmlAndroidMenu *m_optionsMenu;
    QtQmlAndroidActionBar *m_actionBar;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDACTIVITY_P_H
