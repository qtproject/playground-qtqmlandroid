#include "qtandroidarrayadapter_p.h"
#include "qtandroidadapterview_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidArrayAdapter::QtAndroidArrayAdapter(QObject *parent) :
    QtAndroidBaseAdapter(parent)
{
}

QStringList QtAndroidArrayAdapter::array() const
{
    return m_array;
}

void QtAndroidArrayAdapter::setArray(const QStringList &array)
{
    if (m_array != array) {
        m_array = array; // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

int QtAndroidArrayAdapter::count() const
{
    return m_array.count();
}

QString QtAndroidArrayAdapter::getItem(int position) const
{
    return m_array.value(position);
}

void QtAndroidArrayAdapter::clear()
{
    if (!m_array.isEmpty()) {
        m_array.clear(); // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

QAndroidJniObject QtAndroidArrayAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/ArrayAdapter",
                             "(Landroid/content/Context;I)V",
                             ctx().object(),
                             17367043); // TODO: android.R.layout.simple_list_item_1
}

void QtAndroidArrayAdapter::onInflate(QAndroidJniObject &instance)
{
    QtAndroidBaseAdapter::onInflate(instance);

    foreach (const QString &str, m_array)
        instance.callMethod<void>("add", "(Ljava/lang/Object;)V", QAndroidJniObject::fromString(str).object());
}
