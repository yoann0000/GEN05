//
// Created by Yoann Rohrbasser on 07/06/2019.
//

#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "Movie.h"

class MockMovie : public Movie {
public:
    MOCK_CONST_METHOD0(getPriceCode, int());
    MOCK_CONST_METHOD0(getTitle, std::string());
};

TEST(statementTests, statementTest1) {
    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));
    std::string result = "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points";
    ASSERT_EQ(result, customer.statement());
}

TEST(movieTests, priceNameTest) {
    Movie kk = Movie("Karate Kid");
    Movie ae = Movie( "Avengers: Endgame", Movie::NEW_RELEASE );
    Movie jw = Movie( "John Wick 3", 4);
    ASSERT_EQ(0, kk.getPriceCode());
    ASSERT_EQ(1, ae.getPriceCode());
    ASSERT_EQ(4, jw.getPriceCode());
    ASSERT_EQ("Karate Kid", kk.getTitle());
}

TEST(customerTests, nameRentalTest) {
    Customer c = Customer("Georges");
    Movie kk = Movie("Karate Kid");
    Rental r = Rental(kk, 3);
    c.addRental(r);
    ASSERT_EQ("Georges", c.getName());
    ASSERT_EQ("Karate Kid", r.getMovie().getTitle());
    ASSERT_EQ(3, r.getDaysRented());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}