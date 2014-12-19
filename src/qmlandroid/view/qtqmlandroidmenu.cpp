#include "qtqmlandroidmenu_p.h"
#include "qtqmlandroidmenuitem_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidMenu::QtQmlAndroidMenu(QObject *parent) :
    QtQmlAndroidContextual(parent)
{
}

QList<QtQmlAndroidMenuItem *> QtQmlAndroidMenu::items() const
{
    QList<QtQmlAndroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QtQmlAndroidMenuItem *item = qobject_cast<QtQmlAndroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}

QAndroidJniObject QtQmlAndroidMenu::onCreate()
{
    return QAndroidJniObject("qt/android/view/QtMenu");
}

void QtQmlAndroidMenu::onInflate(QAndroidJniObject &instance)
{
    foreach (QtQmlAndroidMenuItem *item, items()) {
        item->construct();
        if (item->isValid())
            instance.callMethod<void>("add", "(Lqt/android/view/QtMenuItem;)V", item->instance().object());
    }
}

QT_END_NAMESPACE
