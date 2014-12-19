#ifndef QTQMLANDROIDANIMATIONSET_P_H
#define QTQMLANDROIDANIMATIONSET_P_H

#include "qtqmlandroidanimation_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidAnimationSet : public QtQmlAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(bool shareInterpolator READ shareInterpolator WRITE setShareInterpolator NOTIFY shareInterpolatorChanged)

public:
    explicit QtQmlAndroidAnimationSet(QObject *parent = 0);

    bool shareInterpolator() const;
    void setShareInterpolator(bool share);

Q_SIGNALS:
    void shareInterpolatorChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    bool m_shareInterpolator;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDANIMATIONSET_P_H
