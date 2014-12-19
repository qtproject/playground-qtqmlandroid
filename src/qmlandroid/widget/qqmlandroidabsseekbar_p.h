#ifndef QQMLANDROIDABSSEEKBAR_P_H
#define QQMLANDROIDABSSEEKBAR_P_H

#include "qqmlandroidprogressbar_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidAbsSeekBar : public QQmlAndroidProgressBar
{
    Q_OBJECT

public:
    explicit QQmlAndroidAbsSeekBar(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDABSSEEKBAR_P_H
