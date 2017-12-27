#ifndef SMART_ENUMS_SMART_ENUM_HPP
#define SMART_ENUMS_SMART_ENUM_HPP

#include "pointee_comparator.hpp"

#include <vector>
#include <algorithm>
#include <string>
#include <cinttypes>
#include <exception>

#include <iostream>


class OverflowException : public std::exception
{
public:
    OverflowException(void) = default;
    OverflowException(char const * const message )
            : message(message)
    {

    }
    ~OverflowException() override = default;

    const char *what() const noexcept override
    {
        std::string const s (exception::what());
        return message.append(s).c_str();
    }

private:
    mutable std::string message;
};
class smart_enum
{
protected:
    constexpr smart_enum(std::uint32_t const value, char const *const name)
            : value(value)
            , name(name)
    {
        collection.push_back(this);
        std::sort(std::begin(collection), std::end(collection), pointee_comparator<smart_enum>());
    }

public:
    virtual ~smart_enum() = default;
    std::uint32_t to_int(void) const;
    std::string to_str(void) const;

    static smart_enum const& next(smart_enum const& st_enum);
    static smart_enum const& prev(smart_enum const& st_enum);
    static bool isFirst(smart_enum const& st_enum);
    static bool isLast(smart_enum const& st_enum);
    static bool isNext(smart_enum const& st_enum, smart_enum const& isnext);
    static bool isPrev(smart_enum const& st_enum, smart_enum const& isprev);
    smart_enum const& next(void) const;
    smart_enum const& prev(void) const;

    static auto begin(void)
    {
        return std::begin(collection);
    }
    static auto end(void)
    {
        return std::end(collection);
    }
    static auto values(void)
    {
        return collection;
    }


    bool isFirst(void) const;
    bool isLast(void) const;
    bool isNext(smart_enum const& st_enum) const;
    bool isPrev(smart_enum const& st_enum) const;


    operator std::uint32_t() const
    {
        return value;
    }
    operator char const * const() const
    {
        return name;
    }
    operator std::string() const
    {
        return name;
    }


    // avoid copy
    smart_enum(smart_enum const &rhs) = delete;
    smart_enum &operator=(smart_enum const &rhs) = delete;

    // avoid move
    smart_enum(smart_enum &&rhs) noexcept = delete;
    smart_enum& operator=(smart_enum &&rhs) noexcept = delete;

private:
    std::uint32_t value;
    char const *const name;

    // to register and order all the types
    using CollectionType = std::vector<smart_enum const *>;
    static CollectionType collection;
};

//some operators
std::ostream& operator<<(std::ostream& os, smart_enum const& obj)
{
    os << obj.to_str();
    return os;
}
//some operators
std::ostream& operator<<(std::ostream& os, smart_enum const * const obj)
{
    os << obj->to_str();
    return os;
}

inline bool operator==(const smart_enum& lhs, const smart_enum& rhs)
{ /* do actual comparison */
    return lhs.to_int() == rhs.to_int();
}
inline bool operator!=(const smart_enum& lhs, const smart_enum& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const smart_enum& lhs, const smart_enum& rhs)
{ /* do actual comparison */
    std::cout << __PRETTY_FUNCTION__ << "lhs:" << lhs << ", rhs:" << rhs << std::endl;
    return lhs.to_int() < rhs.to_int();
}
inline bool operator> (const smart_enum& lhs, const smart_enum& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const smart_enum& lhs, const smart_enum& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const smart_enum& lhs, const smart_enum& rhs){return !operator< (lhs,rhs);}

///impl
smart_enum::CollectionType smart_enum::collection;

smart_enum const& smart_enum::next(smart_enum const& st_enum)
{
    return st_enum.next();
}

smart_enum const& smart_enum::prev(smart_enum const& st_enum)
{
    return st_enum.prev();
}

bool smart_enum::isFirst(smart_enum const& st_enum)
{
    return st_enum.isFirst();
}

bool smart_enum::isLast(smart_enum const& st_enum)
{
    return st_enum.isLast();
}

std::uint32_t smart_enum::to_int(void) const
{
    return value;
}

std::string smart_enum::to_str(void) const
{
    return name;
}

smart_enum const& smart_enum::next(void) const
{
    auto ite = std::find(std::begin(collection), std::end(collection), this);
    if (**ite == *collection.at(std::size(collection)-1))
    {
        throw OverflowException("No next element");
    }
    return **(++ite);
}

smart_enum const& smart_enum::prev(void) const
{
    auto ite = std::find(std::begin(collection), std::end(collection), this);
    if (**ite == *collection.at(0))
    {
        throw OverflowException("No prev element");
    }
    return **(--ite);
}

bool smart_enum::isFirst(void) const
{
    auto ite = std::begin(collection);
    return *ite == this;
}

bool smart_enum::isLast(void) const
{
    auto size = std::size(collection);
    return collection.at(size-1) == this;
}

bool smart_enum::isNext(smart_enum const& st_enum) const
{
    if (collection.at(std::size(collection)-1) == this)
    {
        return false;
    }
    auto ite = std::find(std::begin(collection), std::end(collection), this);
    return st_enum == (*ite)->next();
}

bool smart_enum::isPrev(smart_enum const& st_enum) const
{
    if (collection.at(0) == this)
    {
        return false;
    }
    auto ite = std::find(std::begin(collection), std::end(collection), this);
    return st_enum == (*ite)->prev();
}

bool smart_enum::isNext(smart_enum const& st_enum, smart_enum const& isnext)
{
    return st_enum.isNext(isnext);
}
bool smart_enum::isPrev(smart_enum const& st_enum, smart_enum const& isprev)
{
    return st_enum.isPrev(isprev);
}




#endif //SMART_ENUMS_SMART_ENUM_HPP
