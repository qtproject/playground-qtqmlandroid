#ifndef QTDROIDRELATIVELAYOUTPARAMS_P_H
#define QTDROIDRELATIVELAYOUTPARAMS_P_H

#include "qtdroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRelativeLayoutParams : public QtAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidView *above READ above WRITE setAbove NOTIFY aboveChanged)
    Q_PROPERTY(QtAndroidView *below READ below WRITE setBelow NOTIFY belowChanged)
    Q_PROPERTY(QtAndroidView *alignTop READ alignTop WRITE setAlignTop NOTIFY alignTopChanged)
    Q_PROPERTY(QtAndroidView *alignLeft READ alignLeft WRITE setAlignLeft NOTIFY alignLeftChanged)
    Q_PROPERTY(QtAndroidView *alignRight READ alignRight WRITE setAlignRight NOTIFY alignRightChanged)
    Q_PROPERTY(QtAndroidView *alignBottom READ alignBottom WRITE setAlignBottom NOTIFY alignBottomChanged)
    Q_PROPERTY(QtAndroidView *alignStart READ alignStart WRITE setAlignStart NOTIFY alignStartChanged)
    Q_PROPERTY(QtAndroidView *alignEnd READ alignEnd WRITE setAlignEnd NOTIFY alignEndChanged)
    Q_PROPERTY(QtAndroidView *alignBaseline READ alignBaseline WRITE setAlignBaseline NOTIFY alignBaselineChanged)
    Q_PROPERTY(QtAndroidView *toLeftOf READ toLeftOf WRITE setToLeftOf NOTIFY toLeftOfChanged)
    Q_PROPERTY(QtAndroidView *toRightOf READ toRightOf WRITE setToRightOf NOTIFY toRightOfChanged)
    Q_PROPERTY(QtAndroidView *toStartOf READ toStartOf WRITE setToStartOf NOTIFY toStartOfChanged)
    Q_PROPERTY(QtAndroidView *toEndOf READ toEndOf WRITE setToEndOf NOTIFY toEndOfChanged)
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
    explicit QtAndroidRelativeLayoutParams(QtAndroidView *view);

    QtAndroidView *above() const;
    void setAbove(QtAndroidView *view);

    QtAndroidView *below() const;
    void setBelow(QtAndroidView *view);

    QtAndroidView *alignTop() const;
    void setAlignTop(QtAndroidView *view);

    QtAndroidView *alignLeft() const;
    void setAlignLeft(QtAndroidView *view);

    QtAndroidView *alignRight() const;
    void setAlignRight(QtAndroidView *view);

    QtAndroidView *alignBottom() const;
    void setAlignBottom(QtAndroidView *view);

    QtAndroidView *alignStart() const;
    void setAlignStart(QtAndroidView *view);

    QtAndroidView *alignEnd() const;
    void setAlignEnd(QtAndroidView *view);

    QtAndroidView *alignBaseline() const;
    void setAlignBaseline(QtAndroidView *view);

    QtAndroidView *toLeftOf() const;
    void setToLeftOf(QtAndroidView *view);

    QtAndroidView *toRightOf() const;
    void setToRightOf(QtAndroidView *view);

    QtAndroidView *toStartOf() const;
    void setToStartOf(QtAndroidView *view);

    QtAndroidView *toEndOf() const;
    void setToEndOf(QtAndroidView *view);

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
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtAndroidView *m_above;
    QtAndroidView *m_below;
    QtAndroidView *m_alignTop;
    QtAndroidView *m_alignLeft;
    QtAndroidView *m_alignRight;
    QtAndroidView *m_alignBottom;
    QtAndroidView *m_alignStart;
    QtAndroidView *m_alignEnd;
    QtAndroidView *m_alignBaseline;
    QtAndroidView *m_toLeftOf;
    QtAndroidView *m_toRightOf;
    QtAndroidView *m_toStartOf;
    QtAndroidView *m_toEndOf;

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

#endif // QTDROIDRELATIVELAYOUTPARAMS_P_H
