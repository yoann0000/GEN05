#include <utility>

// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented ): _movie(movie), _daysRented( daysRented ) {}
    Rental();

    virtual int getDaysRented() const {
        return _daysRented;
    }
    virtual const Movie& getMovie() const {
        return _movie;
    }

private:
    Movie _movie;
    int _daysRented;
};

#endif // RENTAL_H