#include <utility>

// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
public:
    virtual ~Movie() = default;
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    explicit Movie( std::string  title, int priceCode = REGULAR ): _title(std::move( title )), _priceCode( priceCode ){}
    Movie();

    virtual int getPriceCode() const {
        return _priceCode;
    }

    void setPriceCode( int arg ) {
        _priceCode = arg;
    }

    virtual std::string getTitle() const {
        return _title;
    }

private:
    std::string _title;
    int _priceCode;
};

#endif // MOVIE_H