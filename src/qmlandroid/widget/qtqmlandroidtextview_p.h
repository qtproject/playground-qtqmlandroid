#ifndef QTQMLANDROIDTEXTVIEW_P_H
#define QTQMLANDROIDTEXTVIEW_P_H

#include "qtqmlandroidview_p.h"
#include "qtqmlandroidoptional_p.h"
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidTextView : public QtQmlAndroidView
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(int textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(qreal textSize READ textSize WRITE setTextSize NOTIFY textSizeChanged)
    Q_PROPERTY(QString hint READ hint WRITE setHint NOTIFY hintChanged)
    Q_PROPERTY(bool singleLine READ isSingleLine WRITE setSingleLine NOTIFY singleLineChanged)
    Q_PROPERTY(int inputType READ inputType WRITE setInputType NOTIFY inputTypeChanged)

public:
    explicit QtQmlAndroidTextView(QtQmlAndroidView *parent = 0);

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

    int inputType() const;
    void setInputType(int type);

Q_SIGNALS:
    void textChanged();
    void textColorChanged();
    void textSizeChanged();
    void hintChanged();
    void singleLineChanged();
    void inputTypeChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QString m_text;
    QString m_hint;
    QtQmlAndroidOptional<int> m_textColor;
    QtQmlAndroidOptional<qreal> m_textSize;
    bool m_singleLine;
    QtQmlAndroidOptional<int> m_inputType;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDTEXTVIEW_P_H
