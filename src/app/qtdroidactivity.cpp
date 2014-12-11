#include "qtdroidactivity_p.h"
#include "qtdroidactionbar_p.h"
#include "qtdroidmenuitem_p.h"
#include "qtdroidmenu_p.h"
#include "qtdroidview_p.h"
#include "qtdroidfunctions_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QtAndroidActivity::QtAndroidActivity(QObject *parent) :
    QtAndroidContext(parent), m_view(0), m_optionsMenu(0), m_actionBar(0)
{
    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QtAndroidActionBar *QtAndroidActivity::actionBar() const
{
    return m_actionBar;
}

void QtAndroidActivity::setActionBar(QtAndroidActionBar *bar)
{
    // TODO: dynamic changes
    m_actionBar = bar;
}

QtAndroidMenu *QtAndroidActivity::optionsMenu() const
{
    return m_optionsMenu;
}

void QtAndroidActivity::setOptionsMenu(QtAndroidMenu *menu)
{
    // TODO: dynamic changes
    m_optionsMenu = menu;
}

QtAndroidView *QtAndroidActivity::contentView() const
{
    return m_view;
}

void QtAndroidActivity::setContentView(QtAndroidView *view)
{
    if (m_view != view) {
        if (m_view)
            m_view->setContext(0);
        m_view = view;
        if (view)
            view->setContext(this);
    }
}

void QtAndroidActivity::classBegin()
{
    QtAndroidContext::classBegin();
}

void QtAndroidActivity::componentComplete()
{
    QtAndroidContext::componentComplete();

    QAndroidJniObject activity = instance();
    QtAndroid::callFunction([=]() {
        if (m_optionsMenu) {
            foreach (QtAndroidMenuItem *item, m_optionsMenu->items()) {
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
            QAndroidJniObject content = m_view->construct();
            m_view->setInstance(content);
            m_view->inflate();
            if (content.isValid())
                activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", content.object());
        }
    });
}
