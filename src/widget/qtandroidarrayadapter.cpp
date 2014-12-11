#include "qtandroidarrayadapter_p.h"
#include "qtandroidadapterview_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidArrayAdapter::QtAndroidArrayAdapter(QObject *parent) : QtAndroidBaseAdapter(parent)
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

void QtAndroidArrayAdapter::setup(QtAndroidAdapterView *view)
{
    QAndroidJniObject ctx = view->ctx();
    QAndroidJniObject adv = view->instance();
    QtAndroid::callFunction([=]() {
        QAndroidJniObject adapter("android/widget/ArrayAdapter",
                                  "(Landroid/content/Context;I)V",
                                  ctx.object(),
                                  17367043); // TODO: android.R.layout.simple_list_item_1

        foreach (const QString &str, m_array)
            adapter.callMethod<void>("add", "(Ljava/lang/Object;)V", QAndroidJniObject::fromString(str).object());

        adv.callMethod<void>("setAdapter", "(Landroid/widget/Adapter;)V", adapter.object());
    });
}
