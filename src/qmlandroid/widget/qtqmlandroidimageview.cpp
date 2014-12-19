#include "qtqmlandroidimageview_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidImageView::QtQmlAndroidImageView(QtQmlAndroidView *parent) :
    QtQmlAndroidView(parent), m_resource(0)
{
}

QUrl QtQmlAndroidImageView::imageURI() const
{
    return m_uri;
}

void QtQmlAndroidImageView::setImageURI(const QUrl &uri)
{
    if (m_uri != uri) {
        m_uri = uri;
        if (isValid()) {
            QAndroidJniObject v = instance();
            QAndroidJniObject u = getUri();
            QtQmlAndroid::callFunction([=]() {
                v.callMethod<void>("setImageURI", "(Landroid/net/Uri;)V", u.object());
            });
        }
        emit imageURIChanged();
    }
}

int QtQmlAndroidImageView::imageResource() const
{
    return m_resource;
}

void QtQmlAndroidImageView::setImageResource(int resource)
{
    if (m_resource != resource) {
        m_resource = resource;
        QtQmlAndroid::callIntMethod(instance(), "setImageResource", resource);
        emit imageResourceChanged();
    }
}

int QtQmlAndroidImageView::imageTintColor() const
{
    if (m_tint.isNull())
        return 0; // TODO
    return m_tint.value();
}

void QtQmlAndroidImageView::setImageTintColor(int color)
{
    if (m_tint.isNull() || m_tint.value() != color) {
        m_tint = color;
        if (isValid()) {
            QAndroidJniObject view = instance();
            QtQmlAndroid::callFunction([=]() {
                QAndroidJniObject tint = QAndroidJniObject::callStaticObjectMethod("android/content/res/ColorStateList",
                                                                                   "valueOf",
                                                                                   "(I)Landroid/content/res/ColorStateList;",
                                                                                   color);
                view.callMethod<void>("setImageTintList", "(Landroid/content/res/ColorStateList;)v", tint.object());
            });
        }
        emit imageTintColorChanged();
    }
}

QAndroidJniObject QtQmlAndroidImageView::onCreate()
{
    return QAndroidJniObject("android/widget/ImageView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidImageView::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidView::onInflate(instance);

    if (m_uri.isValid())
        instance.callMethod<void>("setImageURI", "(Landroid/net/Uri;)V", getUri().object());
    if (m_resource > 0)
        instance.callMethod<void>("setImageResource", "(I)V", m_resource);
    if (!m_tint.isNull()) {
        QAndroidJniObject tint = QAndroidJniObject::callStaticObjectMethod("android/content/res/ColorStateList",
                                                                           "valueOf",
                                                                           "(I)Landroid/content/res/ColorStateList;",
                                                                           m_tint.value());
        instance.callMethod<void>("setImageTintList", "(Landroid/content/res/ColorStateList;)v", tint.object());
    }
}

QAndroidJniObject QtQmlAndroidImageView::getUri() const
{
    QAndroidJniObject str = QAndroidJniObject::fromString(m_uri.toString());
    return QAndroidJniObject::callStaticObjectMethod("android/net/Uri", "parse", "(Ljava/lang/String;)Landroid/net/Uri;", str.object());
}

QT_END_NAMESPACE
