#include "qtdroidlayoutparams_p.h"
#include "qtdroidview_p.h"

QtDroidLayoutParams::QtDroidLayoutParams(QtDroidView *view) :
    QtDroidObject(view), m_view(view)
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
//        if (isValid())
//            jniObject().callMethod<void>("applyText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(txt).object());
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
//        if (isValid())
//            jniObject().callMethod<void>("applyText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(txt).object());
        emit heightChanged();
    }
}

QAndroidJniObject QtDroidLayoutParams::construct()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtDroidLayoutParams::applyParams(QAndroidJniObject &params)
{
    if (!m_width.isNull())
        params.setField<int>("width", m_width.value());
    if (!m_height.isNull())
        params.setField<int>("height", m_height.value());
}
