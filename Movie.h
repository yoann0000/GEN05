#include <utility>

// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "PriceCode.h"

class Movie {
public:
    virtual ~Movie() = default;

    explicit Movie( std::string  title, PriceCode* priceCode): _title(std::move( title )), _priceCode( priceCode ){}
    explicit Movie( std::string  title): _title(std::move( title )), _priceCode(new Regular){}
    Movie();

    virtual PriceCode* getPriceCode() const {
        return _priceCode;
    }

    void setPriceCode( PriceCode* arg ) {
        _priceCode = arg;
    }

    virtual std::string getTitle() const {
        return _title;
    }

private:
    std::string _title;
    PriceCode* _priceCode;
};

#endif // MOVIE_H