#include "qtdroidpopupmenu_p.h"
#include "qtdroidmenuitem_p.h"
#include "qtdroidcontext_p.h"
#include "qtdroidview_p.h"
#include <QtCore/qdebug.h>

QtDroidPopupMenu::QtDroidPopupMenu(QObject *parent) : QtDroidObject(parent), m_anchor(0)
{
}

QtDroidView *QtDroidPopupMenu::anchor() const
{
    return m_anchor;
}

void QtDroidPopupMenu::setAnchor(QtDroidView *anchor)
{
    if (m_anchor != anchor) {
        m_anchor = anchor;
        emit anchorChanged();
    }
}

int QtDroidPopupMenu::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtDroidPopupMenu::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QtDroidPopupMenu::show()
{
    QtDroidView *anchor = m_anchor ? m_anchor : qobject_cast<QtDroidView *>(parent());
    if (!anchor) {
        qWarning() << "PopupMenu parent must be either anchored or in a view.";
        return;
    }

    QtDroidContext *context = anchor->context();
    if (!context) {
        qWarning() << "PopupMenu is not ready - no context.";
        return;
    }

    QAndroidJniObject c = context->instance();
    QAndroidJniObject a = anchor->instance();

    callFunction([=]() {
        QAndroidJniObject popup;
        if (!m_gravity.isNull()) {
            popup = QAndroidJniObject("android/widget/PopupMenu",
                                      "(Landroid/content/Context;Landroid/view/View;I)V",
                                      c.object(), a.object(), m_gravity.value());
        } else {
            popup = QAndroidJniObject("android/widget/PopupMenu",
                                      "(Landroid/content/Context;Landroid/view/View;)V",
                                      c.object(), a.object());
        }
        setInstance(popup);

        QAndroidJniObject menu = popup.callObjectMethod("getMenu", "()Landroid/view/Menu;");
        foreach (QtDroidMenuItem *item, m_items) {
            QAndroidJniObject it = menu.callObjectMethod("add",
                                                         "(Ljava/lang/CharSequence;)Landroid/view/MenuItem;",
                                                         QAndroidJniObject::fromString(item->title()).object());
            //it.callMethod<void>("...");
        }

        popup.callMethod<void>("show");
    });
}

void QtDroidPopupMenu::dismiss()
{
    callVoidMethod("dismiss");
}

void QtDroidPopupMenu::objectAdded(QObject *object)
{
    QtDroidMenuItem *item = qobject_cast<QtDroidMenuItem *>(object);
    if (item)
        m_items += item;
}

void QtDroidPopupMenu::objectRemoved(QObject *object)
{
    QtDroidMenuItem *item = qobject_cast<QtDroidMenuItem *>(object);
    if (item)
        m_items.removeOne(item);
}
