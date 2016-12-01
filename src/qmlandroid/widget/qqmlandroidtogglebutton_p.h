#ifndef QQMLANDROIDTOGGLEBUTTON_P_H
#define QQMLANDROIDTOGGLEBUTTON_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qqmlandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidToggleButton : public QQmlAndroidCompoundButton
{
    Q_OBJECT
    Q_PROPERTY(QString textOn READ textOn WRITE setTextOn NOTIFY textOnChanged)
    Q_PROPERTY(QString textOff READ textOff WRITE setTextOff NOTIFY textOffChanged)

public:
    explicit QQmlAndroidToggleButton(QQmlAndroidView *parent = 0);

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

#endif // QQMLANDROIDTOGGLEBUTTON_P_H
