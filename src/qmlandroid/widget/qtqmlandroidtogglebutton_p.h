#ifndef QTQMLANDROIDTOGGLEBUTTON_P_H
#define QTQMLANDROIDTOGGLEBUTTON_P_H

#include "qtqmlandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidToggleButton : public QtQmlAndroidCompoundButton
{
    Q_OBJECT
    Q_PROPERTY(QString textOn READ textOn WRITE setTextOn NOTIFY textOnChanged)
    Q_PROPERTY(QString textOff READ textOff WRITE setTextOff NOTIFY textOffChanged)

public:
    explicit QtQmlAndroidToggleButton(QtQmlAndroidView *parent = 0);

    QString textOn() const;
    void setTextOn(const QString &text);

    QString textOff() const;
    void setTextOff(const QString &text);

Q_SIGNALS:
    void textOnChanged();
    void textOffChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QString m_textOn;
    QString m_textOff;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDTOGGLEBUTTON_P_H
