#ifndef QTQMLANDROIDLINEARLAYOUT_P_H
#define QTQMLANDROIDLINEARLAYOUT_P_H

#include "qtqmlandroidviewgroup_p.h"
#include "qtqmlandroidoptional_p.h"
#include "qtqmlandroidlinearlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidLinearLayout : public QtQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(bool baselineAligned READ isBaselineAligned WRITE setBaselineAligned NOTIFY baselineAlignedChanged)
    Q_PROPERTY(int baselineAlignedChildIndex READ baselineAlignedChildIndex WRITE setBaselineAlignedChildIndex NOTIFY baselineAlignedChildIndexChanged)
    Q_PROPERTY(bool measureWithLargestChildEnabled READ isMeasureWithLargestChildEnabled WRITE setMeasureWithLargestChildEnabled NOTIFY measureWithLargestChildEnabledChanged)
    Q_PROPERTY(Orientation orientation READ orientation WRITE setOrientation NOTIFY orientationChanged)
    Q_PROPERTY(qreal weightSum READ weightSum WRITE setWeightSum NOTIFY weightSumChanged)
    Q_ENUMS(Orientation)

public:
    explicit QtQmlAndroidLinearLayout(QtQmlAndroidView *parent = 0);

    static QtQmlAndroidLinearLayoutParams *qmlAttachedProperties(QObject *object);

    enum Orientation {
        HORIZONTAL = 0,
        VERTICAL = 1
    };

    bool isBaselineAligned() const;
    void setBaselineAligned(bool aligned);

    int baselineAlignedChildIndex() const;
    void setBaselineAlignedChildIndex(int index);

    // TODO: Drawable divider
    // TODO: int gravity

    bool isMeasureWithLargestChildEnabled() const;
    void setMeasureWithLargestChildEnabled(bool enabled);

    Orientation orientation() const;
    void setOrientation(Orientation orientation);

    qreal weightSum() const;
    void setWeightSum(qreal sum);

Q_SIGNALS:
    void baselineAlignedChanged();
    void baselineAlignedChildIndexChanged();
    void measureWithLargestChildEnabledChanged();
    void orientationChanged();
    void weightSumChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtQmlAndroidOptional<bool> m_baselineAligned;
    QtQmlAndroidOptional<bool> m_baselineAlignedChildIndex;
    // TODO: Drawable divider
    // TODO: int gravity
    QtQmlAndroidOptional<bool> m_measureWithLargestChild;
    QtQmlAndroidOptional<Orientation> m_orientation;
    QtQmlAndroidOptional<qreal> m_weightSum;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtQmlAndroidLinearLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTQMLANDROIDLINEARLAYOUT_P_H
