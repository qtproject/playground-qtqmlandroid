#include "qtqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidLinearLayout::QtQmlAndroidLinearLayout(QtQmlAndroidView *parent) :
    QtQmlAndroidViewGroup(parent)
{
}

QtQmlAndroidLinearLayoutParams *QtQmlAndroidLinearLayout::qmlAttachedProperties(QObject *object)
{
    QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView*>(object);
    if (view)
        return new QtQmlAndroidLinearLayoutParams(view);
    return 0;
}

bool QtQmlAndroidLinearLayout::isBaselineAligned() const
{
    if (m_baselineAligned.isNull())
        return true;
    return m_baselineAligned.value();
}

void QtQmlAndroidLinearLayout::setBaselineAligned(bool aligned)
{
    if (aligned != isBaselineAligned()) {
        m_baselineAligned = aligned;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAligned", "(Z)V", aligned);
        emit baselineAlignedChanged();
    }
}

int QtQmlAndroidLinearLayout::baselineAlignedChildIndex() const
{
    if (m_baselineAlignedChildIndex.isNull())
        return -1;
    return m_baselineAlignedChildIndex.value();
}

void QtQmlAndroidLinearLayout::setBaselineAlignedChildIndex(int index)
{
    if (index != baselineAlignedChildIndex()) {
        m_baselineAlignedChildIndex = index;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAlignedChildIndex", "(I)V", index);
        emit baselineAlignedChildIndexChanged();
    }
}

bool QtQmlAndroidLinearLayout::isMeasureWithLargestChildEnabled() const
{
    if (m_measureWithLargestChild.isNull())
        return false;
    return m_measureWithLargestChild.value();
}

void QtQmlAndroidLinearLayout::setMeasureWithLargestChildEnabled(bool enabled)
{
    if (enabled != isMeasureWithLargestChildEnabled()) {
        m_measureWithLargestChild = enabled;
//        if (isValid())
//            jniObject().callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", enabled);
        emit measureWithLargestChildEnabledChanged();
    }
}

QtQmlAndroidLinearLayout::Orientation QtQmlAndroidLinearLayout::orientation() const
{
    if (m_orientation.isNull())
        return HORIZONTAL;
    return m_orientation.value();
}

void QtQmlAndroidLinearLayout::setOrientation(Orientation value)
{
    if (value != orientation()) {
        m_orientation = value;
//        if (isValid())
//            jniObject().callMethod<void>("setOrientation", "(I)V", value);
        emit orientationChanged();
    }
}

qreal QtQmlAndroidLinearLayout::weightSum() const
{
    if (m_weightSum.isNull())
        return -1.0f;
    return m_weightSum.value();
}

void QtQmlAndroidLinearLayout::setWeightSum(qreal sum)
{
    if (sum != weightSum()) {
        m_weightSum = sum;
//        if (isValid())
//            jniObject().callMethod<void>("setWeightSum", "(J)V", sum);
        emit weightSumChanged();
    }
}

QAndroidJniObject QtQmlAndroidLinearLayout::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidLinearLayout::onInflate(QAndroidJniObject &instance)
{
    if (!m_baselineAligned.isNull())
        instance.callMethod<void>("setBaselineAligned", "(Z)V", m_baselineAligned.value());
    if (!m_measureWithLargestChild.isNull())
        instance.callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", m_measureWithLargestChild.value());
    if (!m_orientation.isNull())
        instance.callMethod<void>("setOrientation", "(I)V", m_orientation.value());
    if (!m_weightSum.isNull())
        instance.callMethod<void>("setWeightSum", "(J)V", m_weightSum.value());

    QtQmlAndroidViewGroup::onInflate(instance);

    if (!m_baselineAlignedChildIndex.isNull())
        instance.callMethod<void>("setBaselineAlignedChildIndex", "(I)V", m_baselineAlignedChildIndex.value());
}

QT_END_NAMESPACE
