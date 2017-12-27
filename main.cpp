#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "EnglishSuits.hpp"

#include <iostream>
//(1, "HEARTS");
//(2, "SPADES");
//(3, "DIAMONDS");
//(4, "CLUBS");

int needsInt(std::uint32_t x)
{
    return x;
}

std::string needsString(std::string s)
{
    return s;
}

std::string needsStringFromChar( char const * const s)
{
    return s;
}

TEST_CASE("smart_enum")
{
    for(auto& element : EnglishSuits::values())
    {
        std::cout << "el:" << element  << std::endl;
    }
    SECTION("conversion to int")
    {
        REQUIRE(EnglishSuits::HEARTS.to_int() == needsInt(EnglishSuits::HEARTS));
        REQUIRE(EnglishSuits::SPADES.to_int() == needsInt(EnglishSuits::SPADES));
        REQUIRE(EnglishSuits::DIAMONDS.to_int() == needsInt(EnglishSuits::DIAMONDS));
        REQUIRE(EnglishSuits::CLUBS.to_int() == needsInt(EnglishSuits::CLUBS));
    }

    SECTION("conversion to string")
    {
        REQUIRE(EnglishSuits::HEARTS.to_str() == needsString(EnglishSuits::HEARTS));
        REQUIRE(EnglishSuits::SPADES.to_str() == needsString(EnglishSuits::SPADES));
        REQUIRE(EnglishSuits::DIAMONDS.to_str() == needsString(EnglishSuits::DIAMONDS));
        REQUIRE(EnglishSuits::CLUBS.to_str() == needsString(EnglishSuits::CLUBS));
    }

    SECTION("conversion to char const * const")
    {
        REQUIRE(EnglishSuits::HEARTS.to_str() == needsStringFromChar(EnglishSuits::HEARTS));
        REQUIRE(EnglishSuits::SPADES.to_str() == needsStringFromChar(EnglishSuits::SPADES));
        REQUIRE(EnglishSuits::DIAMONDS.to_str() == needsStringFromChar(EnglishSuits::DIAMONDS));
        REQUIRE(EnglishSuits::CLUBS.to_str() == needsStringFromChar(EnglishSuits::CLUBS));
    }

    SECTION("go throught ")
    {
        for (auto& element : EnglishSuits::values())
        {
            WARN(*element);
        }

        for( auto ite = EnglishSuits::begin(); EnglishSuits::end() != ite; ++ite)
        {
            WARN(**ite);
        }
    }

    SECTION("comparisons ")
    {
        REQUIRE(EnglishSuits::HEARTS == EnglishSuits::HEARTS);
        REQUIRE(EnglishSuits::SPADES == EnglishSuits::SPADES);
        REQUIRE(EnglishSuits::DIAMONDS == EnglishSuits::DIAMONDS);
        REQUIRE(EnglishSuits::CLUBS == EnglishSuits::CLUBS);

        REQUIRE(EnglishSuits::HEARTS != EnglishSuits::SPADES);
        REQUIRE(EnglishSuits::HEARTS != EnglishSuits::DIAMONDS);
        REQUIRE(EnglishSuits::HEARTS != EnglishSuits::CLUBS);

        REQUIRE(EnglishSuits::SPADES != EnglishSuits::HEARTS);
        REQUIRE(EnglishSuits::SPADES != EnglishSuits::DIAMONDS);
        REQUIRE(EnglishSuits::SPADES != EnglishSuits::CLUBS);

        REQUIRE(EnglishSuits::DIAMONDS != EnglishSuits::HEARTS);
        REQUIRE(EnglishSuits::DIAMONDS != EnglishSuits::SPADES);
        REQUIRE(EnglishSuits::DIAMONDS != EnglishSuits::CLUBS);

        REQUIRE(EnglishSuits::CLUBS != EnglishSuits::HEARTS);
        REQUIRE(EnglishSuits::CLUBS != EnglishSuits::SPADES);
        REQUIRE(EnglishSuits::CLUBS != EnglishSuits::DIAMONDS);
    }

    SECTION("aditional operations")
    {
        REQUIRE(EnglishSuits::HEARTS.next() == EnglishSuits::SPADES);
        REQUIRE(EnglishSuits::SPADES.next()== EnglishSuits::DIAMONDS);
        REQUIRE(EnglishSuits::DIAMONDS.next() == EnglishSuits::CLUBS);
        REQUIRE_THROWS(EnglishSuits::CLUBS.next());

        REQUIRE_THROWS(EnglishSuits::HEARTS.prev());
        REQUIRE(EnglishSuits::SPADES.prev() == EnglishSuits::HEARTS);
        REQUIRE(EnglishSuits::DIAMONDS.prev()== EnglishSuits::SPADES);
        REQUIRE(EnglishSuits::CLUBS.prev() == EnglishSuits::DIAMONDS);
    }

    SECTION("aditional checks")
    {
        REQUIRE(EnglishSuits::HEARTS.isFirst());
        REQUIRE_FALSE(EnglishSuits::SPADES.isFirst());
        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isFirst());
        REQUIRE_FALSE(EnglishSuits::CLUBS.isFirst());

        REQUIRE_FALSE(EnglishSuits::HEARTS.isLast());
        REQUIRE_FALSE(EnglishSuits::SPADES.isLast());
        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isLast());
        REQUIRE(EnglishSuits::CLUBS.isLast());

        REQUIRE(EnglishSuits::HEARTS.isNext(EnglishSuits::SPADES));
        REQUIRE_FALSE(EnglishSuits::HEARTS.isNext(EnglishSuits::HEARTS));
        REQUIRE_FALSE(EnglishSuits::HEARTS.isNext(EnglishSuits::DIAMONDS));
        REQUIRE_FALSE(EnglishSuits::HEARTS.isNext(EnglishSuits::CLUBS));

        REQUIRE_FALSE(EnglishSuits::HEARTS.isPrev(EnglishSuits::HEARTS));
        REQUIRE_FALSE(EnglishSuits::HEARTS.isPrev(EnglishSuits::SPADES));
        REQUIRE_FALSE(EnglishSuits::HEARTS.isPrev(EnglishSuits::DIAMONDS));
        REQUIRE_FALSE(EnglishSuits::HEARTS.isPrev(EnglishSuits::CLUBS));

        REQUIRE_FALSE(EnglishSuits::SPADES.isNext(EnglishSuits::SPADES));
        REQUIRE_FALSE(EnglishSuits::SPADES.isNext(EnglishSuits::HEARTS));
        REQUIRE(EnglishSuits::SPADES.isNext(EnglishSuits::DIAMONDS));
        REQUIRE_FALSE(EnglishSuits::SPADES.isNext(EnglishSuits::CLUBS));

        REQUIRE(EnglishSuits::SPADES.isPrev(EnglishSuits::HEARTS));
        REQUIRE_FALSE(EnglishSuits::SPADES.isPrev(EnglishSuits::SPADES));
        REQUIRE_FALSE(EnglishSuits::SPADES.isPrev(EnglishSuits::DIAMONDS));
        REQUIRE_FALSE(EnglishSuits::SPADES.isPrev(EnglishSuits::CLUBS));


        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isNext(EnglishSuits::SPADES));
        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isNext(EnglishSuits::HEARTS));
        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isNext(EnglishSuits::DIAMONDS));
        REQUIRE(EnglishSuits::DIAMONDS.isNext(EnglishSuits::CLUBS));

        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isPrev(EnglishSuits::HEARTS));
        REQUIRE(EnglishSuits::DIAMONDS.isPrev(EnglishSuits::SPADES));
        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isPrev(EnglishSuits::DIAMONDS));
        REQUIRE_FALSE(EnglishSuits::DIAMONDS.isPrev(EnglishSuits::CLUBS));

        REQUIRE_FALSE(EnglishSuits::CLUBS.isNext(EnglishSuits::SPADES));
        REQUIRE_FALSE(EnglishSuits::CLUBS.isNext(EnglishSuits::HEARTS));
        REQUIRE_FALSE(EnglishSuits::CLUBS.isNext(EnglishSuits::DIAMONDS));
        REQUIRE_FALSE(EnglishSuits::CLUBS.isNext(EnglishSuits::CLUBS));

        REQUIRE_FALSE(EnglishSuits::CLUBS.isPrev(EnglishSuits::HEARTS));
        REQUIRE_FALSE(EnglishSuits::CLUBS.isPrev(EnglishSuits::SPADES));
        REQUIRE(EnglishSuits::CLUBS.isPrev(EnglishSuits::DIAMONDS));
        REQUIRE_FALSE(EnglishSuits::CLUBS.isPrev(EnglishSuits::CLUBS));
    }

    SECTION("static methods")
    {
        REQUIRE(EnglishSuits::isNext(EnglishSuits::HEARTS, EnglishSuits::SPADES));
        REQUIRE(EnglishSuits::isPrev(EnglishSuits::SPADES, EnglishSuits::HEARTS));
        REQUIRE(EnglishSuits::next(EnglishSuits::HEARTS) == EnglishSuits::SPADES);
        REQUIRE(EnglishSuits::prev(EnglishSuits::SPADES) == EnglishSuits::HEARTS);

        REQUIRE_THROWS(EnglishSuits::prev(EnglishSuits::HEARTS));
        REQUIRE_THROWS(EnglishSuits::next(EnglishSuits::CLUBS));
    }
}