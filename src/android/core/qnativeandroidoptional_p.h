/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Copyright (C) 2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Marc Mutz <marc.mutz@kdab.com>
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt QML Android module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QNATIVEANDROIDOPTIONAL_P_H
#define QNATIVEANDROIDOPTIONAL_P_H

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

QT_BEGIN_NAMESPACE

template <typename T>
class QNativeAndroidOptional
{
public:
    QNativeAndroidOptional() : t(), exists(false) {}
    explicit QNativeAndroidOptional(const T &t) : t(t), exists(true) {}
    explicit QNativeAndroidOptional(T &&t) : t(std::move(t)), exists(true) {}
    QNativeAndroidOptional &operator=(const T &o) { t = o; exists = true; return *this; }

    operator T&() Q_DECL_NOTHROW { return t; }
    operator const T&() const Q_DECL_NOTHROW { return t; }

    bool isNull() const Q_DECL_NOTHROW { return !exists; }

private:
    T t;
    bool exists;
};

template <typename T>
inline bool operator==(const QNativeAndroidOptional<T> &lhs, const QNativeAndroidOptional<T> &rhs)
    Q_DECL_NOEXCEPT_EXPR(noexcept(static_cast<const T&>(lhs) == static_cast<const T&>(rhs)))
{ return lhs.isNull() == rhs.isNull() && !lhs.isNull() && static_cast<const T&>(lhs) == static_cast<const T&>(rhs); }

template <typename T>
inline bool operator==(const QNativeAndroidOptional<T> &lhs, const T &rhs)
    Q_DECL_NOEXCEPT_EXPR(noexcept(static_cast<const T&>(lhs) == rhs))
{ return !lhs.isNull() && static_cast<const T&>(lhs) == rhs; }

template <typename T>
inline bool operator==(const T &lhs, const QNativeAndroidOptional<T> &rhs)
    Q_DECL_NOEXCEPT_EXPR(noexcept(lhs == static_cast<const T&>(rhs)))
{ return !rhs.isNull() && lhs == static_cast<const T&>(rhs); }

template <typename T>
inline bool operator!=(const QNativeAndroidOptional<T> &lhs, const QNativeAndroidOptional<T> &rhs)
    Q_DECL_NOEXCEPT_EXPR(noexcept(lhs == rhs))
{ return !operator==(lhs, rhs); }

template <typename T>
inline bool operator!=(const QNativeAndroidOptional<T> &lhs, const T &rhs)
    Q_DECL_NOEXCEPT_EXPR(noexcept(lhs == rhs))
{ return !operator==(lhs, rhs); }

template <typename T>
inline bool operator!=(const T &lhs, const QNativeAndroidOptional<T> &rhs)
    Q_DECL_NOEXCEPT_EXPR(noexcept(lhs == rhs))
{ return !operator==(lhs, rhs); }

QT_END_NAMESPACE

#endif // QNATIVEANDROIDOPTIONAL_P_H
