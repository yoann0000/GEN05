//
// Created by Yoann Rohrbasser on 07/06/2019.
//

#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"

TEST(statementTests, statementTest1) {
    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));
    std::string result = "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points";
    ASSERT_EQ(result, customer.statement());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}