#include "qtdroidlayoutparams_p.h"
#include "qtdroidlinearlayoutparams_p.h"
#include "qtdroidlinearlayout_p.h"
#include "qtdroidview_p.h"

QtDroidLayoutParams::QtDroidLayoutParams(QtDroidView *view) :
    QtDroidObject(view), m_view(view)
{
}

QtDroidLayoutParams *QtDroidLayoutParams::qmlAttachedProperties(QObject *object)
{
    QtDroidLinearLayout *linearLayout = qobject_cast<QtDroidLinearLayout*>(object);
    if (linearLayout)
        return new QtDroidLinearLayoutParams(linearLayout);

    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidLayoutParams(view);
    return 0;
}

QtDroidLayoutParams::Size QtDroidLayoutParams::width() const
{
    if (m_width.isNull())
        return MATCH_PARENT;
    return m_width.value();
}

void QtDroidLayoutParams::setWidth(Size value)
{
    if (value != width()) {
        m_width = value;
//        if (isValid())
//            jniObject().callMethod<void>("applyText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(txt).object());
        emit widthChanged();
    }
}

QtDroidLayoutParams::Size QtDroidLayoutParams::height() const
{
    if (m_height.isNull())
        return MATCH_PARENT;
    return m_height.value();
}

void QtDroidLayoutParams::setHeight(Size value)
{
    if (value != height()) {
        m_height = value;
//        if (isValid())
//            jniObject().callMethod<void>("applyText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(txt).object());
        emit heightChanged();
    }
}

void QtDroidLayoutParams::applyParams(QtDroidView *view)
{
    if (!m_width.isNull())
        ;
    if (!m_height.isNull())
        ;
}
