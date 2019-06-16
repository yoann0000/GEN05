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
        double thisAmount = r.getMovie().getPriceCode()->calculateAmmount(r.getDaysRented());

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ( (r.getMovie().getPriceCode()->getCode() ==  1)
             && r.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << r.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << printFooter(totalAmount, frequentRenterPoints);
    return result.str();
}

string Customer::printFooter(double totalAmount, int frequentRenterPoints)
{
    string s;
    s.append("Amount owed is ");
    s.append(to_string(totalAmount));
    s.append("\n");
    s.append("You earned ");
    s.append(to_string(frequentRenterPoints));
    s.append(" frequent renter points");

    return s;
}