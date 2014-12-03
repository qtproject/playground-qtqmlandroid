#ifndef QTDROIDABSSEEKBAR_P_H
#define QTDROIDABSSEEKBAR_P_H

#include "qtdroidprogressbar_p.h"

QT_BEGIN_NAMESPACE

class QtDroidAbsSeekBar : public QtDroidProgressBar
{
    Q_OBJECT

public:
    explicit QtDroidAbsSeekBar(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDABSSEEKBAR_P_H
