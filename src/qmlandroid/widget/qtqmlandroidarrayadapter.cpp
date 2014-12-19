#include "qtqmlandroidarrayadapter_p.h"
#include "qtqmlandroidadapterview_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidArrayAdapter::QtQmlAndroidArrayAdapter(QObject *parent) :
    QtQmlAndroidBaseAdapter(parent), m_style(17367043) // TODO: android.R.layout.simple_list_item_1
{
}

int QtQmlAndroidArrayAdapter::style() const
{
    return m_style;
}

void QtQmlAndroidArrayAdapter::setStyle(int style)
{
    if (m_style != style) {
        m_style = style;
        emit styleChanged();
    }
}

QStringList QtQmlAndroidArrayAdapter::array() const
{
    return m_array;
}

void QtQmlAndroidArrayAdapter::setArray(const QStringList &array)
{
    if (m_array != array) {
        m_array = array; // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

int QtQmlAndroidArrayAdapter::count() const
{
    return m_array.count();
}

QString QtQmlAndroidArrayAdapter::getItem(int position) const
{
    return m_array.value(position);
}

void QtQmlAndroidArrayAdapter::clear()
{
    if (!m_array.isEmpty()) {
        m_array.clear(); // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

QAndroidJniObject QtQmlAndroidArrayAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/ArrayAdapter",
                             "(Landroid/content/Context;I)V",
                             ctx().object(),
                             m_style);
}

void QtQmlAndroidArrayAdapter::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidBaseAdapter::onInflate(instance);

    foreach (const QString &str, m_array)
        instance.callMethod<void>("add", "(Ljava/lang/Object;)V", QAndroidJniObject::fromString(str).object());
}

QT_END_NAMESPACE
