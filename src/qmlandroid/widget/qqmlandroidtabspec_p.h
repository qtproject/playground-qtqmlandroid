#ifndef QQMLANDROIDTABSPEC_P_H
#define QQMLANDROIDTABSPEC_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qobject.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidView;
class QQmlAndroidTabHost;

class QQmlAndroidTabSpec : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)

public:
    explicit QQmlAndroidTabSpec(QQmlAndroidView *view);

    static QQmlAndroidTabSpec *qmlAttachedProperties(QObject *object);

    QString label() const;
    void setLabel(const QString &label);

    void setup(QAndroidJniObject &host, int index);

Q_SIGNALS:
    void labelChanged();

private:
    QString m_label;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QQmlAndroidTabSpec, QML_HAS_ATTACHED_PROPERTIES)

#endif // QQMLANDROIDTABSPEC_P_H
