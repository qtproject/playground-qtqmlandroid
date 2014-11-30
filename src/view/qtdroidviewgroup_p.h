#ifndef QTDROIDVIEWGROUP_P_H
#define QTDROIDVIEWGROUP_P_H

#include "qtdroidview_p.h"

QT_BEGIN_NAMESPACE

class QtDroidViewGroup : public QtDroidView
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QtDroidView> children READ children NOTIFY childrenChanged)

public:
    explicit QtDroidViewGroup(QObject *parent = 0);

    QQmlListProperty<QtDroidView> children();

Q_SIGNALS:
    void childrenChanged();

protected:
    void objectAdded(QObject *object) Q_DECL_OVERRIDE;
    void objectRemoved(QObject *object) Q_DECL_OVERRIDE;

    static void children_append(QQmlListProperty<QtDroidView> *list, QtDroidView *child);
    static int children_count(QQmlListProperty<QtDroidView> *list);
    static QtDroidView *children_at(QQmlListProperty<QtDroidView> *list, int index);
    static void children_clear(QQmlListProperty<QtDroidView> *list);

    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;

protected:
    QList<QtDroidView *> m_children;
};

QT_END_NAMESPACE

#endif // QTDROIDVIEWGROUP_P_H
