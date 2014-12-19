#ifndef QTQMLANDROIDIMAGEVIEW_P_H
#define QTQMLANDROIDIMAGEVIEW_P_H

#include "qtqmlandroidview_p.h"
#include "qtqmlandroidoptional_p.h"
#include <QtCore/qurl.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidImageView : public QQmlAndroidView
{
    Q_OBJECT
    Q_PROPERTY(QUrl imageURI READ imageURI WRITE setImageURI NOTIFY imageURIChanged)
    Q_PROPERTY(int imageResource READ imageResource WRITE setImageResource NOTIFY imageResourceChanged)
    Q_PROPERTY(int imageTintColor READ imageTintColor WRITE setImageTintColor NOTIFY imageTintColorChanged)

public:
    explicit QQmlAndroidImageView(QQmlAndroidView *parent = 0);

    QUrl imageURI() const;
    void setImageURI(const QUrl &uri);

    int imageResource() const;
    void setImageResource(int resource);

    int imageTintColor() const;
    void setImageTintColor(int color);

Q_SIGNALS:
    void imageURIChanged();
    void imageResourceChanged();
    void imageTintColorChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QAndroidJniObject getUri() const;

    QUrl m_uri;
    int m_resource;
    QQmlAndroidOptional<int> m_tint;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDTEXTVIEW_P_H
