#include <utility>

// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( Movie  movie, int daysRented ): _movie(std::move( movie )), _daysRented( daysRented ) {}

    int getDaysRented() const {
        return _daysRented;
    }
    const Movie& getMovie() const {
        return _movie;
    }

private:
    Movie _movie;
    int _daysRented;
};

#endif // RENTAL_H