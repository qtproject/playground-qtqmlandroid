#include "qtqmlandroidpopupmenu_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidmenuitem_p.h"
#include "qtqmlandroidcontext_p.h"
#include "qtqmlandroidview_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QQmlAndroidPopupMenu::QQmlAndroidPopupMenu(QObject *parent) :
    QQmlAndroidObject(parent), m_anchor(0)
{
}

QList<QQmlAndroidMenuItem *> QQmlAndroidPopupMenu::items() const
{
    QList<QQmlAndroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QQmlAndroidMenuItem *item = qobject_cast<QQmlAndroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}

QQmlAndroidView *QQmlAndroidPopupMenu::anchor() const
{
    return m_anchor;
}

void QQmlAndroidPopupMenu::setAnchor(QQmlAndroidView *anchor)
{
    if (m_anchor != anchor) {
        m_anchor = anchor;
        emit anchorChanged();
    }
}

int QQmlAndroidPopupMenu::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QQmlAndroidPopupMenu::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QQmlAndroidPopupMenu::show()
{
    QQmlAndroidView *anchor = m_anchor ? m_anchor : qobject_cast<QQmlAndroidView *>(parent());
    if (!anchor) {
        qWarning() << "PopupMenu parent must be either anchored or in a view.";
        return;
    }

    QQmlAndroidContext *context = anchor->context();
    if (!context) {
        qWarning() << "PopupMenu is not ready - no context.";
        return;
    }

    QAndroidJniObject c = context->instance();
    QAndroidJniObject a = anchor->instance();

    QtQmlAndroid::callFunction([=]() {
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
        inflate(popup);

        QAndroidJniObject menu = popup.callObjectMethod("getMenu", "()Landroid/view/Menu;");
        foreach (QQmlAndroidMenuItem *item, items()) {
            QAndroidJniObject it = menu.callObjectMethod("add",
                                                         "(Ljava/lang/CharSequence;)Landroid/view/MenuItem;",
                                                         QAndroidJniObject::fromString(item->title()).object());
            //it.callMethod<void>("...");
        }

        popup.callMethod<void>("show");
    });
}

void QQmlAndroidPopupMenu::dismiss()
{
    QtQmlAndroid::callVoidMethod(instance(), "dismiss");
}

QT_END_NAMESPACE
