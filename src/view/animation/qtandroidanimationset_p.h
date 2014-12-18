#ifndef QTANDROIDANIMATIONSET_P_H
#define QTANDROIDANIMATIONSET_P_H

#include "qtandroidanimation_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAnimationSet : public QtAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(bool shareInterpolator READ shareInterpolator WRITE setShareInterpolator NOTIFY shareInterpolatorChanged)

public:
    explicit QtAndroidAnimationSet(QObject *parent = 0);

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

#endif // QTANDROIDANIMATIONSET_P_H
