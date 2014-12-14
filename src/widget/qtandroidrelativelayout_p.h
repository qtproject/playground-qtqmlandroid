#ifndef QTANDROIDRELATIVELAYOUT_P_H
#define QTANDROIDRELATIVELAYOUT_P_H

#include "qtandroidviewgroup_p.h"
#include "qtandroidrelativelayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRelativeLayout : public QtAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QtAndroidRelativeLayout(QtAndroidView *parent = 0);

    static QtAndroidRelativeLayoutParams *qmlAttachedProperties(QObject *object);

    enum Verb {
        LEFT_OF                  = 0,
        RIGHT_OF                 = 1,
        ABOVE                    = 2,
        BELOW                    = 3,
        ALIGN_BASELINE           = 4,
        ALIGN_LEFT               = 5,
        ALIGN_TOP                = 6,
        ALIGN_RIGHT              = 7,
        ALIGN_BOTTOM             = 8,
        ALIGN_PARENT_LEFT        = 9,
        ALIGN_PARENT_TOP         = 10,
        ALIGN_PARENT_RIGHT       = 11,
        ALIGN_PARENT_BOTTOM      = 12,
        CENTER_IN_PARENT         = 13,
        CENTER_HORIZONTAL        = 14,
        CENTER_VERTICAL          = 15,
        START_OF                 = 16,
        END_OF                   = 17,
        ALIGN_START              = 18,
        ALIGN_END                = 19,
        ALIGN_PARENT_START       = 20,
        ALIGN_PARENT_END         = 21
    };

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtAndroidRelativeLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTANDROIDRELATIVELAYOUT_P_H
