#include "qtdroidrelativelayoutparams_p.h"
#include "qtdroidrelativelayout_p.h"
#include "qtdroidview_p.h"

QtDroidRelativeLayoutParams::QtDroidRelativeLayoutParams(QtDroidView *view) : QtDroidMarginLayoutParams(view),
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

QtDroidView *QtDroidRelativeLayoutParams::above() const
{
    return m_above;
}

void QtDroidRelativeLayoutParams::setAbove(QtDroidView *view)
{
    if (view != m_above) {
        m_above = view;
        emit aboveChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::below() const
{
    return m_below;
}

void QtDroidRelativeLayoutParams::setBelow(QtDroidView *view)
{
    if (view != m_below) {
        m_below = view;
        emit belowChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::alignTop() const
{
    return m_alignTop;
}

void QtDroidRelativeLayoutParams::setAlignTop(QtDroidView *view)
{
    if (view != m_alignTop) {
        m_alignTop = view;
        emit alignTopChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::alignLeft() const
{
    return m_alignLeft;
}

void QtDroidRelativeLayoutParams::setAlignLeft(QtDroidView *view)
{
    if (view != m_alignLeft) {
        m_alignLeft = view;
        emit alignLeftChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::alignRight() const
{
    return m_alignRight;
}

void QtDroidRelativeLayoutParams::setAlignRight(QtDroidView *view)
{
    if (view != m_alignRight) {
        m_alignRight = view;
        emit alignRightChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::alignBottom() const
{
    return m_alignBottom;
}

void QtDroidRelativeLayoutParams::setAlignBottom(QtDroidView *view)
{
    if (view != m_alignBottom) {
        m_alignBottom = view;
        emit alignBottomChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::alignStart() const
{
    return m_alignStart;
}

void QtDroidRelativeLayoutParams::setAlignStart(QtDroidView *view)
{
    if (view != m_alignStart) {
        m_alignStart = view;
        emit alignStartChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::alignEnd() const
{
    return m_alignEnd;
}

void QtDroidRelativeLayoutParams::setAlignEnd(QtDroidView *view)
{
    if (view != m_alignEnd) {
        m_alignEnd = view;
        emit alignEndChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::alignBaseline() const
{
    return m_alignBaseline;
}

void QtDroidRelativeLayoutParams::setAlignBaseline(QtDroidView *view)
{
    if (view != m_alignBaseline) {
        m_alignBaseline = view;
        emit alignBaselineChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::toLeftOf() const
{
    return m_toLeftOf;
}

void QtDroidRelativeLayoutParams::setToLeftOf(QtDroidView *view)
{
    if (view != m_toLeftOf) {
        m_toLeftOf = view;
        emit toLeftOfChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::toRightOf() const
{
    return m_toRightOf;
}

void QtDroidRelativeLayoutParams::setToRightOf(QtDroidView *view)
{
    if (view != m_toRightOf) {
        m_toRightOf = view;
        emit toRightOfChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::toStartOf() const
{
    return m_toStartOf;
}

void QtDroidRelativeLayoutParams::setToStartOf(QtDroidView *view)
{
    if (view != m_toStartOf) {
        m_toStartOf = view;
        emit toStartOfChanged();
    }
}

QtDroidView *QtDroidRelativeLayoutParams::toEndOf() const
{
    return m_toEndOf;
}

void QtDroidRelativeLayoutParams::setToEndOf(QtDroidView *view)
{
    if (view != m_toEndOf) {
        m_toEndOf = view;
        emit toEndOfChanged();
    }
}

bool QtDroidRelativeLayoutParams::alignParentTop() const
{
    return m_alignParentTop;
}

void QtDroidRelativeLayoutParams::setAlignParentTop(bool align)
{
    if (align != alignParentTop()) {
        m_alignParentTop = align;
        emit alignParentTopChanged();
    }
}

bool QtDroidRelativeLayoutParams::alignParentLeft() const
{
    return m_alignParentLeft;
}

void QtDroidRelativeLayoutParams::setAlignParentLeft(bool align)
{
    if (align != alignParentLeft()) {
        m_alignParentLeft = align;
        emit alignParentLeftChanged();
    }
}

bool QtDroidRelativeLayoutParams::alignParentRight() const
{
    return m_alignParentRight;
}

void QtDroidRelativeLayoutParams::setAlignParentRight(bool align)
{
    if (align != alignParentRight()) {
        m_alignParentRight = align;
        emit alignParentRightChanged();
    }
}

bool QtDroidRelativeLayoutParams::alignParentBottom() const
{
    return m_alignParentBottom;
}

void QtDroidRelativeLayoutParams::setAlignParentBottom(bool align)
{
    if (align != alignParentBottom()) {
        m_alignParentBottom = align;
        emit alignParentBottomChanged();
    }
}

bool QtDroidRelativeLayoutParams::alignParentStart() const
{
    return m_alignParentStart;
}

void QtDroidRelativeLayoutParams::setAlignParentStart(bool align)
{
    if (align != alignParentStart()) {
        m_alignParentStart = align;
        emit alignParentStartChanged();
    }
}

bool QtDroidRelativeLayoutParams::alignParentEnd() const
{
    return m_alignParentEnd;
}

void QtDroidRelativeLayoutParams::setAlignParentEnd(bool align)
{
    if (align != alignParentEnd()) {
        m_alignParentEnd = align;
        emit alignParentEndChanged();
    }
}

bool QtDroidRelativeLayoutParams::alignWithParent() const
{
    return m_alignWithParent;
}

void QtDroidRelativeLayoutParams::setAlignWithParent(bool align)
{
    if (align != alignWithParent()) {
        m_alignWithParent = align;
        emit alignWithParentChanged();
    }
}

bool QtDroidRelativeLayoutParams::centerHorizontal() const
{
    return m_centerHorizontal;
}

void QtDroidRelativeLayoutParams::setCenterHorizontal(bool center)
{
    if (center != centerHorizontal()) {
        m_centerHorizontal = center;
        emit centerHorizontalChanged();
    }
}

bool QtDroidRelativeLayoutParams::centerVertical() const
{
    return m_centerVertical;
}

void QtDroidRelativeLayoutParams::setCenterVertical(bool center)
{
    if (center != centerVertical()) {
        m_centerVertical = center;
        emit centerVerticalChanged();
    }
}

bool QtDroidRelativeLayoutParams::centerInParent() const
{
    return m_centerInParent;
}

void QtDroidRelativeLayoutParams::setCenterInParent(bool center)
{
    if (center != centerInParent()) {
        m_centerInParent = center;
        emit centerInParentChanged();
    }
}

QAndroidJniObject QtDroidRelativeLayoutParams::construct()
{
    return QAndroidJniObject("android/widget/RelativeLayout$LayoutParams",
                             "(II)V",
                             WRAP_CONTENT, WRAP_CONTENT);
}

static void addRule(QAndroidJniObject& params, QtDroidView *view, QtDroidRelativeLayout::Verb verb)
{
    if (view) {
        int anchor = view->instance().callMethod<jint>("getId");
        params.callMethod<void>("addRule", "(II)V", verb, anchor);
    }
}

static void addRule(QAndroidJniObject &params, bool value, QtDroidRelativeLayout::Verb verb)
{
    if (value)
        params.callMethod<void>("addRule", "(I)V", verb);
}

void QtDroidRelativeLayoutParams::inflate(QAndroidJniObject &params)
{
    QtDroidMarginLayoutParams::inflate(params);

    params.setField<jboolean>("alignWithParent", m_alignWithParent);

    addRule(params, m_above, QtDroidRelativeLayout::ABOVE);
    addRule(params, m_below, QtDroidRelativeLayout::BELOW);
    addRule(params, m_alignTop, QtDroidRelativeLayout::ALIGN_TOP);
    addRule(params, m_alignLeft, QtDroidRelativeLayout::ALIGN_LEFT);
    addRule(params, m_alignRight, QtDroidRelativeLayout::ALIGN_RIGHT);
    addRule(params, m_alignBottom, QtDroidRelativeLayout::ALIGN_BOTTOM);
    addRule(params, m_alignStart, QtDroidRelativeLayout::ALIGN_START);
    addRule(params, m_alignEnd, QtDroidRelativeLayout::ALIGN_END);
    addRule(params, m_alignBaseline, QtDroidRelativeLayout::ALIGN_BASELINE);
    addRule(params, m_toLeftOf, QtDroidRelativeLayout::LEFT_OF);
    addRule(params, m_toRightOf, QtDroidRelativeLayout::RIGHT_OF);
    addRule(params, m_toStartOf, QtDroidRelativeLayout::START_OF);
    addRule(params, m_toEndOf, QtDroidRelativeLayout::END_OF);

    addRule(params, m_alignParentTop, QtDroidRelativeLayout::ALIGN_PARENT_TOP);
    addRule(params, m_alignParentLeft, QtDroidRelativeLayout::ALIGN_PARENT_LEFT);
    addRule(params, m_alignParentRight, QtDroidRelativeLayout::ALIGN_PARENT_RIGHT);
    addRule(params, m_alignParentBottom, QtDroidRelativeLayout::ALIGN_PARENT_BOTTOM);
    addRule(params, m_alignParentStart, QtDroidRelativeLayout::ALIGN_PARENT_START);
    addRule(params, m_alignParentEnd, QtDroidRelativeLayout::ALIGN_PARENT_END);
    addRule(params, m_centerHorizontal, QtDroidRelativeLayout::CENTER_HORIZONTAL);
    addRule(params, m_centerVertical, QtDroidRelativeLayout::CENTER_VERTICAL);
    addRule(params, m_centerInParent, QtDroidRelativeLayout::CENTER_IN_PARENT);
}
