#ifndef QTQMLANDROIDCONTEXTWRAPPER_P_H
#define QTQMLANDROIDCONTEXTWRAPPER_P_H

#include "qtqmlandroidcontext_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidContextWrapper : public QtQmlAndroidContext
{
    Q_OBJECT

public:
    explicit QtQmlAndroidContextWrapper(QObject *parent = 0);
    explicit QtQmlAndroidContextWrapper(QtQmlAndroidContext *context, QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDCONTEXTWRAPPER_P_H
