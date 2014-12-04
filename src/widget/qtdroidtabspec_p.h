#ifndef QTDROIDTABSPEC_P_H
#define QTDROIDTABSPEC_P_H

#include <QtCore/qobject.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QtDroidView;
class QtDroidTabHost;

class QtDroidTabSpec : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)

public:
    explicit QtDroidTabSpec(QtDroidView *view);

    static QtDroidTabSpec *qmlAttachedProperties(QObject *object);

    QString label() const;
    void setLabel(const QString &label);

    void setup(QtDroidTabHost *host, int index);

Q_SIGNALS:
    void labelChanged();

private:
    QString m_label;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtDroidTabSpec, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTDROIDTABSPEC_P_H
