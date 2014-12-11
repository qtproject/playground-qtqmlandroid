#ifndef QTANDROIDTABSPEC_P_H
#define QTANDROIDTABSPEC_P_H

#include <QtCore/qobject.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QtAndroidView;
class QtAndroidTabHost;

class QtAndroidTabSpec : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)

public:
    explicit QtAndroidTabSpec(QtAndroidView *view);

    static QtAndroidTabSpec *qmlAttachedProperties(QObject *object);

    QString label() const;
    void setLabel(const QString &label);

    void setup(QtAndroidTabHost *host, int index);

Q_SIGNALS:
    void labelChanged();

private:
    QString m_label;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtAndroidTabSpec, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTANDROIDTABSPEC_P_H
