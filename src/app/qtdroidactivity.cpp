#include "qtdroidactivity_p.h"
#include "qtdroidactionbar_p.h"
#include "qtdroidmenuitem_p.h"
#include "qtdroidmenu_p.h"
#include "qtdroidview_p.h"
#include "qtdroidfunctions_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QtDroidActivity::QtDroidActivity(QObject *parent) :
    QtDroidContext(parent), m_view(0), m_optionsMenu(0), m_actionBar(0)
{
    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QtDroidActionBar *QtDroidActivity::actionBar() const
{
    return m_actionBar;
}

void QtDroidActivity::setActionBar(QtDroidActionBar *bar)
{
    // TODO: dynamic changes
    m_actionBar = bar;
}

QtDroidMenu *QtDroidActivity::optionsMenu() const
{
    return m_optionsMenu;
}

void QtDroidActivity::setOptionsMenu(QtDroidMenu *menu)
{
    // TODO: dynamic changes
    m_optionsMenu = menu;
}

QtDroidView *QtDroidActivity::contentView() const
{
    return m_view;
}

void QtDroidActivity::setContentView(QtDroidView *view)
{
    if (m_view != view) {
        if (m_view)
            m_view->setContext(0);
        m_view = view;
        if (view)
            view->setContext(this);
    }
}

void QtDroidActivity::classBegin()
{
    QtDroidContext::classBegin();
}

void QtDroidActivity::componentComplete()
{
    QtDroidContext::componentComplete();

    QAndroidJniObject activity = instance();
    QtDroid::callFunction([=]() {
        if (m_optionsMenu) {
            foreach (QtDroidMenuItem *item, m_optionsMenu->items()) {
                activity.callMethod<void>("addOptionsMenuItem",
                                          "(Ljava/lang/String;)V",
                                          QAndroidJniObject::fromString(item->title()).object());
            }
        }
        if (m_actionBar) {
            QAndroidJniObject bar = activity.callObjectMethod("getActionBar", "()Landroid/app/ActionBar;");
            m_actionBar->setInstance(bar);
            m_actionBar->setActivity(this);
        }
        if (m_view) {
            QAndroidJniObject content = m_view->construct(activity.object());
            m_view->setInstance(content);
            m_view->inflate(activity.object());
            if (content.isValid())
                activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", content.object());
        }
    });
}
