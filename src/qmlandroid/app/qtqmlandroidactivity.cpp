#include "qtqmlandroidactivity_p.h"
#include "qtqmlandroidactionbar_p.h"
#include "qtqmlandroidmenuitem_p.h"
#include "qtqmlandroidmenu_p.h"
#include "qtqmlandroidview_p.h"
#include "qtqmlandroidwindow_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

QtQmlAndroidActivity::QtQmlAndroidActivity(QObject *parent) :
    QtQmlAndroidContextWrapper(parent), m_window(new QtQmlAndroidWindow(this)),
    m_contentView(0), m_optionsMenu(0), m_actionBar(0)
{
    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QtQmlAndroidWindow *QtQmlAndroidActivity::window() const
{
    return m_window;
}

QtQmlAndroidActionBar *QtQmlAndroidActivity::actionBar() const
{
    return m_actionBar;
}

void QtQmlAndroidActivity::setActionBar(QtQmlAndroidActionBar *bar)
{
    if (m_actionBar != bar) {
        if (m_actionBar)
            m_actionBar->destruct();
        m_actionBar = bar;
        if (m_actionBar)
            setupActionBar();
    }
}

QtQmlAndroidMenu *QtQmlAndroidActivity::optionsMenu() const
{
    return m_optionsMenu;
}

void QtQmlAndroidActivity::setOptionsMenu(QtQmlAndroidMenu *menu)
{
    if (m_optionsMenu != menu) {
        if (m_optionsMenu) {
            disconnect(m_optionsMenu, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidActivity::updateOptionsMenu);
            m_optionsMenu->destruct();
        }
        m_optionsMenu = menu;
        if (m_optionsMenu) {
            connect(m_optionsMenu, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidActivity::updateOptionsMenu);
            if (isComponentComplete())
                m_optionsMenu->construct();
        }
    }
}

QtQmlAndroidView *QtQmlAndroidActivity::contentView() const
{
    return m_contentView;
}

void QtQmlAndroidActivity::setContentView(QtQmlAndroidView *view)
{
    if (m_contentView != view) {
        if (m_contentView) {
            disconnect(m_contentView, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidActivity::updateContentView);
            m_contentView->destruct();
        }
        m_contentView = view;
        if (m_contentView) {
            connect(m_contentView, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidActivity::updateContentView);
            if (isComponentComplete())
                m_contentView->construct();
        }
    }
}

void QtQmlAndroidActivity::classBegin()
{
    QtQmlAndroidContextWrapper::classBegin();
}

void QtQmlAndroidActivity::componentComplete()
{
    QtQmlAndroidContextWrapper::componentComplete();

    foreach (QObject *child, children()) {
        QtQmlAndroidObject *object = qobject_cast<QtQmlAndroidObject *>(child);
        if (object)
            object->construct();
    }

    if (m_actionBar)
        setupActionBar();

    if (m_window)
        setupWindow();
}

void QtQmlAndroidActivity::setupWindow()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject wnd = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
        m_window->inflate(wnd);
    });
}

void QtQmlAndroidActivity::setupActionBar()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject bar = activity.callObjectMethod("getActionBar", "()Landroid/app/ActionBar;");
        m_actionBar->inflate(bar);
    });
}

void QtQmlAndroidActivity::updateOptionsMenu()
{
    if (!isValid())
        return;

    QAndroidJniObject menu;
    if (m_optionsMenu)
        menu = m_optionsMenu->instance();

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        activity.callMethod<void>("setOptionsMenu", "(Lqt/android/view/QtMenu;)V", menu.object());
    });
}

void QtQmlAndroidActivity::invalidateOptionsMenu()
{
    QtQmlAndroid::callVoidMethod(instance(), "invalidateOptionsMenu");
}

void QtQmlAndroidActivity::updateContentView()
{
    if (!isValid())
        return;

    QAndroidJniObject content;
    if (m_contentView)
        content = m_contentView->instance();

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", content.object());
    });
}

QT_END_NAMESPACE
