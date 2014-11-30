#ifndef QTDROIDOBJECT_P_H
#define QTDROIDOBJECT_P_H

#include <QtCore/qobject.h>
#include <QtQml/qqmllist.h>
#include <QtQml/qqmlparserstatus.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>
#include <functional>

QT_BEGIN_NAMESPACE

class QtDroidObject : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
    Q_INTERFACES(QQmlParserStatus)

public:
    explicit QtDroidObject(QObject *parent = 0);

    QAndroidJniObject instance() const;
    void setInstance(const QAndroidJniObject &instance);

    static void callUiMethod(std::function<void()> method);

    QQmlListProperty<QObject> data();

Q_SIGNALS:
    void dataChanged();

protected:
    bool isComponentComplete() const;
    void classBegin() Q_DECL_OVERRIDE;
    void componentComplete() Q_DECL_OVERRIDE;

    static void data_append(QQmlListProperty<QObject> *list, QObject *object);
    static int data_count(QQmlListProperty<QObject> *list);
    static QObject *data_at(QQmlListProperty<QObject> *list, int index);
    static void data_clear(QQmlListProperty<QObject> *list);

    virtual void objectAdded(QObject *object) { Q_UNUSED(object) }
    virtual void objectRemoved(QObject *object) { Q_UNUSED(object) }

private:
    bool m_complete;
    QList<QObject *> m_data;
    QAndroidJniObject m_instance;
};

QT_END_NAMESPACE

#endif // QTDROIDOBJECT_P_H
