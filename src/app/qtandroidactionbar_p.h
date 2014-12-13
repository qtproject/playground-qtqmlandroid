#ifndef QTANDROIDACTIONBAR_P_H
#define QTANDROIDACTIONBAR_P_H

#include "qtandroidobject_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidActivity;
class QtAndroidDrawable;

class QtAndroidActionBar : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(qreal elevation READ elevation WRITE setElevation NOTIFY elevationChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString subtitle READ subtitle WRITE setSubtitle NOTIFY subtitleChanged)
    Q_PROPERTY(QtAndroidDrawable *background READ background WRITE setBackground NOTIFY backgroundChanged)

public:
    explicit QtAndroidActionBar(QObject *parent = 0);

    bool isVisible() const;
    void setVisible(bool visible);

    qreal elevation() const;
    void setElevation(qreal elevation);

    QString title() const;
    void setTitle(const QString &title);

    QString subtitle() const;
    void setSubtitle(const QString &subtitle);

    QtAndroidDrawable *background() const;
    void setBackground(QtAndroidDrawable *background);

    QtAndroidActivity *activity() const;
    void setActivity(QtAndroidActivity *activity);

Q_SIGNALS:
    void visibleChanged();
    void elevationChanged();
    void titleChanged();
    void subtitleChanged();
    void backgroundChanged();

private:
    bool m_visible;
    qreal m_elevation;
    QString m_title;
    QString m_subtitle;
    QtAndroidActivity *m_activity;
    QtAndroidDrawable *m_background;
};

QT_END_NAMESPACE

#endif // QTANDROIDACTIONBAR_P_H
