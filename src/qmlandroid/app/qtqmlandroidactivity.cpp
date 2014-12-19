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

QQmlAndroidActivity::QQmlAndroidActivity(QObject *parent) :
    QQmlAndroidContextWrapper(parent), m_window(new QQmlAndroidWindow(this)),
    m_contentView(0), m_optionsMenu(0), m_actionBar(0)
{
    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QQmlAndroidWindow *QQmlAndroidActivity::window() const
{
    return m_window;
}

QQmlAndroidActionBar *QQmlAndroidActivity::actionBar() const
{
    return m_actionBar;
}

void QQmlAndroidActivity::setActionBar(QQmlAndroidActionBar *bar)
{
    if (m_actionBar != bar) {
        if (m_actionBar)
            m_actionBar->destruct();
        m_actionBar = bar;
        if (m_actionBar)
            setupActionBar();
    }
}

QQmlAndroidMenu *QQmlAndroidActivity::optionsMenu() const
{
    return m_optionsMenu;
}

void QQmlAndroidActivity::setOptionsMenu(QQmlAndroidMenu *menu)
{
    if (m_optionsMenu != menu) {
        if (m_optionsMenu) {
            disconnect(m_optionsMenu, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateOptionsMenu);
            m_optionsMenu->destruct();
        }
        m_optionsMenu = menu;
        if (m_optionsMenu) {
            connect(m_optionsMenu, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateOptionsMenu);
            if (isComponentComplete())
                m_optionsMenu->construct();
        }
    }
}

QQmlAndroidView *QQmlAndroidActivity::contentView() const
{
    return m_contentView;
}

void QQmlAndroidActivity::setContentView(QQmlAndroidView *view)
{
    if (m_contentView != view) {
        if (m_contentView) {
            disconnect(m_contentView, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateContentView);
            m_contentView->destruct();
        }
        m_contentView = view;
        if (m_contentView) {
            connect(m_contentView, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateContentView);
            if (isComponentComplete())
                m_contentView->construct();
        }
    }
}

void QQmlAndroidActivity::classBegin()
{
    QQmlAndroidContextWrapper::classBegin();
}

void QQmlAndroidActivity::componentComplete()
{
    QQmlAndroidContextWrapper::componentComplete();

    foreach (QObject *child, children()) {
        QQmlAndroidObject *object = qobject_cast<QQmlAndroidObject *>(child);
        if (object)
            object->construct();
    }

    if (m_actionBar)
        setupActionBar();

    if (m_window)
        setupWindow();
}

void QQmlAndroidActivity::setupWindow()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject wnd = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
        m_window->inflate(wnd);
    });
}

void QQmlAndroidActivity::setupActionBar()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject bar = activity.callObjectMethod("getActionBar", "()Landroid/app/ActionBar;");
        m_actionBar->inflate(bar);
    });
}

void QQmlAndroidActivity::updateOptionsMenu()
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

void QQmlAndroidActivity::invalidateOptionsMenu()
{
    QtQmlAndroid::callVoidMethod(instance(), "invalidateOptionsMenu");
}

void QQmlAndroidActivity::updateContentView()
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
