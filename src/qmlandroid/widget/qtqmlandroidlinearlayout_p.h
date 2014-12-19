#ifndef QQMLANDROIDLINEARLAYOUT_P_H
#define QQMLANDROIDLINEARLAYOUT_P_H

#include "qtqmlandroidviewgroup_p.h"
#include "qtqmlandroidoptional_p.h"
#include "qtqmlandroidlinearlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidLinearLayout : public QQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(bool baselineAligned READ isBaselineAligned WRITE setBaselineAligned NOTIFY baselineAlignedChanged)
    Q_PROPERTY(int baselineAlignedChildIndex READ baselineAlignedChildIndex WRITE setBaselineAlignedChildIndex NOTIFY baselineAlignedChildIndexChanged)
    Q_PROPERTY(bool measureWithLargestChildEnabled READ isMeasureWithLargestChildEnabled WRITE setMeasureWithLargestChildEnabled NOTIFY measureWithLargestChildEnabledChanged)
    Q_PROPERTY(Orientation orientation READ orientation WRITE setOrientation NOTIFY orientationChanged)
    Q_PROPERTY(qreal weightSum READ weightSum WRITE setWeightSum NOTIFY weightSumChanged)
    Q_ENUMS(Orientation)

public:
    explicit QQmlAndroidLinearLayout(QQmlAndroidView *parent = 0);

    static QQmlAndroidLinearLayoutParams *qmlAttachedProperties(QObject *object);

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
    QQmlAndroidOptional<bool> m_baselineAligned;
    QQmlAndroidOptional<bool> m_baselineAlignedChildIndex;
    // TODO: Drawable divider
    // TODO: int gravity
    QQmlAndroidOptional<bool> m_measureWithLargestChild;
    QQmlAndroidOptional<Orientation> m_orientation;
    QQmlAndroidOptional<qreal> m_weightSum;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QQmlAndroidLinearLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QQMLANDROIDLINEARLAYOUT_P_H
