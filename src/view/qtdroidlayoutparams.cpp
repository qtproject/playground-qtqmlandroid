#include "qtdroidlayoutparams_p.h"
#include "qtdroidfunctions_p.h"
#include "qtdroidview_p.h"

QtAndroidLayoutParams::QtAndroidLayoutParams(QtAndroidView *view) :
    QObject(view), m_view(view)
{
    m_view->setLayoutParams(this);
}

int QtAndroidLayoutParams::width() const
{
    if (m_width.isNull())
        return MATCH_PARENT;
    return m_width.value();
}

void QtAndroidLayoutParams::setWidth(int value)
{
    if (value != width()) {
        m_width = value;
        // TODO: invalidate
        emit widthChanged();
    }
}

int QtAndroidLayoutParams::height() const
{
    if (m_height.isNull())
        return MATCH_PARENT;
    return m_height.value();
}

void QtAndroidLayoutParams::setHeight(int value)
{
    if (value != height()) {
        m_height = value;
        // TODO: invalidate
        emit heightChanged();
    }
}

void QtAndroidLayoutParams::apply(QtAndroidView *v)
{
    QAndroidJniObject view = v->instance();
    QtAndroid::callFunction([=]() {
        QAndroidJniObject params = construct();
        inflate(params);
        view.callMethod<void>("setLayoutParams",
                              "(Landroid/view/ViewGroup$LayoutParams;)V",
                              params.object());
    });
}

QAndroidJniObject QtAndroidLayoutParams::construct()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtAndroidLayoutParams::inflate(QAndroidJniObject &params)
{
    if (!m_width.isNull())
        params.setField<int>("width", m_width.value());
    if (!m_height.isNull())
        params.setField<int>("height", m_height.value());
}
