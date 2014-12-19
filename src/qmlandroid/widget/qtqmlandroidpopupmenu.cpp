#include "qtqmlandroidpopupmenu_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidmenuitem_p.h"
#include "qtqmlandroidcontext_p.h"
#include "qtqmlandroidview_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QtQmlAndroidPopupMenu::QtQmlAndroidPopupMenu(QObject *parent) :
    QtQmlAndroidObject(parent), m_anchor(0)
{
}

QList<QtQmlAndroidMenuItem *> QtQmlAndroidPopupMenu::items() const
{
    QList<QtQmlAndroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QtQmlAndroidMenuItem *item = qobject_cast<QtQmlAndroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}

QtQmlAndroidView *QtQmlAndroidPopupMenu::anchor() const
{
    return m_anchor;
}

void QtQmlAndroidPopupMenu::setAnchor(QtQmlAndroidView *anchor)
{
    if (m_anchor != anchor) {
        m_anchor = anchor;
        emit anchorChanged();
    }
}

int QtQmlAndroidPopupMenu::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtQmlAndroidPopupMenu::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QtQmlAndroidPopupMenu::show()
{
    QtQmlAndroidView *anchor = m_anchor ? m_anchor : qobject_cast<QtQmlAndroidView *>(parent());
    if (!anchor) {
        qWarning() << "PopupMenu parent must be either anchored or in a view.";
        return;
    }

    QtQmlAndroidContext *context = anchor->context();
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
        foreach (QtQmlAndroidMenuItem *item, items()) {
            QAndroidJniObject it = menu.callObjectMethod("add",
                                                         "(Ljava/lang/CharSequence;)Landroid/view/MenuItem;",
                                                         QAndroidJniObject::fromString(item->title()).object());
            //it.callMethod<void>("...");
        }

        popup.callMethod<void>("show");
    });
}

void QtQmlAndroidPopupMenu::dismiss()
{
    QtQmlAndroid::callVoidMethod(instance(), "dismiss");
}

QT_END_NAMESPACE
