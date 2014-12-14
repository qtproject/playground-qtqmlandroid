#ifndef QTANDROIDABSSEEKBAR_P_H
#define QTANDROIDABSSEEKBAR_P_H

#include "qtandroidprogressbar_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAbsSeekBar : public QtAndroidProgressBar
{
    Q_OBJECT

public:
    explicit QtAndroidAbsSeekBar(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDABSSEEKBAR_P_H
