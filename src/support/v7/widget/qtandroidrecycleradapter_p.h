#ifndef QTANDROIDRECYCLERADAPTER_P_H
#define QTANDROIDRECYCLERADAPTER_P_H

#include "qtandroidcontextual_p.h"
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QtAndroidRecyclerAdapter : public QtAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(QStringList array READ array WRITE setArray NOTIFY arrayChanged)

public:
    explicit QtAndroidRecyclerAdapter(QObject *parent = 0);

    // TODO: RecyclerView.Adapter is not based on array...
    QStringList array() const;
    void setArray(const QStringList &array);

Q_SIGNALS:
    void arrayChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QStringList m_array;
};

QT_END_NAMESPACE

#endif // QTANDROIDRECYCLERADAPTER_P_H
