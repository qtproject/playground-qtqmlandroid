#include "qtqmlandroidrelativelayoutparams_p.h"
#include "qtqmlandroidrelativelayout_p.h"
#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidRelativeLayoutParams::QtQmlAndroidRelativeLayoutParams(QtQmlAndroidView *view) :
    QtQmlAndroidMarginLayoutParams(view),
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

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::above() const
{
    return m_above;
}

void QtQmlAndroidRelativeLayoutParams::setAbove(QtQmlAndroidView *view)
{
    if (view != m_above) {
        m_above = view;
        invalidate();
        emit aboveChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::below() const
{
    return m_below;
}

void QtQmlAndroidRelativeLayoutParams::setBelow(QtQmlAndroidView *view)
{
    if (view != m_below) {
        m_below = view;
        invalidate();
        emit belowChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::alignTop() const
{
    return m_alignTop;
}

void QtQmlAndroidRelativeLayoutParams::setAlignTop(QtQmlAndroidView *view)
{
    if (view != m_alignTop) {
        m_alignTop = view;
        invalidate();
        emit alignTopChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::alignLeft() const
{
    return m_alignLeft;
}

void QtQmlAndroidRelativeLayoutParams::setAlignLeft(QtQmlAndroidView *view)
{
    if (view != m_alignLeft) {
        m_alignLeft = view;
        invalidate();
        emit alignLeftChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::alignRight() const
{
    return m_alignRight;
}

void QtQmlAndroidRelativeLayoutParams::setAlignRight(QtQmlAndroidView *view)
{
    if (view != m_alignRight) {
        m_alignRight = view;
        invalidate();
        emit alignRightChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::alignBottom() const
{
    return m_alignBottom;
}

void QtQmlAndroidRelativeLayoutParams::setAlignBottom(QtQmlAndroidView *view)
{
    if (view != m_alignBottom) {
        m_alignBottom = view;
        invalidate();
        emit alignBottomChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::alignStart() const
{
    return m_alignStart;
}

void QtQmlAndroidRelativeLayoutParams::setAlignStart(QtQmlAndroidView *view)
{
    if (view != m_alignStart) {
        m_alignStart = view;
        invalidate();
        emit alignStartChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::alignEnd() const
{
    return m_alignEnd;
}

void QtQmlAndroidRelativeLayoutParams::setAlignEnd(QtQmlAndroidView *view)
{
    if (view != m_alignEnd) {
        m_alignEnd = view;
        invalidate();
        emit alignEndChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::alignBaseline() const
{
    return m_alignBaseline;
}

void QtQmlAndroidRelativeLayoutParams::setAlignBaseline(QtQmlAndroidView *view)
{
    if (view != m_alignBaseline) {
        m_alignBaseline = view;
        invalidate();
        emit alignBaselineChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::toLeftOf() const
{
    return m_toLeftOf;
}

void QtQmlAndroidRelativeLayoutParams::setToLeftOf(QtQmlAndroidView *view)
{
    if (view != m_toLeftOf) {
        m_toLeftOf = view;
        invalidate();
        emit toLeftOfChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::toRightOf() const
{
    return m_toRightOf;
}

void QtQmlAndroidRelativeLayoutParams::setToRightOf(QtQmlAndroidView *view)
{
    if (view != m_toRightOf) {
        m_toRightOf = view;
        invalidate();
        emit toRightOfChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::toStartOf() const
{
    return m_toStartOf;
}

void QtQmlAndroidRelativeLayoutParams::setToStartOf(QtQmlAndroidView *view)
{
    if (view != m_toStartOf) {
        m_toStartOf = view;
        invalidate();
        emit toStartOfChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidRelativeLayoutParams::toEndOf() const
{
    return m_toEndOf;
}

void QtQmlAndroidRelativeLayoutParams::setToEndOf(QtQmlAndroidView *view)
{
    if (view != m_toEndOf) {
        m_toEndOf = view;
        invalidate();
        emit toEndOfChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::alignParentTop() const
{
    return m_alignParentTop;
}

void QtQmlAndroidRelativeLayoutParams::setAlignParentTop(bool align)
{
    if (align != alignParentTop()) {
        m_alignParentTop = align;
        invalidate();
        emit alignParentTopChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::alignParentLeft() const
{
    return m_alignParentLeft;
}

void QtQmlAndroidRelativeLayoutParams::setAlignParentLeft(bool align)
{
    if (align != alignParentLeft()) {
        m_alignParentLeft = align;
        invalidate();
        emit alignParentLeftChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::alignParentRight() const
{
    return m_alignParentRight;
}

void QtQmlAndroidRelativeLayoutParams::setAlignParentRight(bool align)
{
    if (align != alignParentRight()) {
        m_alignParentRight = align;
        invalidate();
        emit alignParentRightChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::alignParentBottom() const
{
    return m_alignParentBottom;
}

void QtQmlAndroidRelativeLayoutParams::setAlignParentBottom(bool align)
{
    if (align != alignParentBottom()) {
        m_alignParentBottom = align;
        invalidate();
        emit alignParentBottomChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::alignParentStart() const
{
    return m_alignParentStart;
}

void QtQmlAndroidRelativeLayoutParams::setAlignParentStart(bool align)
{
    if (align != alignParentStart()) {
        m_alignParentStart = align;
        invalidate();
        emit alignParentStartChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::alignParentEnd() const
{
    return m_alignParentEnd;
}

void QtQmlAndroidRelativeLayoutParams::setAlignParentEnd(bool align)
{
    if (align != alignParentEnd()) {
        m_alignParentEnd = align;
        invalidate();
        emit alignParentEndChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::alignWithParent() const
{
    return m_alignWithParent;
}

void QtQmlAndroidRelativeLayoutParams::setAlignWithParent(bool align)
{
    if (align != alignWithParent()) {
        m_alignWithParent = align;
        invalidate();
        emit alignWithParentChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::centerHorizontal() const
{
    return m_centerHorizontal;
}

void QtQmlAndroidRelativeLayoutParams::setCenterHorizontal(bool center)
{
    if (center != centerHorizontal()) {
        m_centerHorizontal = center;
        invalidate();
        emit centerHorizontalChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::centerVertical() const
{
    return m_centerVertical;
}

void QtQmlAndroidRelativeLayoutParams::setCenterVertical(bool center)
{
    if (center != centerVertical()) {
        m_centerVertical = center;
        invalidate();
        emit centerVerticalChanged();
    }
}

bool QtQmlAndroidRelativeLayoutParams::centerInParent() const
{
    return m_centerInParent;
}

void QtQmlAndroidRelativeLayoutParams::setCenterInParent(bool center)
{
    if (center != centerInParent()) {
        m_centerInParent = center;
        invalidate();
        emit centerInParentChanged();
    }
}

QAndroidJniObject QtQmlAndroidRelativeLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/RelativeLayout$LayoutParams",
                             "(II)V",
                             WRAP_CONTENT, WRAP_CONTENT);
}

static void addRule(QAndroidJniObject& instance, QtQmlAndroidView *view, QtQmlAndroidRelativeLayout::Verb verb)
{
    if (view) {
        int anchor = view->instance().callMethod<jint>("getId");
        instance.callMethod<void>("addRule", "(II)V", verb, anchor);
    }
}

static void addRule(QAndroidJniObject &instance, bool value, QtQmlAndroidRelativeLayout::Verb verb)
{
    if (value)
        instance.callMethod<void>("addRule", "(I)V", verb);
}

void QtQmlAndroidRelativeLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<jboolean>("alignWithParent", m_alignWithParent);

    addRule(instance, m_above, QtQmlAndroidRelativeLayout::ABOVE);
    addRule(instance, m_below, QtQmlAndroidRelativeLayout::BELOW);
    addRule(instance, m_alignTop, QtQmlAndroidRelativeLayout::ALIGN_TOP);
    addRule(instance, m_alignLeft, QtQmlAndroidRelativeLayout::ALIGN_LEFT);
    addRule(instance, m_alignRight, QtQmlAndroidRelativeLayout::ALIGN_RIGHT);
    addRule(instance, m_alignBottom, QtQmlAndroidRelativeLayout::ALIGN_BOTTOM);
    addRule(instance, m_alignStart, QtQmlAndroidRelativeLayout::ALIGN_START);
    addRule(instance, m_alignEnd, QtQmlAndroidRelativeLayout::ALIGN_END);
    addRule(instance, m_alignBaseline, QtQmlAndroidRelativeLayout::ALIGN_BASELINE);
    addRule(instance, m_toLeftOf, QtQmlAndroidRelativeLayout::LEFT_OF);
    addRule(instance, m_toRightOf, QtQmlAndroidRelativeLayout::RIGHT_OF);
    addRule(instance, m_toStartOf, QtQmlAndroidRelativeLayout::START_OF);
    addRule(instance, m_toEndOf, QtQmlAndroidRelativeLayout::END_OF);

    addRule(instance, m_alignParentTop, QtQmlAndroidRelativeLayout::ALIGN_PARENT_TOP);
    addRule(instance, m_alignParentLeft, QtQmlAndroidRelativeLayout::ALIGN_PARENT_LEFT);
    addRule(instance, m_alignParentRight, QtQmlAndroidRelativeLayout::ALIGN_PARENT_RIGHT);
    addRule(instance, m_alignParentBottom, QtQmlAndroidRelativeLayout::ALIGN_PARENT_BOTTOM);
    addRule(instance, m_alignParentStart, QtQmlAndroidRelativeLayout::ALIGN_PARENT_START);
    addRule(instance, m_alignParentEnd, QtQmlAndroidRelativeLayout::ALIGN_PARENT_END);
    addRule(instance, m_centerHorizontal, QtQmlAndroidRelativeLayout::CENTER_HORIZONTAL);
    addRule(instance, m_centerVertical, QtQmlAndroidRelativeLayout::CENTER_VERTICAL);
    addRule(instance, m_centerInParent, QtQmlAndroidRelativeLayout::CENTER_IN_PARENT);
}

QT_END_NAMESPACE
