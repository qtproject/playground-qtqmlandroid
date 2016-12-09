#ifndef QQMLANDROIDCONTEXTUAL_P_H
#define QQMLANDROIDCONTEXTUAL_P_H

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

#include <QtQmlAndroid/private/qqmlandroidobject_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidContext;

class Q_QMLANDROID_EXPORT QQmlAndroidContextual : public QQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidContext *context READ context NOTIFY contextChanged)

public:
    explicit QQmlAndroidContextual(QObject *parent = 0);
    explicit QQmlAndroidContextual(QQmlAndroidContext *context, QObject *parent = 0);

    QAndroidJniObject ctx() const;
    QQmlAndroidContext *context() const;
    void setContext(QQmlAndroidContext *context);

Q_SIGNALS:
    void contextChanged();

protected:
    void componentComplete() Q_DECL_OVERRIDE;

private Q_SLOTS:
    bool initContext(QQmlAndroidContext *context = 0);
    void resolveContext();
    void propagateContext();

private:
    QQmlAndroidContext *m_context;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCONTEXTUAL_P_H
