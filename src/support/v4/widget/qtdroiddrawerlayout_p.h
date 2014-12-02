#ifndef QTDROIDDRAWERLAYOUT_P_H
#define QTDROIDDRAWERLAYOUT_P_H

#include "qtdroidviewgroup_p.h"
#include "qtdroiddrawerlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidActionBarDrawerToggle;

class QtDroidDrawerLayout : public QtDroidViewGroup
{
    Q_OBJECT

public:
    explicit QtDroidDrawerLayout(QObject *parent = 0);

    static QtDroidDrawerLayoutParams *qmlAttachedProperties(QObject *object);

public Q_SLOTS:
    void closeDrawers();
    void closeDrawer(int gravity);

protected:
    void objectAdded(QObject *object) Q_DECL_OVERRIDE;

    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;

private:
    QtDroidActionBarDrawerToggle *m_toggle;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtDroidDrawerLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTDROIDDRAWERLAYOUT_P_H
