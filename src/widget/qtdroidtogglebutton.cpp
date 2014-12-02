#include "qtdroidtogglebutton_p.h"

QtDroidToggleButton::QtDroidToggleButton(QObject *parent) : QtDroidCompoundButton(parent)
{
}

QString QtDroidToggleButton::textOn() const
{
    return m_textOn;
}

void QtDroidToggleButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        callTextMethod("setTextOn", text);
        emit textOnChanged();
    }
}

QString QtDroidToggleButton::textOff() const
{
    return m_textOff;
}

void QtDroidToggleButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        callTextMethod("setTextOff", text);
        emit textOffChanged();
    }
}

QAndroidJniObject QtDroidToggleButton::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidToggleButton::inflate(jobject context)
{
    QtDroidCompoundButton::inflate(context);

    if (!m_textOn.isNull())
        callTextMethod("setTextOn", m_textOn);
    if (!m_textOff.isNull())
        callTextMethod("setTextOff", m_textOff);
}
