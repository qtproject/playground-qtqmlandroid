#ifndef QTDROIDRELATIVELAYOUTPARAMS_P_H
#define QTDROIDRELATIVELAYOUTPARAMS_P_H

#include "qtdroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidRelativeLayoutParams : public QtDroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(QtDroidView *above READ above WRITE setAbove NOTIFY aboveChanged)
    Q_PROPERTY(QtDroidView *below READ below WRITE setBelow NOTIFY belowChanged)
    Q_PROPERTY(QtDroidView *alignTop READ alignTop WRITE setAlignTop NOTIFY alignTopChanged)
    Q_PROPERTY(QtDroidView *alignLeft READ alignLeft WRITE setAlignLeft NOTIFY alignLeftChanged)
    Q_PROPERTY(QtDroidView *alignRight READ alignRight WRITE setAlignRight NOTIFY alignRightChanged)
    Q_PROPERTY(QtDroidView *alignBottom READ alignBottom WRITE setAlignBottom NOTIFY alignBottomChanged)
    Q_PROPERTY(QtDroidView *alignStart READ alignStart WRITE setAlignStart NOTIFY alignStartChanged)
    Q_PROPERTY(QtDroidView *alignEnd READ alignEnd WRITE setAlignEnd NOTIFY alignEndChanged)
    Q_PROPERTY(QtDroidView *alignBaseline READ alignBaseline WRITE setAlignBaseline NOTIFY alignBaselineChanged)
    Q_PROPERTY(QtDroidView *toLeftOf READ toLeftOf WRITE setToLeftOf NOTIFY toLeftOfChanged)
    Q_PROPERTY(QtDroidView *toRightOf READ toRightOf WRITE setToRightOf NOTIFY toRightOfChanged)
    Q_PROPERTY(QtDroidView *toStartOf READ toStartOf WRITE setToStartOf NOTIFY toStartOfChanged)
    Q_PROPERTY(QtDroidView *toEndOf READ toEndOf WRITE setToEndOf NOTIFY toEndOfChanged)
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
    explicit QtDroidRelativeLayoutParams(QtDroidView *view);

    static QtDroidRelativeLayoutParams *qmlAttachedProperties(QObject *object);

    QtDroidView *above() const;
    void setAbove(QtDroidView *view);

    QtDroidView *below() const;
    void setBelow(QtDroidView *view);

    QtDroidView *alignTop() const;
    void setAlignTop(QtDroidView *view);

    QtDroidView *alignLeft() const;
    void setAlignLeft(QtDroidView *view);

    QtDroidView *alignRight() const;
    void setAlignRight(QtDroidView *view);

    QtDroidView *alignBottom() const;
    void setAlignBottom(QtDroidView *view);

    QtDroidView *alignStart() const;
    void setAlignStart(QtDroidView *view);

    QtDroidView *alignEnd() const;
    void setAlignEnd(QtDroidView *view);

    QtDroidView *alignBaseline() const;
    void setAlignBaseline(QtDroidView *view);

    QtDroidView *toLeftOf() const;
    void setToLeftOf(QtDroidView *view);

    QtDroidView *toRightOf() const;
    void setToRightOf(QtDroidView *view);

    QtDroidView *toStartOf() const;
    void setToStartOf(QtDroidView *view);

    QtDroidView *toEndOf() const;
    void setToEndOf(QtDroidView *view);

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
    void applyParams(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtDroidView *m_above;
    QtDroidView *m_below;
    QtDroidView *m_alignTop;
    QtDroidView *m_alignLeft;
    QtDroidView *m_alignRight;
    QtDroidView *m_alignBottom;
    QtDroidView *m_alignStart;
    QtDroidView *m_alignEnd;
    QtDroidView *m_alignBaseline;
    QtDroidView *m_toLeftOf;
    QtDroidView *m_toRightOf;
    QtDroidView *m_toStartOf;
    QtDroidView *m_toEndOf;

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

QML_DECLARE_TYPEINFO(QtDroidRelativeLayoutParams, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTDROIDRELATIVELAYOUTPARAMS_P_H
