#ifndef QQMLANDROIDIMAGEVIEW_P_H
#define QQMLANDROIDIMAGEVIEW_P_H

#include "qqmlandroidview_p.h"
#include "qqmlandroidoptional_p.h"
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

#endif // QQMLANDROIDTEXTVIEW_P_H
