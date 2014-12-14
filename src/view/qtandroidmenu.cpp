#include "qtandroidmenu_p.h"
#include "qtandroidmenuitem_p.h"

QtAndroidMenu::QtAndroidMenu(QObject *parent) : QtAndroidObject(parent)
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

QAndroidJniObject QtAndroidMenu::construct()
{
    return QAndroidJniObject("qt/android/view/QtMenu");
}

void QtAndroidMenu::inflate()
{
    QAndroidJniObject menu = instance();
    foreach (QtAndroidMenuItem *item, items()) {
        QAndroidJniObject it = item->construct();
        item->setInstance(it);
        item->inflate();
        menu.callMethod<void>("add", "(Lqt/android/view/QtMenuItem;)V", it.object());
    }
}
