#ifndef QTANDROIDIMAGEVIEW_P_H
#define QTANDROIDIMAGEVIEW_P_H

#include "qtandroidview_p.h"
#include <QtCore/qurl.h>

QT_BEGIN_NAMESPACE

class QtAndroidImageView : public QtAndroidView
{
    Q_OBJECT
    Q_PROPERTY(QUrl imageURI READ imageURI WRITE setImageURI NOTIFY imageURIChanged)
    Q_PROPERTY(int imageResource READ imageResource WRITE setImageResource NOTIFY imageResourceChanged)

public:
    explicit QtAndroidImageView(QtAndroidView *parent = 0);

    QUrl imageURI() const;
    void setImageURI(const QUrl &uri);

    int imageResource() const;
    void setImageResource(int resource);

Q_SIGNALS:
    void imageURIChanged();
    void imageResourceChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QAndroidJniObject getUri() const;

    QUrl m_uri;
    int m_resource;
};

QT_END_NAMESPACE

#endif // QTANDROIDTEXTVIEW_P_H
