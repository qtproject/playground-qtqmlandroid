#include "qtandroidlinearlayout_p.h"

QtAndroidLinearLayout::QtAndroidLinearLayout(QtAndroidView *parent) : QtAndroidViewGroup(parent)
{
}

QtAndroidLinearLayoutParams *QtAndroidLinearLayout::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidLinearLayoutParams(view);
    return 0;
}

bool QtAndroidLinearLayout::isBaselineAligned() const
{
    if (m_baselineAligned.isNull())
        return true;
    return m_baselineAligned.value();
}

void QtAndroidLinearLayout::setBaselineAligned(bool aligned)
{
    if (aligned != isBaselineAligned()) {
        m_baselineAligned = aligned;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAligned", "(Z)V", aligned);
        emit baselineAlignedChanged();
    }
}

int QtAndroidLinearLayout::baselineAlignedChildIndex() const
{
    if (m_baselineAlignedChildIndex.isNull())
        return -1;
    return m_baselineAlignedChildIndex.value();
}

void QtAndroidLinearLayout::setBaselineAlignedChildIndex(int index)
{
    if (index != baselineAlignedChildIndex()) {
        m_baselineAlignedChildIndex = index;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAlignedChildIndex", "(I)V", index);
        emit baselineAlignedChildIndexChanged();
    }
}

bool QtAndroidLinearLayout::isMeasureWithLargestChildEnabled() const
{
    if (m_measureWithLargestChild.isNull())
        return false;
    return m_measureWithLargestChild.value();
}

void QtAndroidLinearLayout::setMeasureWithLargestChildEnabled(bool enabled)
{
    if (enabled != isMeasureWithLargestChildEnabled()) {
        m_measureWithLargestChild = enabled;
//        if (isValid())
//            jniObject().callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", enabled);
        emit measureWithLargestChildEnabledChanged();
    }
}

QtAndroidLinearLayout::Orientation QtAndroidLinearLayout::orientation() const
{
    if (m_orientation.isNull())
        return HORIZONTAL;
    return m_orientation.value();
}

void QtAndroidLinearLayout::setOrientation(Orientation value)
{
    if (value != orientation()) {
        m_orientation = value;
//        if (isValid())
//            jniObject().callMethod<void>("setOrientation", "(I)V", value);
        emit orientationChanged();
    }
}

qreal QtAndroidLinearLayout::weightSum() const
{
    if (m_weightSum.isNull())
        return -1.0f;
    return m_weightSum.value();
}

void QtAndroidLinearLayout::setWeightSum(qreal sum)
{
    if (sum != weightSum()) {
        m_weightSum = sum;
//        if (isValid())
//            jniObject().callMethod<void>("setWeightSum", "(J)V", sum);
        emit weightSumChanged();
    }
}

QAndroidJniObject QtAndroidLinearLayout::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidLinearLayout::onInflate()
{
    QAndroidJniObject layout = instance();
    if (layout.isValid()) {
        if (!m_baselineAligned.isNull())
            layout.callMethod<void>("setBaselineAligned", "(Z)V", m_baselineAligned.value());
        if (!m_measureWithLargestChild.isNull())
            layout.callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", m_measureWithLargestChild.value());
        if (!m_orientation.isNull())
            layout.callMethod<void>("setOrientation", "(I)V", m_orientation.value());
        if (!m_weightSum.isNull())
            layout.callMethod<void>("setWeightSum", "(J)V", m_weightSum.value());
    }

    QtAndroidViewGroup::onInflate();

    if (layout.isValid()) {
        if (!m_baselineAlignedChildIndex.isNull())
            layout.callMethod<void>("setBaselineAlignedChildIndex", "(I)V", m_baselineAlignedChildIndex.value());
    }
}
