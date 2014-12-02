#include "qtdroidtogglebutton_p.h"

QtDroidToggleButton::QtDroidToggleButton(QObject *parent) : QtDroidCompoundButton(parent)
{
}

static void callSetText(const QAndroidJniObject& button, const char *method, const QString &text)
{
    if (button.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            button.callMethod<void>(method, "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(text).object());
        });
    }
}

QString QtDroidToggleButton::textOn() const
{
    return m_textOn;
}

void QtDroidToggleButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        callSetText(instance(), "setTextOn", text);
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
        callSetText(instance(), "setTextOff", text);
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
        callSetText(instance(), "setTextOn", m_textOn);
    if (!m_textOff.isNull())
        callSetText(instance(), "setTextOff", m_textOff);
}
