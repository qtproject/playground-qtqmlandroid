/****************************************************************************
**
** Copyright (C) 2014 Ivan Komissarov <ABBAPOH@gmail.com>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQMLANDROIDOPTIONAL_P_H
#define QQMLANDROIDOPTIONAL_P_H

#include <QtCore/QHash>

#ifdef Q_COMPILER_REF_QUALIFIERS
#  define Q_DECL_LVALUE_FUNCTION &
#else
#  define Q_DECL_LVALUE_FUNCTION
#endif

QT_BEGIN_NAMESPACE

struct QQmlAndroidNothing {};

template<typename T>
class QQmlAndroidOptional
{
private:
    typedef bool (QQmlAndroidOptional::*RestrictedBool)() const;

public:
    Q_DECL_CONSTEXPR inline QQmlAndroidOptional() Q_DECL_NOTHROW : null(true) {}

    inline QQmlAndroidOptional(const QQmlAndroidOptional &other) :
        null(other.null)
    {
        if (!null)
            new (ptr()) T(other.value());
    }

#ifdef Q_COMPILER_RVALUE_REFS
    inline QQmlAndroidOptional(QQmlAndroidOptional &&other) :
        null(other.null)
    {
        if (!null)
            new (ptr()) T(qMove(other.value()));
    }
#endif

    Q_DECL_CONSTEXPR inline QQmlAndroidOptional(QQmlAndroidNothing) Q_DECL_NOTHROW : null(true) {}

    inline QQmlAndroidOptional(const T &value) :
        null(false)
    {
        new (ptr()) T(value);
    }

#ifdef Q_COMPILER_RVALUE_REFS
    inline QQmlAndroidOptional(T &&value) :
        null(false)
    {
        new (ptr()) T(qMove(value));
    }
#endif

    inline ~QQmlAndroidOptional()
    {
        if (!null)
            ptr()->~T();
    }

    inline QQmlAndroidOptional &operator=(QQmlAndroidNothing)
    {
        reset();
        return *this;
    }

    inline QQmlAndroidOptional &operator=(const QQmlAndroidOptional &other)
    {
        if (other.isNull() == isNull()) {
            if (!null)
                value() = other.value();
        } else {
            if (!null)
                ptr()->~T();
            else
                new (ptr()) T(other.value());
            null = other.isNull();
        }
        return *this;
    }

#ifdef Q_COMPILER_RVALUE_REFS
    inline QQmlAndroidOptional &operator=(QQmlAndroidOptional &&other)
    {
        if (other.isNull() == isNull()) {
            if (!null)
                value() = qMove(other.value());
        } else {
            if (!null)
                ptr()->~T();
            else
                new (ptr()) T(qMove(other.value()));
            null = other.isNull();
        }
        return *this;
    }
#endif

    inline QQmlAndroidOptional &operator=(const T &value)
    {
        if (!null) {
            this->value() = value;
        } else {
            new (ptr()) T(value);
            null = false;
        }

        return *this;
    }

#ifdef Q_COMPILER_RVALUE_REFS
    inline QQmlAndroidOptional &operator=(T &&value)
    {
        if (!null) {
            this->value() = qMove(value);
        } else {
            new (ptr()) T(qMove(value));
            null = false;
        }

        return *this;
    }
#endif

    Q_DECL_CONSTEXPR inline bool isNull() const { return null; }

#ifndef Q_QDOC
    inline T &value() Q_DECL_LVALUE_FUNCTION
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::value", "QQmlAndroidOptional is null");
        return *ptr();
    }

    inline const T &value() const Q_DECL_LVALUE_FUNCTION
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::value", "QQmlAndroidOptional is null");
        return *ptr();
    }

#ifdef Q_COMPILER_RVALUE_REFS
    inline T &&value() &&
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::value", "QQmlAndroidOptional is null");
        return qMove(*ptr());
    }
#endif

#else
    inline T &value();
    inline const T &value() const;
#endif // Q_QDOC

    inline const T &value(const T &defaultValue) const
    {
        return null ? defaultValue : value();
    }

    inline void swap(QQmlAndroidOptional &other) Q_DECL_NOEXCEPT_EXPR(noexcept(qSwap(value(), other.value()))
                                                           && noexcept(T(qMove(other.value()))))
    {
        if (null == other.null) {
            if (!null)
                qSwap(value(), other.value());
        } else {
            if (!null) {
                new (other.ptr()) T(qMove(value()));
                ptr()->~T();
            } else {
                new (ptr()) T(qMove(other.value()));
                other.value().~T();
            }
            qSwap(null, other.null);
        }
    }

    inline void reset()
    {
        if (!null) {
            ptr()->~T();
            null = true;
        }
    }

#ifndef Q_QDOC
    inline T &operator*() Q_DECL_LVALUE_FUNCTION
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::operator*", "QQmlAndroidOptional is null");
        return *ptr();
    }

    inline const T &operator*() const Q_DECL_LVALUE_FUNCTION
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::operator*", "QQmlAndroidOptional is null");
        return *ptr();
    }

#ifdef Q_COMPILER_RVALUE_REFS
    inline T &&operator * () &&
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::operator*", "QQmlAndroidOptional is null");
        return qMove(*ptr());
    }
#endif

    inline T *operator->()
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::operator->", "QQmlAndroidOptional is null");
        return ptr();
    }

    inline const T *operator->() const
    {
        Q_ASSERT_X(!null, "QQmlAndroidOptional::operator->", "QQmlAndroidOptional is null");
        return ptr();
    }

    Q_DECL_CONSTEXPR inline operator RestrictedBool() const { return null ? Q_NULLPTR : &QQmlAndroidOptional::isNull; }

#else
    inline T &operator*();
    inline const T &operator*() const;
    inline T *operator->();
    inline const T *operator->() const;

    Q_DECL_CONSTEXPR explicit inline operator bool() const { return null; }
#endif // Q_QDOC

    Q_DECL_CONSTEXPR bool operator!() const { return null; }

private:
    struct Aligner { bool a; T t; };

    bool null;
    char storage[sizeof(Aligner) - sizeof(bool)];

    inline T *ptr()
    {
        return reinterpret_cast<T *>(storage + (sizeof(storage) % sizeof(T)));
    }

    inline const T *ptr() const
    {
        return reinterpret_cast<const T*>(storage + (sizeof(storage) % sizeof(T)));
    }
};

template<typename T>
inline QQmlAndroidOptional<T> qMakeOptional(const T &value)
{
    return QQmlAndroidOptional<T>(value);
}

template <>
class QQmlAndroidOptional<void>
{
private:
    typedef bool (QQmlAndroidOptional<void>::*RestrictedBool)() const;
public:
    // all compiler-generated special member functions are ok!

    Q_DECL_CONSTEXPR inline bool isNull() const { return true; }

#ifndef Q_QDOC
    Q_DECL_CONSTEXPR inline operator RestrictedBool () const { return Q_NULLPTR; }
#else
    Q_DECL_CONSTEXPR explicit inline operator bool() const { return false; }
#endif
};

template<typename T>
Q_DECL_CONSTEXPR inline bool operator==(const QQmlAndroidOptional<T> &lhs, const QQmlAndroidOptional<T> &rhs)
{
    return (rhs.isNull() && lhs.isNull())
            || (!rhs.isNull() && !lhs.isNull() && lhs.value() == rhs.value());
}

template<typename T>
Q_DECL_CONSTEXPR inline bool operator!=(const QQmlAndroidOptional<T> &lhs, const QQmlAndroidOptional<T> &rhs)
{
    return !(lhs == rhs);
}

template<typename T>
Q_DECL_CONSTEXPR inline bool operator<(const QQmlAndroidOptional<T> &lhs, const QQmlAndroidOptional<T> &rhs)
{
    return (lhs.isNull() && !rhs.isNull())
            || (!rhs.isNull() && !lhs.isNull() && lhs.value() < rhs.value());
}

template<typename T>
Q_DECL_CONSTEXPR inline bool operator>(const QQmlAndroidOptional<T> &lhs, const QQmlAndroidOptional<T> &rhs)
{
    return rhs < lhs;
}

template<typename T>
Q_DECL_CONSTEXPR inline bool operator<=(const QQmlAndroidOptional<T> &lhs, const QQmlAndroidOptional<T> &rhs)
{
    return !(lhs > rhs);
}

template<typename T>
Q_DECL_CONSTEXPR inline bool operator>=(const QQmlAndroidOptional<T> &lhs, const QQmlAndroidOptional<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T>
Q_DECL_CONSTEXPR inline uint qHash(const QQmlAndroidOptional<T> &key, uint seed = 0)
{
    return key ? seed : qHash(*key, seed) ;
}

QT_END_NAMESPACE

#undef Q_DECL_LVALUE_FUNCTION

#endif // QQMLANDROIDOPTIONAL_H
