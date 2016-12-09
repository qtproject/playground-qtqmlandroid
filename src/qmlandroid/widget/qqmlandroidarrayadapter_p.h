#ifndef QQMLANDROIDARRAYADAPTER_P_H
#define QQMLANDROIDARRAYADAPTER_P_H

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

#include <QtQmlAndroid/private/qqmlandroidbaseadapter_p.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidArrayAdapter : public QQmlAndroidBaseAdapter
{
    Q_OBJECT
    Q_PROPERTY(int style READ style WRITE setStyle NOTIFY styleChanged)
    Q_PROPERTY(QStringList array READ array WRITE setArray NOTIFY arrayChanged)

public:
    explicit QQmlAndroidArrayAdapter(QObject *parent = 0);

    int style() const;
    void setStyle(int style);

    QStringList array() const;
    void setArray(const QStringList &array);

    int count() const Q_DECL_OVERRIDE;
    Q_INVOKABLE QString getItem(int position) const;

public Q_SLOTS:
    void clear() Q_DECL_OVERRIDE;

Q_SIGNALS:
    void styleChanged();
    void arrayChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    int m_style;
    QStringList m_array;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDARRAYADAPTER_P_H
