#ifndef QTQMLANDROIDABSSEEKBAR_P_H
#define QTQMLANDROIDABSSEEKBAR_P_H

#include "qtqmlandroidprogressbar_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidAbsSeekBar : public QtQmlAndroidProgressBar
{
    Q_OBJECT

public:
    explicit QtQmlAndroidAbsSeekBar(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDABSSEEKBAR_P_H
