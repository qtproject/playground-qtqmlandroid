#include "qqmlandroidarrayadapter_p.h"
#include "qqmlandroidadapterview_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidArrayAdapter::QQmlAndroidArrayAdapter(QObject *parent) :
    QQmlAndroidBaseAdapter(parent), m_style(17367043) // TODO: android.R.layout.simple_list_item_1
{
}

int QQmlAndroidArrayAdapter::style() const
{
    return m_style;
}

void QQmlAndroidArrayAdapter::setStyle(int style)
{
    if (m_style != style) {
        m_style = style;
        emit styleChanged();
    }
}

QStringList QQmlAndroidArrayAdapter::array() const
{
    return m_array;
}

void QQmlAndroidArrayAdapter::setArray(const QStringList &array)
{
    if (m_array != array) {
        m_array = array; // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

int QQmlAndroidArrayAdapter::count() const
{
    return m_array.count();
}

QString QQmlAndroidArrayAdapter::getItem(int position) const
{
    return m_array.value(position);
}

void QQmlAndroidArrayAdapter::clear()
{
    if (!m_array.isEmpty()) {
        m_array.clear(); // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

QAndroidJniObject QQmlAndroidArrayAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/ArrayAdapter",
                             "(Landroid/content/Context;I)V",
                             ctx().object(),
                             m_style);
}

void QQmlAndroidArrayAdapter::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidBaseAdapter::onInflate(instance);

    foreach (const QString &str, m_array)
        instance.callMethod<void>("add", "(Ljava/lang/Object;)V", QAndroidJniObject::fromString(str).object());
}

QT_END_NAMESPACE
