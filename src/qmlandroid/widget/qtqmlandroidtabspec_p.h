#ifndef QTQMLANDROIDTABSPEC_P_H
#define QTQMLANDROIDTABSPEC_P_H

#include <QtCore/qobject.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidView;
class QtQmlAndroidTabHost;

class QtQmlAndroidTabSpec : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)

public:
    explicit QtQmlAndroidTabSpec(QtQmlAndroidView *view);

    static QtQmlAndroidTabSpec *qmlAttachedProperties(QObject *object);

    QString label() const;
    void setLabel(const QString &label);

    void setup(QAndroidJniObject &host, int index);

Q_SIGNALS:
    void labelChanged();

private:
    QString m_label;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtQmlAndroidTabSpec, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTQMLANDROIDTABSPEC_P_H
