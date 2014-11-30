#include "qtdroidlinearlayout_p.h"

QtDroidLinearLayout::QtDroidLinearLayout(QObject *parent) : QtDroidViewGroup(parent)
{
}

QtDroidLinearLayoutParams *QtDroidLinearLayout::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidLinearLayoutParams(view);
    return 0;
}

bool QtDroidLinearLayout::isBaselineAligned() const
{
    if (m_baselineAligned.isNull())
        return true;
    return m_baselineAligned.value();
}

void QtDroidLinearLayout::setBaselineAligned(bool aligned)
{
    if (aligned != isBaselineAligned()) {
        m_baselineAligned = aligned;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAligned", "(Z)V", aligned);
        emit baselineAlignedChanged();
    }
}

int QtDroidLinearLayout::baselineAlignedChildIndex() const
{
    if (m_baselineAlignedChildIndex.isNull())
        return -1;
    return m_baselineAlignedChildIndex.value();
}

void QtDroidLinearLayout::setBaselineAlignedChildIndex(int index)
{
    if (index != baselineAlignedChildIndex()) {
        m_baselineAlignedChildIndex = index;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAlignedChildIndex", "(I)V", index);
        emit baselineAlignedChildIndexChanged();
    }
}

bool QtDroidLinearLayout::isMeasureWithLargestChildEnabled() const
{
    if (m_measureWithLargestChild.isNull())
        return false;
    return m_measureWithLargestChild.value();
}

void QtDroidLinearLayout::setMeasureWithLargestChildEnabled(bool enabled)
{
    if (enabled != isMeasureWithLargestChildEnabled()) {
        m_measureWithLargestChild = enabled;
//        if (isValid())
//            jniObject().callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", enabled);
        emit measureWithLargestChildEnabledChanged();
    }
}

QtDroidLinearLayout::Orientation QtDroidLinearLayout::orientation() const
{
    if (m_orientation.isNull())
        return HORIZONTAL;
    return m_orientation.value();
}

void QtDroidLinearLayout::setOrientation(Orientation value)
{
    if (value != orientation()) {
        m_orientation = value;
//        if (isValid())
//            jniObject().callMethod<void>("setOrientation", "(I)V", value);
        emit orientationChanged();
    }
}

qreal QtDroidLinearLayout::weightSum() const
{
    if (m_weightSum.isNull())
        return -1.0f;
    return m_weightSum.value();
}

void QtDroidLinearLayout::setWeightSum(qreal sum)
{
    if (sum != weightSum()) {
        m_weightSum = sum;
//        if (isValid())
//            jniObject().callMethod<void>("setWeightSum", "(J)V", sum);
        emit weightSumChanged();
    }
}

QAndroidJniObject QtDroidLinearLayout::construct(jobject context)
{
    return QAndroidJniObject("android/widget/LinearLayout",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidLinearLayout::inflate(jobject context)
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

    QtDroidViewGroup::inflate(context);

    if (layout.isValid()) {
        if (!m_baselineAlignedChildIndex.isNull())
            layout.callMethod<void>("setBaselineAlignedChildIndex", "(I)V", m_baselineAlignedChildIndex.value());
    }
}
