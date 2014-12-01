#include "qtdroidarrayadapter_p.h"

QtDroidArrayAdapter::QtDroidArrayAdapter(QObject *parent) : QtDroidObject(parent)
{
}

QStringList QtDroidArrayAdapter::array() const
{
    return m_array;
}

void QtDroidArrayAdapter::setArray(const QStringList &array)
{
    if (m_array != array) {
        m_array = array; // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

int QtDroidArrayAdapter::count() const
{
    return m_array.count();
}

QString QtDroidArrayAdapter::getItem(int position) const
{
    return m_array.value(position);
}

void QtDroidArrayAdapter::clear()
{
    if (!m_array.isEmpty()) {
        m_array.clear(); // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

QAndroidJniObject QtDroidArrayAdapter::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ArrayAdapter",
                             "(Landroid/content/Context;I)V",
                             context,
                             17367043); // TODO: android.R.layout.simple_list_item_1
}

void QtDroidArrayAdapter::inflate(jobject context)
{
    QAndroidJniObject adapter = instance();
    if (adapter.isValid()) {
        foreach (const QString &str, m_array)
            adapter.callMethod<void>("add", "(Ljava/lang/Object;)V", QAndroidJniObject::fromString(str).object());
    }
}
