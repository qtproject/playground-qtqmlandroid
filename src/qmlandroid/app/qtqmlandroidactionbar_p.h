#ifndef QQMLANDROIDACTIONBAR_P_H
#define QQMLANDROIDACTIONBAR_P_H

#include "qtqmlandroidobject_p.h"
#include "qtqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidDrawable;

class QQmlAndroidActionBar : public QQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(qreal elevation READ elevation WRITE setElevation NOTIFY elevationChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString subtitle READ subtitle WRITE setSubtitle NOTIFY subtitleChanged)
    Q_PROPERTY(QQmlAndroidDrawable *background READ background WRITE setBackground NOTIFY backgroundChanged)

public:
    explicit QQmlAndroidActionBar(QObject *parent = 0);

    bool isVisible() const;
    void setVisible(bool visible);

    qreal elevation() const;
    void setElevation(qreal elevation);

    QString title() const;
    void setTitle(const QString &title);

    QString subtitle() const;
    void setSubtitle(const QString &subtitle);

    QQmlAndroidDrawable *background() const;
    void setBackground(QQmlAndroidDrawable *background);

Q_SIGNALS:
    void visibleChanged();
    void elevationChanged();
    void titleChanged();
    void subtitleChanged();
    void backgroundChanged();

protected:
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateBackground();

private:
    bool m_visible;
    qreal m_elevation;
    QString m_title;
    QString m_subtitle;
    QQmlAndroidDrawable *m_background;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACTIONBAR_P_H
