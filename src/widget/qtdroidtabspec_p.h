#ifndef QTDROIDTABSPEC_P_H
#define QTDROIDTABSPEC_P_H

#include <QtCore/qobject.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QtDroidView;
class QAndroidJniObject;

class QtDroidTabSpec : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)

public:
    explicit QtDroidTabSpec(QtDroidView *view);

    static QtDroidTabSpec *qmlAttachedProperties(QObject *object);

    QString label() const;
    void setLabel(const QString &label);

Q_SIGNALS:
    void labelChanged();

protected:
    void applyParams(QAndroidJniObject &spec);

private:
    QString m_label;

    friend class QtDroidTabHost;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtDroidTabSpec, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTDROIDTABSPEC_P_H
