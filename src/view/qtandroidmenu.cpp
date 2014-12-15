#include "qtandroidmenu_p.h"
#include "qtandroidmenuitem_p.h"

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
        QAndroidJniObject it = item->onCreate();
        item->setInstance(it);
        item->onInflate(it);
        instance.callMethod<void>("add", "(Lqt/android/view/QtMenuItem;)V", it.object());
    }
}
