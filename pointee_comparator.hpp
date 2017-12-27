
#ifndef SMART_ENUMS_POINTEE_COMPARATOR_HPP
#define SMART_ENUMS_POINTEE_COMPARATOR_HPP


template<typename T>
struct pointee_comparator
{
    bool operator()(T const* lhs, T const* rhs) const
    {
        return *lhs<*rhs;
    }
};

#endif //SMART_ENUMS_POINTEE_COMPARATOR_HPP
