#include "qqmlandroidrelativelayoutparams_p.h"
#include "qqmlandroidrelativelayout_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidRelativeLayoutParams::QQmlAndroidRelativeLayoutParams(QQmlAndroidView *view) :
    QQmlAndroidMarginLayoutParams(view),
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

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::above() const
{
    return m_above;
}

void QQmlAndroidRelativeLayoutParams::setAbove(QQmlAndroidView *view)
{
    if (view != m_above) {
        m_above = view;
        invalidate();
        emit aboveChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::below() const
{
    return m_below;
}

void QQmlAndroidRelativeLayoutParams::setBelow(QQmlAndroidView *view)
{
    if (view != m_below) {
        m_below = view;
        invalidate();
        emit belowChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::alignTop() const
{
    return m_alignTop;
}

void QQmlAndroidRelativeLayoutParams::setAlignTop(QQmlAndroidView *view)
{
    if (view != m_alignTop) {
        m_alignTop = view;
        invalidate();
        emit alignTopChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::alignLeft() const
{
    return m_alignLeft;
}

void QQmlAndroidRelativeLayoutParams::setAlignLeft(QQmlAndroidView *view)
{
    if (view != m_alignLeft) {
        m_alignLeft = view;
        invalidate();
        emit alignLeftChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::alignRight() const
{
    return m_alignRight;
}

void QQmlAndroidRelativeLayoutParams::setAlignRight(QQmlAndroidView *view)
{
    if (view != m_alignRight) {
        m_alignRight = view;
        invalidate();
        emit alignRightChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::alignBottom() const
{
    return m_alignBottom;
}

void QQmlAndroidRelativeLayoutParams::setAlignBottom(QQmlAndroidView *view)
{
    if (view != m_alignBottom) {
        m_alignBottom = view;
        invalidate();
        emit alignBottomChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::alignStart() const
{
    return m_alignStart;
}

void QQmlAndroidRelativeLayoutParams::setAlignStart(QQmlAndroidView *view)
{
    if (view != m_alignStart) {
        m_alignStart = view;
        invalidate();
        emit alignStartChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::alignEnd() const
{
    return m_alignEnd;
}

void QQmlAndroidRelativeLayoutParams::setAlignEnd(QQmlAndroidView *view)
{
    if (view != m_alignEnd) {
        m_alignEnd = view;
        invalidate();
        emit alignEndChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::alignBaseline() const
{
    return m_alignBaseline;
}

void QQmlAndroidRelativeLayoutParams::setAlignBaseline(QQmlAndroidView *view)
{
    if (view != m_alignBaseline) {
        m_alignBaseline = view;
        invalidate();
        emit alignBaselineChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::toLeftOf() const
{
    return m_toLeftOf;
}

void QQmlAndroidRelativeLayoutParams::setToLeftOf(QQmlAndroidView *view)
{
    if (view != m_toLeftOf) {
        m_toLeftOf = view;
        invalidate();
        emit toLeftOfChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::toRightOf() const
{
    return m_toRightOf;
}

void QQmlAndroidRelativeLayoutParams::setToRightOf(QQmlAndroidView *view)
{
    if (view != m_toRightOf) {
        m_toRightOf = view;
        invalidate();
        emit toRightOfChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::toStartOf() const
{
    return m_toStartOf;
}

void QQmlAndroidRelativeLayoutParams::setToStartOf(QQmlAndroidView *view)
{
    if (view != m_toStartOf) {
        m_toStartOf = view;
        invalidate();
        emit toStartOfChanged();
    }
}

QQmlAndroidView *QQmlAndroidRelativeLayoutParams::toEndOf() const
{
    return m_toEndOf;
}

void QQmlAndroidRelativeLayoutParams::setToEndOf(QQmlAndroidView *view)
{
    if (view != m_toEndOf) {
        m_toEndOf = view;
        invalidate();
        emit toEndOfChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::alignParentTop() const
{
    return m_alignParentTop;
}

void QQmlAndroidRelativeLayoutParams::setAlignParentTop(bool align)
{
    if (align != alignParentTop()) {
        m_alignParentTop = align;
        invalidate();
        emit alignParentTopChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::alignParentLeft() const
{
    return m_alignParentLeft;
}

void QQmlAndroidRelativeLayoutParams::setAlignParentLeft(bool align)
{
    if (align != alignParentLeft()) {
        m_alignParentLeft = align;
        invalidate();
        emit alignParentLeftChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::alignParentRight() const
{
    return m_alignParentRight;
}

void QQmlAndroidRelativeLayoutParams::setAlignParentRight(bool align)
{
    if (align != alignParentRight()) {
        m_alignParentRight = align;
        invalidate();
        emit alignParentRightChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::alignParentBottom() const
{
    return m_alignParentBottom;
}

void QQmlAndroidRelativeLayoutParams::setAlignParentBottom(bool align)
{
    if (align != alignParentBottom()) {
        m_alignParentBottom = align;
        invalidate();
        emit alignParentBottomChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::alignParentStart() const
{
    return m_alignParentStart;
}

void QQmlAndroidRelativeLayoutParams::setAlignParentStart(bool align)
{
    if (align != alignParentStart()) {
        m_alignParentStart = align;
        invalidate();
        emit alignParentStartChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::alignParentEnd() const
{
    return m_alignParentEnd;
}

void QQmlAndroidRelativeLayoutParams::setAlignParentEnd(bool align)
{
    if (align != alignParentEnd()) {
        m_alignParentEnd = align;
        invalidate();
        emit alignParentEndChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::alignWithParent() const
{
    return m_alignWithParent;
}

void QQmlAndroidRelativeLayoutParams::setAlignWithParent(bool align)
{
    if (align != alignWithParent()) {
        m_alignWithParent = align;
        invalidate();
        emit alignWithParentChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::centerHorizontal() const
{
    return m_centerHorizontal;
}

void QQmlAndroidRelativeLayoutParams::setCenterHorizontal(bool center)
{
    if (center != centerHorizontal()) {
        m_centerHorizontal = center;
        invalidate();
        emit centerHorizontalChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::centerVertical() const
{
    return m_centerVertical;
}

void QQmlAndroidRelativeLayoutParams::setCenterVertical(bool center)
{
    if (center != centerVertical()) {
        m_centerVertical = center;
        invalidate();
        emit centerVerticalChanged();
    }
}

bool QQmlAndroidRelativeLayoutParams::centerInParent() const
{
    return m_centerInParent;
}

void QQmlAndroidRelativeLayoutParams::setCenterInParent(bool center)
{
    if (center != centerInParent()) {
        m_centerInParent = center;
        invalidate();
        emit centerInParentChanged();
    }
}

QAndroidJniObject QQmlAndroidRelativeLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/RelativeLayout$LayoutParams",
                             "(II)V",
                             WRAP_CONTENT, WRAP_CONTENT);
}

static void addRule(QAndroidJniObject& instance, QQmlAndroidView *view, QQmlAndroidRelativeLayout::Verb verb)
{
    if (view) {
        int anchor = view->instance().callMethod<jint>("getId");
        instance.callMethod<void>("addRule", "(II)V", verb, anchor);
    }
}

static void addRule(QAndroidJniObject &instance, bool value, QQmlAndroidRelativeLayout::Verb verb)
{
    if (value)
        instance.callMethod<void>("addRule", "(I)V", verb);
}

void QQmlAndroidRelativeLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<jboolean>("alignWithParent", m_alignWithParent);

    addRule(instance, m_above, QQmlAndroidRelativeLayout::ABOVE);
    addRule(instance, m_below, QQmlAndroidRelativeLayout::BELOW);
    addRule(instance, m_alignTop, QQmlAndroidRelativeLayout::ALIGN_TOP);
    addRule(instance, m_alignLeft, QQmlAndroidRelativeLayout::ALIGN_LEFT);
    addRule(instance, m_alignRight, QQmlAndroidRelativeLayout::ALIGN_RIGHT);
    addRule(instance, m_alignBottom, QQmlAndroidRelativeLayout::ALIGN_BOTTOM);
    addRule(instance, m_alignStart, QQmlAndroidRelativeLayout::ALIGN_START);
    addRule(instance, m_alignEnd, QQmlAndroidRelativeLayout::ALIGN_END);
    addRule(instance, m_alignBaseline, QQmlAndroidRelativeLayout::ALIGN_BASELINE);
    addRule(instance, m_toLeftOf, QQmlAndroidRelativeLayout::LEFT_OF);
    addRule(instance, m_toRightOf, QQmlAndroidRelativeLayout::RIGHT_OF);
    addRule(instance, m_toStartOf, QQmlAndroidRelativeLayout::START_OF);
    addRule(instance, m_toEndOf, QQmlAndroidRelativeLayout::END_OF);

    addRule(instance, m_alignParentTop, QQmlAndroidRelativeLayout::ALIGN_PARENT_TOP);
    addRule(instance, m_alignParentLeft, QQmlAndroidRelativeLayout::ALIGN_PARENT_LEFT);
    addRule(instance, m_alignParentRight, QQmlAndroidRelativeLayout::ALIGN_PARENT_RIGHT);
    addRule(instance, m_alignParentBottom, QQmlAndroidRelativeLayout::ALIGN_PARENT_BOTTOM);
    addRule(instance, m_alignParentStart, QQmlAndroidRelativeLayout::ALIGN_PARENT_START);
    addRule(instance, m_alignParentEnd, QQmlAndroidRelativeLayout::ALIGN_PARENT_END);
    addRule(instance, m_centerHorizontal, QQmlAndroidRelativeLayout::CENTER_HORIZONTAL);
    addRule(instance, m_centerVertical, QQmlAndroidRelativeLayout::CENTER_VERTICAL);
    addRule(instance, m_centerInParent, QQmlAndroidRelativeLayout::CENTER_IN_PARENT);
}

QT_END_NAMESPACE
