#ifndef QTQMLANDROIDRELATIVELAYOUTPARAMS_P_H
#define QTQMLANDROIDRELATIVELAYOUTPARAMS_P_H

#include "qtqmlandroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidRelativeLayoutParams : public QtQmlAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidView *above READ above WRITE setAbove NOTIFY aboveChanged)
    Q_PROPERTY(QtQmlAndroidView *below READ below WRITE setBelow NOTIFY belowChanged)
    Q_PROPERTY(QtQmlAndroidView *alignTop READ alignTop WRITE setAlignTop NOTIFY alignTopChanged)
    Q_PROPERTY(QtQmlAndroidView *alignLeft READ alignLeft WRITE setAlignLeft NOTIFY alignLeftChanged)
    Q_PROPERTY(QtQmlAndroidView *alignRight READ alignRight WRITE setAlignRight NOTIFY alignRightChanged)
    Q_PROPERTY(QtQmlAndroidView *alignBottom READ alignBottom WRITE setAlignBottom NOTIFY alignBottomChanged)
    Q_PROPERTY(QtQmlAndroidView *alignStart READ alignStart WRITE setAlignStart NOTIFY alignStartChanged)
    Q_PROPERTY(QtQmlAndroidView *alignEnd READ alignEnd WRITE setAlignEnd NOTIFY alignEndChanged)
    Q_PROPERTY(QtQmlAndroidView *alignBaseline READ alignBaseline WRITE setAlignBaseline NOTIFY alignBaselineChanged)
    Q_PROPERTY(QtQmlAndroidView *toLeftOf READ toLeftOf WRITE setToLeftOf NOTIFY toLeftOfChanged)
    Q_PROPERTY(QtQmlAndroidView *toRightOf READ toRightOf WRITE setToRightOf NOTIFY toRightOfChanged)
    Q_PROPERTY(QtQmlAndroidView *toStartOf READ toStartOf WRITE setToStartOf NOTIFY toStartOfChanged)
    Q_PROPERTY(QtQmlAndroidView *toEndOf READ toEndOf WRITE setToEndOf NOTIFY toEndOfChanged)
    Q_PROPERTY(bool alignParentTop READ alignParentTop WRITE setAlignParentTop NOTIFY alignParentTopChanged)
    Q_PROPERTY(bool alignParentLeft READ alignParentLeft WRITE setAlignParentLeft NOTIFY alignParentLeftChanged)
    Q_PROPERTY(bool alignParentRight READ alignParentRight WRITE setAlignParentRight NOTIFY alignParentRightChanged)
    Q_PROPERTY(bool alignParentBottom READ alignParentBottom WRITE setAlignParentBottom NOTIFY alignParentBottomChanged)
    Q_PROPERTY(bool alignParentStart READ alignParentStart WRITE setAlignParentStart NOTIFY alignParentStartChanged)
    Q_PROPERTY(bool alignParentEnd READ alignParentEnd WRITE setAlignParentEnd NOTIFY alignParentEndChanged)
    Q_PROPERTY(bool alignWithParent READ alignWithParent WRITE setAlignWithParent NOTIFY alignWithParentChanged)
    Q_PROPERTY(bool centerHorizontal READ centerHorizontal WRITE setCenterHorizontal NOTIFY centerHorizontalChanged)
    Q_PROPERTY(bool centerVertical READ centerVertical WRITE setCenterVertical NOTIFY centerVerticalChanged)
    Q_PROPERTY(bool centerInParent READ centerInParent WRITE setCenterInParent NOTIFY centerInParentChanged)

public:
    explicit QtQmlAndroidRelativeLayoutParams(QtQmlAndroidView *view);

    QtQmlAndroidView *above() const;
    void setAbove(QtQmlAndroidView *view);

    QtQmlAndroidView *below() const;
    void setBelow(QtQmlAndroidView *view);

    QtQmlAndroidView *alignTop() const;
    void setAlignTop(QtQmlAndroidView *view);

    QtQmlAndroidView *alignLeft() const;
    void setAlignLeft(QtQmlAndroidView *view);

    QtQmlAndroidView *alignRight() const;
    void setAlignRight(QtQmlAndroidView *view);

    QtQmlAndroidView *alignBottom() const;
    void setAlignBottom(QtQmlAndroidView *view);

    QtQmlAndroidView *alignStart() const;
    void setAlignStart(QtQmlAndroidView *view);

    QtQmlAndroidView *alignEnd() const;
    void setAlignEnd(QtQmlAndroidView *view);

    QtQmlAndroidView *alignBaseline() const;
    void setAlignBaseline(QtQmlAndroidView *view);

    QtQmlAndroidView *toLeftOf() const;
    void setToLeftOf(QtQmlAndroidView *view);

    QtQmlAndroidView *toRightOf() const;
    void setToRightOf(QtQmlAndroidView *view);

    QtQmlAndroidView *toStartOf() const;
    void setToStartOf(QtQmlAndroidView *view);

    QtQmlAndroidView *toEndOf() const;
    void setToEndOf(QtQmlAndroidView *view);

    bool alignParentTop() const;
    void setAlignParentTop(bool align);

    bool alignParentLeft() const;
    void setAlignParentLeft(bool align);

    bool alignParentRight() const;
    void setAlignParentRight(bool align);

    bool alignParentBottom() const;
    void setAlignParentBottom(bool align);

    bool alignParentStart() const;
    void setAlignParentStart(bool align);

    bool alignParentEnd() const;
    void setAlignParentEnd(bool align);

    bool alignWithParent() const;
    void setAlignWithParent(bool align);

    bool centerHorizontal() const;
    void setCenterHorizontal(bool center);

    bool centerVertical() const;
    void setCenterVertical(bool center);

    bool centerInParent() const;
    void setCenterInParent(bool center);

Q_SIGNALS:
    void aboveChanged();
    void belowChanged();
    void alignTopChanged();
    void alignLeftChanged();
    void alignRightChanged();
    void alignBottomChanged();
    void alignStartChanged();
    void alignEndChanged();
    void alignBaselineChanged();
    void toLeftOfChanged();
    void toRightOfChanged();
    void toStartOfChanged();
    void toEndOfChanged();

    void alignParentTopChanged();
    bool alignParentLeftChanged();
    bool alignParentRightChanged();
    bool alignParentBottomChanged();
    bool alignParentStartChanged();
    bool alignParentEndChanged();
    bool alignWithParentChanged();
    bool centerHorizontalChanged();
    bool centerVerticalChanged();
    bool centerInParentChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtQmlAndroidView *m_above;
    QtQmlAndroidView *m_below;
    QtQmlAndroidView *m_alignTop;
    QtQmlAndroidView *m_alignLeft;
    QtQmlAndroidView *m_alignRight;
    QtQmlAndroidView *m_alignBottom;
    QtQmlAndroidView *m_alignStart;
    QtQmlAndroidView *m_alignEnd;
    QtQmlAndroidView *m_alignBaseline;
    QtQmlAndroidView *m_toLeftOf;
    QtQmlAndroidView *m_toRightOf;
    QtQmlAndroidView *m_toStartOf;
    QtQmlAndroidView *m_toEndOf;

    bool m_alignParentTop;
    bool m_alignParentLeft;
    bool m_alignParentRight;
    bool m_alignParentBottom;
    bool m_alignParentStart;
    bool m_alignParentEnd;
    bool m_alignWithParent;
    bool m_centerHorizontal;
    bool m_centerVertical;
    bool m_centerInParent;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDRELATIVELAYOUTPARAMS_P_H
