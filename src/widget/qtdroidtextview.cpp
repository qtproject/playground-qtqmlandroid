#include "qtdroidtextview_p.h"
#include "qtdroidfunctions_p.h"
#include "qtdroidcolor_p.h"

QtDroidTextView::QtDroidTextView(QtDroidView *parent) : QtDroidView(parent)
{
}

QString QtDroidTextView::text() const
{
    return m_text;
}

void QtDroidTextView::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        QtDroid::callTextMethod(instance(), "setText", text);
        emit textChanged();
    }
}

int QtDroidTextView::textColor() const
{
    if (m_textColor.isNull())
        return QtDroidColor::BLACK; // TODO
    return m_textColor.value();
}

void QtDroidTextView::setTextColor(int color)
{
    if (color != textColor()) {
        m_textColor = color;
        QtDroid::callIntMethod(instance(), "setTextColor", color);
        emit textColorChanged();
    }
}

qreal QtDroidTextView::textSize() const
{
    if (m_textSize.isNull())
        return -1;
    return m_textSize.value();
}

void QtDroidTextView::setTextSize(qreal size)
{
    if (size != textSize()) {
        m_textSize = size;
        QtDroid::callRealMethod(instance(), "setTextSize", size);
        emit textSizeChanged();
    }
}

QString QtDroidTextView::hint() const
{
    return m_hint;
}

void QtDroidTextView::setHint(const QString &hint)
{
    if (m_hint != hint) {
        m_hint = hint;
        QtDroid::callTextMethod(instance(), "setHint", hint);
        emit hintChanged();
    }
}

QAndroidJniObject QtDroidTextView::construct(jobject context)
{
    return QAndroidJniObject("android/widget/TextView",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidTextView::inflate(jobject context)
{
    QtDroidView::inflate(context);

    if (!m_text.isNull())
        QtDroid::callTextMethod(instance(), "setText", m_text);
    if (!m_textColor.isNull())
        QtDroid::callIntMethod(instance(), "setTextColor", m_textColor.value());
    if (!m_textSize.isNull())
        QtDroid::callRealMethod(instance(), "setTextSize", m_textSize.value());
    if (!m_hint.isNull())
        QtDroid::callTextMethod(instance(), "setHint", m_hint);
}
