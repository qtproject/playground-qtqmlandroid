#include "qtdroidtextview_p.h"

QtDroidTextView::QtDroidTextView(QObject *parent) : QtDroidView(parent)
{
}

QString QtDroidTextView::text() const
{
    if (m_text.isNull())
        return QString();
    return m_text.value();
}

static void callSetText(const QAndroidJniObject& view, const QString &text)
{
    if (view.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            view.callMethod<void>("setText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(text).object());
        });
    }
}

void QtDroidTextView::setText(const QString &txt)
{
    if (txt != text()) {
        m_text = txt;
        callSetText(instance(), txt);
        emit textChanged();
    }
}

QColor QtDroidTextView::textColor() const
{
    if (m_textColor.isNull())
        return QColor();
    return m_textColor.value();
}

static void callSetTextColor(const QAndroidJniObject& view, const QColor &color)
{
    if (view.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            view.callMethod<void>("setTextColor", "(I)V", color.rgba());
        });
    }
}

void QtDroidTextView::setTextColor(const QColor& color)
{
    if (color != textColor()) {
        m_textColor = color;
        callSetTextColor(instance(), color);
        emit textColorChanged();
    }
}

qreal QtDroidTextView::textSize() const
{
    if (m_textSize.isNull())
        return -1;
    return m_textSize.value();
}

static void callSetTextSize(const QAndroidJniObject& view, qreal size)
{
    if (view.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            view.callMethod<void>("setTextSize", "(IF)V", 0, size); // TypedValue.COMPLEX_UNIT_PX
        });
    }
}

void QtDroidTextView::setTextSize(qreal size)
{
    if (size != textSize()) {
        m_textSize = size;
        callSetTextSize(instance(), size);
        emit textSizeChanged();
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
        callSetText(instance(), m_text.value());
    if (!m_textColor.isNull())
        callSetTextColor(instance(), m_textColor.value());
    if (!m_textSize.isNull())
        callSetTextSize(instance(), m_textSize.value());
}
