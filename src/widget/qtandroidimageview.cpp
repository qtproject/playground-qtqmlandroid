#include "qtandroidimageview_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidImageView::QtAndroidImageView(QtAndroidView *parent) :
    QtAndroidView(parent), m_resource(0)
{
}

QUrl QtAndroidImageView::imageURI() const
{
    return m_uri;
}

void QtAndroidImageView::setImageURI(const QUrl &uri)
{
    if (m_uri != uri) {
        m_uri = uri;
        if (isValid()) {
            QAndroidJniObject v = instance();
            QAndroidJniObject u = getUri();
            QtAndroid::callFunction([=]() {
                v.callMethod<void>("setImageURI", "(Landroid/net/Uri;)V", u.object());
            });
        }
        emit imageURIChanged();
    }
}

int QtAndroidImageView::imageResource() const
{
    return m_resource;
}

void QtAndroidImageView::setImageResource(int resource)
{
    if (m_resource != resource) {
        m_resource = resource;
        QtAndroid::callIntMethod(instance(), "setImageResource", resource);
        emit imageResourceChanged();
    }
}

QAndroidJniObject QtAndroidImageView::onCreate()
{
    return QAndroidJniObject("android/widget/ImageView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidImageView::onInflate(QAndroidJniObject &instance)
{
    QtAndroidView::onInflate(instance);

    if (m_uri.isValid())
        instance.callMethod<void>("setImageURI", "(Landroid/net/Uri;)V", getUri().object());
    if (m_resource > 0)
        instance.callMethod<void>("setImageResource", "(I)V", m_resource);
}

QAndroidJniObject QtAndroidImageView::getUri() const
{
    QAndroidJniObject str = QAndroidJniObject::fromString(m_uri.toString());
    return QAndroidJniObject::callStaticObjectMethod("android/net/Uri", "parse", "(Ljava/lang/String;)Landroid/net/Uri;", str.object());
}
