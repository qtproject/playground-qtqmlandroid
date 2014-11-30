#ifndef QTDROIDTEXTVIEW_P_H
#define QTDROIDTEXTVIEW_P_H

#include "qtdroidview_p.h"
#include "qtdroidoptional_p.h"
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

class QtDroidTextView : public QtDroidView
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(qreal textSize READ textSize WRITE setTextSize NOTIFY textSizeChanged)

public:
    explicit QtDroidTextView(QObject *parent = 0);

    QString text() const;
    void setText(const QString &text);

    QColor textColor() const;
    void setTextColor(const QColor& color);

    qreal textSize() const;
    void setTextSize(qreal size);

Q_SIGNALS:
    void textChanged();
    void textColorChanged();
    void textSizeChanged();

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;

private:
    QtDroidOptional<QString> m_text;
    QtDroidOptional<QColor> m_textColor;
    QtDroidOptional<qreal> m_textSize;
};

QT_END_NAMESPACE

#endif // QTDROIDTEXTVIEW_P_H
