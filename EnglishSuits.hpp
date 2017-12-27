#ifndef SMART_ENUMS_ENGLISHSUITS_HPP
#define SMART_ENUMS_ENGLISHSUITS_HPP

#include "smart_enum.hpp"

class EnglishSuits final : public smart_enum
{
public:
    // to make base class constructors available
    using smart_enum::smart_enum;
    ~EnglishSuits() override = default;

    // declare the list of objects
    static const EnglishSuits SPADES;
    static const EnglishSuits CLUBS;
    static const EnglishSuits HEARTS;
    static const EnglishSuits DIAMONDS;
};

//define and initialize the objects
const EnglishSuits EnglishSuits::SPADES(2, "SPADES");
const EnglishSuits EnglishSuits::CLUBS(4, "CLUBS");
const EnglishSuits EnglishSuits::HEARTS(1, "HEARTS");
const EnglishSuits EnglishSuits::DIAMONDS(3, "DIAMONDS");

#endif //SMART_ENUMS_ENGLISHSUITS_HPP
