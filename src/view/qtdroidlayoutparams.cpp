#include "qtdroidlayoutparams_p.h"
#include "qtdroidfunctions_p.h"
#include "qtdroidview_p.h"

QtDroidLayoutParams::QtDroidLayoutParams(QtDroidView *view) :
    QObject(view), m_view(view)
{
    m_view->setLayoutParams(this);
}

int QtDroidLayoutParams::width() const
{
    if (m_width.isNull())
        return MATCH_PARENT;
    return m_width.value();
}

void QtDroidLayoutParams::setWidth(int value)
{
    if (value != width()) {
        m_width = value;
        // TODO: invalidate
        emit widthChanged();
    }
}

int QtDroidLayoutParams::height() const
{
    if (m_height.isNull())
        return MATCH_PARENT;
    return m_height.value();
}

void QtDroidLayoutParams::setHeight(int value)
{
    if (value != height()) {
        m_height = value;
        // TODO: invalidate
        emit heightChanged();
    }
}

void QtDroidLayoutParams::apply(QtDroidView *v)
{
    QAndroidJniObject view = v->instance();
    QtDroid::callFunction([=]() {
        QAndroidJniObject params = construct();
        inflate(params);
        view.callMethod<void>("setLayoutParams",
                              "(Landroid/view/ViewGroup$LayoutParams;)V",
                              params.object());
    });
}

QAndroidJniObject QtDroidLayoutParams::construct()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtDroidLayoutParams::inflate(QAndroidJniObject &params)
{
    if (!m_width.isNull())
        params.setField<int>("width", m_width.value());
    if (!m_height.isNull())
        params.setField<int>("height", m_height.value());
}
