#ifndef QQMLANDROIDCOLORDRAWABLE_P_H
#define QQMLANDROIDCOLORDRAWABLE_P_H

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

#include <QtQmlAndroid/private/qqmlandroiddrawable_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidColorDrawable : public QQmlAndroidDrawable
{
    Q_OBJECT
    Q_PROPERTY(int color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit QQmlAndroidColorDrawable(QObject *parent = 0);
    explicit QQmlAndroidColorDrawable(int color, QObject *parent = 0);

    int color() const;
    void setColor(int color);

Q_SIGNALS:
    void colorChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    int m_color;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCOLORDRAWABLE_P_H
