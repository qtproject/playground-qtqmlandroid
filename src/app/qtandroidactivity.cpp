#include "qtandroidactivity_p.h"
#include "qtandroidactionbar_p.h"
#include "qtandroidmenuitem_p.h"
#include "qtandroidmenu_p.h"
#include "qtandroidview_p.h"
#include "qtandroidwindow_p.h"
#include "qtandroidfunctions_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QtAndroidActivity::QtAndroidActivity(QObject *parent) :
    QtAndroidContextWrapper(parent), m_window(new QtAndroidWindow(this)),
    m_contentView(0), m_optionsMenu(0), m_actionBar(0)
{
    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QtAndroidWindow *QtAndroidActivity::window() const
{
    return m_window;
}

QtAndroidActionBar *QtAndroidActivity::actionBar() const
{
    return m_actionBar;
}

void QtAndroidActivity::setActionBar(QtAndroidActionBar *bar)
{
    if (m_actionBar != bar) {
        if (m_actionBar)
            m_actionBar->destruct();
        m_actionBar = bar;
        if (m_actionBar)
            setupActionBar();
    }
}

QtAndroidMenu *QtAndroidActivity::optionsMenu() const
{
    return m_optionsMenu;
}

void QtAndroidActivity::setOptionsMenu(QtAndroidMenu *menu)
{
    if (m_optionsMenu != menu) {
        if (m_optionsMenu) {
            m_optionsMenu->setContext(0);
            disconnect(m_optionsMenu, SIGNAL(instanceChanged()), this, SLOT(updateOptionsMenu()));
            m_optionsMenu->destruct();
        }
        m_optionsMenu = menu;
        if (m_optionsMenu) {
            m_optionsMenu->setContext(this);
            connect(m_optionsMenu, SIGNAL(instanceChanged()), this, SLOT(updateOptionsMenu()));
            if (isComponentComplete())
                m_optionsMenu->construct();
        }
    }
}

QtAndroidView *QtAndroidActivity::contentView() const
{
    return m_contentView;
}

void QtAndroidActivity::setContentView(QtAndroidView *view)
{
    if (m_contentView != view) {
        if (m_contentView) {
            m_contentView->setContext(0);
            disconnect(m_contentView, SIGNAL(instanceChanged()), this, SLOT(updateContentView()));
            m_contentView->destruct();
        }
        m_contentView = view;
        if (m_contentView) {
            m_contentView->setContext(this);
            connect(m_contentView, SIGNAL(instanceChanged()), this, SLOT(updateContentView()));
            if (isComponentComplete())
                m_contentView->construct();
        }
    }
}

void QtAndroidActivity::classBegin()
{
    QtAndroidContextWrapper::classBegin();
}

void QtAndroidActivity::componentComplete()
{
    QtAndroidContextWrapper::componentComplete();

    if (m_contentView)
        m_contentView->construct();

    if (m_optionsMenu)
        m_optionsMenu->construct();

    if (m_actionBar)
        setupActionBar();

    if (m_window)
        setupWindow();
}

void QtAndroidActivity::setupWindow()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtAndroid::callFunction([=]() {
        QAndroidJniObject wnd = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
        m_window->inflate(wnd);
    });
}

void QtAndroidActivity::setupActionBar()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtAndroid::callFunction([=]() {
        QAndroidJniObject bar = activity.callObjectMethod("getActionBar", "()Landroid/app/ActionBar;");
        m_actionBar->inflate(bar);
    });
}

void QtAndroidActivity::updateOptionsMenu()
{
    if (!isValid())
        return;

    QAndroidJniObject menu;
    if (m_optionsMenu)
        menu = m_optionsMenu->instance();

    QAndroidJniObject activity = instance();
    QtAndroid::callFunction([=]() {
        activity.callMethod<void>("setOptionsMenu", "(Lqt/android/view/QtMenu;)V", menu.object());
    });
}

void QtAndroidActivity::invalidateOptionsMenu()
{
    QtAndroid::callVoidMethod(instance(), "invalidateOptionsMenu");
}

void QtAndroidActivity::updateContentView()
{
    if (!isValid())
        return;

    QAndroidJniObject content;
    if (m_contentView)
        content = m_contentView->instance();

    QAndroidJniObject activity = instance();
    QtAndroid::callFunction([=]() {
        activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", content.object());
    });
}
