// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for (const Rental& r : _rentals) {
        double thisAmount = 0;
        // determine amounts for each line
        switch ( r.getMovie().getPriceCode() ) {
            case Movie::REGULAR:
                thisAmount += 2;
                if ( r.getDaysRented() > 2 )
                    thisAmount += ( r.getDaysRented() - 2 ) * 1.5 ;
                break;
            case Movie::NEW_RELEASE:
                thisAmount += r.getDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                thisAmount += 1.5;
                if ( r.getDaysRented() > 3 )
                    thisAmount += ( r.getDaysRented() - 3 ) * 1.5;
                break;
        }

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ( ( r.getMovie().getPriceCode() == Movie::NEW_RELEASE )
             && r.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << r.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}