#ifndef QTQMLANDROIDACTIONBAR_P_H
#define QTQMLANDROIDACTIONBAR_P_H

#include "qtqmlandroidobject_p.h"
#include "qtqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidDrawable;

class QtQmlAndroidActionBar : public QtQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(qreal elevation READ elevation WRITE setElevation NOTIFY elevationChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString subtitle READ subtitle WRITE setSubtitle NOTIFY subtitleChanged)
    Q_PROPERTY(QtQmlAndroidDrawable *background READ background WRITE setBackground NOTIFY backgroundChanged)

public:
    explicit QtQmlAndroidActionBar(QObject *parent = 0);

    bool isVisible() const;
    void setVisible(bool visible);

    qreal elevation() const;
    void setElevation(qreal elevation);

    QString title() const;
    void setTitle(const QString &title);

    QString subtitle() const;
    void setSubtitle(const QString &subtitle);

    QtQmlAndroidDrawable *background() const;
    void setBackground(QtQmlAndroidDrawable *background);

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
    QtQmlAndroidDrawable *m_background;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDACTIONBAR_P_H
