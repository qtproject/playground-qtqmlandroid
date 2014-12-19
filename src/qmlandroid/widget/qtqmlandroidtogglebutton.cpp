#include "qtqmlandroidtogglebutton_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidToggleButton::QQmlAndroidToggleButton(QQmlAndroidView *parent) :
    QQmlAndroidCompoundButton(parent)
{
}

QString QQmlAndroidToggleButton::textOn() const
{
    return m_textOn;
}

void QQmlAndroidToggleButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        QtQmlAndroid::callTextMethod(instance(), "setTextOn", text);
        emit textOnChanged();
    }
}

QString QQmlAndroidToggleButton::textOff() const
{
    return m_textOff;
}

void QQmlAndroidToggleButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        QtQmlAndroid::callTextMethod(instance(), "setTextOff", text);
        emit textOffChanged();
    }
}

QAndroidJniObject QQmlAndroidToggleButton::onCreate()
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidToggleButton::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidCompoundButton::onInflate(instance);

    if (!m_textOn.isNull())
        instance.callMethod<void>("setTextOn", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOn).object());
    if (!m_textOff.isNull())
        instance.callMethod<void>("setTextOff", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOff).object());
}

QT_END_NAMESPACE
