#ifndef QTANDROIDTOGGLEBUTTON_P_H
#define QTANDROIDTOGGLEBUTTON_P_H

#include "qtandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidToggleButton : public QtAndroidCompoundButton
{
    Q_OBJECT
    Q_PROPERTY(QString textOn READ textOn WRITE setTextOn NOTIFY textOnChanged)
    Q_PROPERTY(QString textOff READ textOff WRITE setTextOff NOTIFY textOffChanged)

public:
    explicit QtAndroidToggleButton(QtAndroidView *parent = 0);

    QString textOn() const;
    void setTextOn(const QString &text);

    QString textOff() const;
    void setTextOff(const QString &text);

Q_SIGNALS:
    void textOnChanged();
    void textOffChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;

private:
    QString m_textOn;
    QString m_textOff;
};

QT_END_NAMESPACE

#endif // QTANDROIDTOGGLEBUTTON_P_H
