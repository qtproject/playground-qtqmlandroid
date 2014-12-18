#include "qtandroidpopupmenu_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidmenuitem_p.h"
#include "qtandroidcontext_p.h"
#include "qtandroidview_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QtAndroidPopupMenu::QtAndroidPopupMenu(QObject *parent) :
    QtAndroidObject(parent), m_anchor(0)
{
}

QList<QtAndroidMenuItem *> QtAndroidPopupMenu::items() const
{
    QList<QtAndroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QtAndroidMenuItem *item = qobject_cast<QtAndroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}

QtAndroidView *QtAndroidPopupMenu::anchor() const
{
    return m_anchor;
}

void QtAndroidPopupMenu::setAnchor(QtAndroidView *anchor)
{
    if (m_anchor != anchor) {
        m_anchor = anchor;
        emit anchorChanged();
    }
}

int QtAndroidPopupMenu::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtAndroidPopupMenu::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QtAndroidPopupMenu::show()
{
    QtAndroidView *anchor = m_anchor ? m_anchor : qobject_cast<QtAndroidView *>(parent());
    if (!anchor) {
        qWarning() << "PopupMenu parent must be either anchored or in a view.";
        return;
    }

    QtAndroidContext *context = anchor->context();
    if (!context) {
        qWarning() << "PopupMenu is not ready - no context.";
        return;
    }

    QAndroidJniObject c = context->instance();
    QAndroidJniObject a = anchor->instance();

    QtAndroid::callFunction([=]() {
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
        foreach (QtAndroidMenuItem *item, items()) {
            QAndroidJniObject it = menu.callObjectMethod("add",
                                                         "(Ljava/lang/CharSequence;)Landroid/view/MenuItem;",
                                                         QAndroidJniObject::fromString(item->title()).object());
            //it.callMethod<void>("...");
        }

        popup.callMethod<void>("show");
    });
}

void QtAndroidPopupMenu::dismiss()
{
    QtAndroid::callVoidMethod(instance(), "dismiss");
}

QT_END_NAMESPACE
