#include "qtandroidmenu_p.h"
#include "qtandroidmenuitem_p.h"

QT_BEGIN_NAMESPACE

QtAndroidMenu::QtAndroidMenu(QObject *parent) :
    QtAndroidContextual(parent)
{
}

QList<QtAndroidMenuItem *> QtAndroidMenu::items() const
{
    QList<QtAndroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QtAndroidMenuItem *item = qobject_cast<QtAndroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}

QAndroidJniObject QtAndroidMenu::onCreate()
{
    return QAndroidJniObject("qt/android/view/QtMenu");
}

void QtAndroidMenu::onInflate(QAndroidJniObject &instance)
{
    foreach (QtAndroidMenuItem *item, items()) {
        item->construct();
        if (item->isValid())
            instance.callMethod<void>("add", "(Lqt/android/view/QtMenuItem;)V", item->instance().object());
    }
}

QT_END_NAMESPACE
