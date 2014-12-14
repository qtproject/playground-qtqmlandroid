#include "qtandroidrelativelayoutparams_p.h"
#include "qtandroidrelativelayout_p.h"
#include "qtandroidview_p.h"

QtAndroidRelativeLayoutParams::QtAndroidRelativeLayoutParams(QtAndroidView *view) : QtAndroidMarginLayoutParams(view),
    m_above(0),
    m_below(0),
    m_alignTop(0),
    m_alignLeft(0),
    m_alignRight(0),
    m_alignBottom(0),
    m_alignStart(0),
    m_alignEnd(0),
    m_alignBaseline(0),
    m_toLeftOf(0),
    m_toRightOf(0),
    m_toStartOf(0),
    m_toEndOf(0),
    m_alignParentTop(false),
    m_alignParentLeft(false),
    m_alignParentRight(false),
    m_alignParentBottom(false),
    m_alignParentStart(false),
    m_alignParentEnd(false),
    m_alignWithParent(false),
    m_centerHorizontal(false),
    m_centerVertical(false),
    m_centerInParent(false)
{
}

QtAndroidView *QtAndroidRelativeLayoutParams::above() const
{
    return m_above;
}

void QtAndroidRelativeLayoutParams::setAbove(QtAndroidView *view)
{
    if (view != m_above) {
        m_above = view;
        emit aboveChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::below() const
{
    return m_below;
}

void QtAndroidRelativeLayoutParams::setBelow(QtAndroidView *view)
{
    if (view != m_below) {
        m_below = view;
        emit belowChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::alignTop() const
{
    return m_alignTop;
}

void QtAndroidRelativeLayoutParams::setAlignTop(QtAndroidView *view)
{
    if (view != m_alignTop) {
        m_alignTop = view;
        emit alignTopChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::alignLeft() const
{
    return m_alignLeft;
}

void QtAndroidRelativeLayoutParams::setAlignLeft(QtAndroidView *view)
{
    if (view != m_alignLeft) {
        m_alignLeft = view;
        emit alignLeftChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::alignRight() const
{
    return m_alignRight;
}

void QtAndroidRelativeLayoutParams::setAlignRight(QtAndroidView *view)
{
    if (view != m_alignRight) {
        m_alignRight = view;
        emit alignRightChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::alignBottom() const
{
    return m_alignBottom;
}

void QtAndroidRelativeLayoutParams::setAlignBottom(QtAndroidView *view)
{
    if (view != m_alignBottom) {
        m_alignBottom = view;
        emit alignBottomChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::alignStart() const
{
    return m_alignStart;
}

void QtAndroidRelativeLayoutParams::setAlignStart(QtAndroidView *view)
{
    if (view != m_alignStart) {
        m_alignStart = view;
        emit alignStartChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::alignEnd() const
{
    return m_alignEnd;
}

void QtAndroidRelativeLayoutParams::setAlignEnd(QtAndroidView *view)
{
    if (view != m_alignEnd) {
        m_alignEnd = view;
        emit alignEndChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::alignBaseline() const
{
    return m_alignBaseline;
}

void QtAndroidRelativeLayoutParams::setAlignBaseline(QtAndroidView *view)
{
    if (view != m_alignBaseline) {
        m_alignBaseline = view;
        emit alignBaselineChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::toLeftOf() const
{
    return m_toLeftOf;
}

void QtAndroidRelativeLayoutParams::setToLeftOf(QtAndroidView *view)
{
    if (view != m_toLeftOf) {
        m_toLeftOf = view;
        emit toLeftOfChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::toRightOf() const
{
    return m_toRightOf;
}

void QtAndroidRelativeLayoutParams::setToRightOf(QtAndroidView *view)
{
    if (view != m_toRightOf) {
        m_toRightOf = view;
        emit toRightOfChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::toStartOf() const
{
    return m_toStartOf;
}

void QtAndroidRelativeLayoutParams::setToStartOf(QtAndroidView *view)
{
    if (view != m_toStartOf) {
        m_toStartOf = view;
        emit toStartOfChanged();
    }
}

QtAndroidView *QtAndroidRelativeLayoutParams::toEndOf() const
{
    return m_toEndOf;
}

void QtAndroidRelativeLayoutParams::setToEndOf(QtAndroidView *view)
{
    if (view != m_toEndOf) {
        m_toEndOf = view;
        emit toEndOfChanged();
    }
}

bool QtAndroidRelativeLayoutParams::alignParentTop() const
{
    return m_alignParentTop;
}

void QtAndroidRelativeLayoutParams::setAlignParentTop(bool align)
{
    if (align != alignParentTop()) {
        m_alignParentTop = align;
        emit alignParentTopChanged();
    }
}

bool QtAndroidRelativeLayoutParams::alignParentLeft() const
{
    return m_alignParentLeft;
}

void QtAndroidRelativeLayoutParams::setAlignParentLeft(bool align)
{
    if (align != alignParentLeft()) {
        m_alignParentLeft = align;
        emit alignParentLeftChanged();
    }
}

bool QtAndroidRelativeLayoutParams::alignParentRight() const
{
    return m_alignParentRight;
}

void QtAndroidRelativeLayoutParams::setAlignParentRight(bool align)
{
    if (align != alignParentRight()) {
        m_alignParentRight = align;
        emit alignParentRightChanged();
    }
}

bool QtAndroidRelativeLayoutParams::alignParentBottom() const
{
    return m_alignParentBottom;
}

void QtAndroidRelativeLayoutParams::setAlignParentBottom(bool align)
{
    if (align != alignParentBottom()) {
        m_alignParentBottom = align;
        emit alignParentBottomChanged();
    }
}

bool QtAndroidRelativeLayoutParams::alignParentStart() const
{
    return m_alignParentStart;
}

void QtAndroidRelativeLayoutParams::setAlignParentStart(bool align)
{
    if (align != alignParentStart()) {
        m_alignParentStart = align;
        emit alignParentStartChanged();
    }
}

bool QtAndroidRelativeLayoutParams::alignParentEnd() const
{
    return m_alignParentEnd;
}

void QtAndroidRelativeLayoutParams::setAlignParentEnd(bool align)
{
    if (align != alignParentEnd()) {
        m_alignParentEnd = align;
        emit alignParentEndChanged();
    }
}

bool QtAndroidRelativeLayoutParams::alignWithParent() const
{
    return m_alignWithParent;
}

void QtAndroidRelativeLayoutParams::setAlignWithParent(bool align)
{
    if (align != alignWithParent()) {
        m_alignWithParent = align;
        emit alignWithParentChanged();
    }
}

bool QtAndroidRelativeLayoutParams::centerHorizontal() const
{
    return m_centerHorizontal;
}

void QtAndroidRelativeLayoutParams::setCenterHorizontal(bool center)
{
    if (center != centerHorizontal()) {
        m_centerHorizontal = center;
        emit centerHorizontalChanged();
    }
}

bool QtAndroidRelativeLayoutParams::centerVertical() const
{
    return m_centerVertical;
}

void QtAndroidRelativeLayoutParams::setCenterVertical(bool center)
{
    if (center != centerVertical()) {
        m_centerVertical = center;
        emit centerVerticalChanged();
    }
}

bool QtAndroidRelativeLayoutParams::centerInParent() const
{
    return m_centerInParent;
}

void QtAndroidRelativeLayoutParams::setCenterInParent(bool center)
{
    if (center != centerInParent()) {
        m_centerInParent = center;
        emit centerInParentChanged();
    }
}

QAndroidJniObject QtAndroidRelativeLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/RelativeLayout$LayoutParams",
                             "(II)V",
                             WRAP_CONTENT, WRAP_CONTENT);
}

static void addRule(QAndroidJniObject& instance, QtAndroidView *view, QtAndroidRelativeLayout::Verb verb)
{
    if (view) {
        int anchor = view->instance().callMethod<jint>("getId");
        instance.callMethod<void>("addRule", "(II)V", verb, anchor);
    }
}

static void addRule(QAndroidJniObject &instance, bool value, QtAndroidRelativeLayout::Verb verb)
{
    if (value)
        instance.callMethod<void>("addRule", "(I)V", verb);
}

void QtAndroidRelativeLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<jboolean>("alignWithParent", m_alignWithParent);

    addRule(instance, m_above, QtAndroidRelativeLayout::ABOVE);
    addRule(instance, m_below, QtAndroidRelativeLayout::BELOW);
    addRule(instance, m_alignTop, QtAndroidRelativeLayout::ALIGN_TOP);
    addRule(instance, m_alignLeft, QtAndroidRelativeLayout::ALIGN_LEFT);
    addRule(instance, m_alignRight, QtAndroidRelativeLayout::ALIGN_RIGHT);
    addRule(instance, m_alignBottom, QtAndroidRelativeLayout::ALIGN_BOTTOM);
    addRule(instance, m_alignStart, QtAndroidRelativeLayout::ALIGN_START);
    addRule(instance, m_alignEnd, QtAndroidRelativeLayout::ALIGN_END);
    addRule(instance, m_alignBaseline, QtAndroidRelativeLayout::ALIGN_BASELINE);
    addRule(instance, m_toLeftOf, QtAndroidRelativeLayout::LEFT_OF);
    addRule(instance, m_toRightOf, QtAndroidRelativeLayout::RIGHT_OF);
    addRule(instance, m_toStartOf, QtAndroidRelativeLayout::START_OF);
    addRule(instance, m_toEndOf, QtAndroidRelativeLayout::END_OF);

    addRule(instance, m_alignParentTop, QtAndroidRelativeLayout::ALIGN_PARENT_TOP);
    addRule(instance, m_alignParentLeft, QtAndroidRelativeLayout::ALIGN_PARENT_LEFT);
    addRule(instance, m_alignParentRight, QtAndroidRelativeLayout::ALIGN_PARENT_RIGHT);
    addRule(instance, m_alignParentBottom, QtAndroidRelativeLayout::ALIGN_PARENT_BOTTOM);
    addRule(instance, m_alignParentStart, QtAndroidRelativeLayout::ALIGN_PARENT_START);
    addRule(instance, m_alignParentEnd, QtAndroidRelativeLayout::ALIGN_PARENT_END);
    addRule(instance, m_centerHorizontal, QtAndroidRelativeLayout::CENTER_HORIZONTAL);
    addRule(instance, m_centerVertical, QtAndroidRelativeLayout::CENTER_VERTICAL);
    addRule(instance, m_centerInParent, QtAndroidRelativeLayout::CENTER_IN_PARENT);
}
