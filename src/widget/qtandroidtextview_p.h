#ifndef QTANDROIDTEXTVIEW_P_H
#define QTANDROIDTEXTVIEW_P_H

#include "qtandroidview_p.h"
#include "qtandroidoptional_p.h"
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

class QtAndroidTextView : public QtAndroidView
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(int textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(qreal textSize READ textSize WRITE setTextSize NOTIFY textSizeChanged)
    Q_PROPERTY(QString hint READ hint WRITE setHint NOTIFY hintChanged)
    Q_PROPERTY(bool singleLine READ isSingleLine WRITE setSingleLine NOTIFY singleLineChanged)

public:
    explicit QtAndroidTextView(QtAndroidView *parent = 0);

    QString text() const;
    void setText(const QString &text);

    int textColor() const;
    void setTextColor(int color);

    qreal textSize() const;
    void setTextSize(qreal size);

    QString hint() const;
    void setHint(const QString &hint);

    bool isSingleLine() const;
    void setSingleLine(bool singleLine);

Q_SIGNALS:
    void textChanged();
    void textColorChanged();
    void textSizeChanged();
    void hintChanged();
    void singleLineChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QString m_text;
    QString m_hint;
    QtAndroidOptional<int> m_textColor;
    QtAndroidOptional<qreal> m_textSize;
    bool m_singleLine;
};

QT_END_NAMESPACE

#endif // QTANDROIDTEXTVIEW_P_H
