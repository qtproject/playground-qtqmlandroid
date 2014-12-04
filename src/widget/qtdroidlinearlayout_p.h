#ifndef QTDROIDLINEARLAYOUT_P_H
#define QTDROIDLINEARLAYOUT_P_H

#include "qtdroidviewgroup_p.h"
#include "qtdroidoptional_p.h"
#include "qtdroidlinearlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidLinearLayout : public QtDroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(bool baselineAligned READ isBaselineAligned WRITE setBaselineAligned NOTIFY baselineAlignedChanged)
    Q_PROPERTY(int baselineAlignedChildIndex READ baselineAlignedChildIndex WRITE setBaselineAlignedChildIndex NOTIFY baselineAlignedChildIndexChanged)
    Q_PROPERTY(bool measureWithLargestChildEnabled READ isMeasureWithLargestChildEnabled WRITE setMeasureWithLargestChildEnabled NOTIFY measureWithLargestChildEnabledChanged)
    Q_PROPERTY(Orientation orientation READ orientation WRITE setOrientation NOTIFY orientationChanged)
    Q_PROPERTY(qreal weightSum READ weightSum WRITE setWeightSum NOTIFY weightSumChanged)
    Q_ENUMS(Orientation)

public:
    explicit QtDroidLinearLayout(QtDroidView *parent = 0);

    static QtDroidLinearLayoutParams *qmlAttachedProperties(QObject *object);

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
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

private:
    QtDroidOptional<bool> m_baselineAligned;
    QtDroidOptional<bool> m_baselineAlignedChildIndex;
    // TODO: Drawable divider
    // TODO: int gravity
    QtDroidOptional<bool> m_measureWithLargestChild;
    QtDroidOptional<Orientation> m_orientation;
    QtDroidOptional<qreal> m_weightSum;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtDroidLinearLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTDROIDLINEARLAYOUT_P_H
