#ifndef QQMLANDROIDACTIVITY_P_H
#define QQMLANDROIDACTIVITY_P_H

#include "qtqmlandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidView;
class QQmlAndroidMenu;
class QQmlAndroidWindow;
class QQmlAndroidActionBar;

class QQmlAndroidActivity : public QQmlAndroidContextWrapper
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidWindow *window READ window CONSTANT)
    Q_PROPERTY(QQmlAndroidActionBar *actionBar READ actionBar WRITE setActionBar)
    Q_PROPERTY(QQmlAndroidMenu *optionsMenu READ optionsMenu WRITE setOptionsMenu)
    Q_PROPERTY(QQmlAndroidView *contentView READ contentView WRITE setContentView)

public:
    explicit QQmlAndroidActivity(QObject *parent = 0);

    QQmlAndroidWindow *window() const;

    QQmlAndroidActionBar *actionBar() const;
    void setActionBar(QQmlAndroidActionBar *bar);

    QQmlAndroidMenu *optionsMenu() const;
    void setOptionsMenu(QQmlAndroidMenu *menu);

    QQmlAndroidView *contentView() const;
    void setContentView(QQmlAndroidView *view);

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
    QQmlAndroidWindow *m_window;
    QQmlAndroidView *m_contentView;
    QQmlAndroidMenu *m_optionsMenu;
    QQmlAndroidActionBar *m_actionBar;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACTIVITY_P_H
