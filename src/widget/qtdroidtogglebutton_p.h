#ifndef QTDROIDTOGGLEBUTTON_P_H
#define QTDROIDTOGGLEBUTTON_P_H

#include "qtdroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtDroidToggleButton : public QtDroidCompoundButton
{
    Q_OBJECT
    Q_PROPERTY(QString textOn READ textOn WRITE setTextOn NOTIFY textOnChanged)
    Q_PROPERTY(QString textOff READ textOff WRITE setTextOff NOTIFY textOffChanged)

public:
    explicit QtDroidToggleButton(QtDroidView *parent = 0);

    QString textOn() const;
    void setTextOn(const QString &text);

    QString textOff() const;
    void setTextOff(const QString &text);

Q_SIGNALS:
    void textOnChanged();
    void textOffChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

private:
    QString m_textOn;
    QString m_textOff;
};

QT_END_NAMESPACE

#endif // QTDROIDTOGGLEBUTTON_P_H
