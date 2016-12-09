#ifndef QQMLANDROIDBASEADAPTER_P_H
#define QQMLANDROIDBASEADAPTER_P_H

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

#include <QtQmlAndroid/private/qqmlandroidcontextual_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidBaseAdapter : public QQmlAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit QQmlAndroidBaseAdapter(QObject *parent = 0);

    virtual int count() const = 0;

public Q_SLOTS:
    virtual void clear() = 0;

Q_SIGNALS:
    void countChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDBASEADAPTER_P_H
