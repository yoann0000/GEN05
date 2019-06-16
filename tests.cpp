//
// Created by Yoann Rohrbasser on 07/06/2019.
//

#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "Movie.h"
#include "PriceCode.h"

using namespace std;
using ::testing::Return;

class MockMovie : public Movie {
public:
    MOCK_CONST_METHOD0(getPriceCode, PriceCode*());
    MOCK_CONST_METHOD0(getTitle, std::string());
};

class MockPriceCode : public PriceCode {
public:
    MOCK_CONST_METHOD0(getCode, int());
    MOCK_METHOD1(calculateAmmount, double(int daysRented));
};

TEST(statementTests, statementTest1) {
    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", new NewRelease ), 5));
    customer.addRental( Rental( Movie("Snow White", new Childrens), 3 ));
    string result = "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points";
    ASSERT_EQ(result, customer.statement());
}

TEST(movieTests, priceNameTest) {
    MockPriceCode pc;
    EXPECT_CALL(pc, getCode()).WillRepeatedly(Return(0));
    EXPECT_CALL(pc, calculateAmmount(5)).WillRepeatedly(Return(5));
    MockMovie movie;
    EXPECT_CALL(movie, getPriceCode()).WillRepeatedly(Return(&pc));
    EXPECT_CALL(movie, getTitle()).WillRepeatedly(Return("mock movie"));

    ASSERT_EQ("Karate Kid", movie.getTitle());
}

TEST(customerTests, nameRentalTest) {
    MockPriceCode pc;
    EXPECT_CALL(pc, getCode()).WillRepeatedly(Return(0));
    EXPECT_CALL(pc, calculateAmmount(5)).WillRepeatedly(Return(5));
    MockMovie movie;
    EXPECT_CALL(movie, getPriceCode()).WillRepeatedly(Return(&pc));
    EXPECT_CALL(movie, getTitle()).WillRepeatedly(Return("mock movie"));
    Customer customer = Customer("test customer");
    customer.addRental(Rental(movie, 5));
    ASSERT_EQ("test customer", customer.getName());
    string result = "Rental Record for test customer\n\tmock movie\t5\nAmount owed is 5\nYou earned 1 frequent renter points";
    ASSERT_EQ(result, customer.statement());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}