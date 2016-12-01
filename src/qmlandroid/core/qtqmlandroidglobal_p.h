#ifndef QTQMLANDROIDGLOBAL_P_H
#define QTQMLANDROIDGLOBAL_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qglobal.h>
#include <QtCore/qthread.h>
#include <QtCore/qcoreapplication.h>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(QT_BUILD_QMLANDROID_LIB)
#    define Q_QMLANDROID_EXPORT Q_DECL_EXPORT
#  else
#    define Q_QMLANDROID_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_QMLANDROID_EXPORT
#endif

namespace QtQmlAndroid {
    static inline bool isMainQtThread()
    {
        return QThread::currentThread() == qApp->thread();
    }
}

QT_END_NAMESPACE

#endif // QTQMLANDROIDGLOBAL_P_H
