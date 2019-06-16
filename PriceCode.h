//
// Created by Yoann on 16/06/2019.
//

#ifndef GEN05_PRICECODE_H
#define GEN05_PRICECODE_H
class PriceCode {
public:
    explicit PriceCode(int code) : code(code) {}
    PriceCode();

    virtual int getCode() const {
        return code;
    }

    virtual double calculateAmmount(int daysRented) {
        return code + daysRented;
    }

protected:
    int code;
};

class Regular : public PriceCode {
public:
    Regular() : PriceCode(0) {}

    double calculateAmmount(int daysRented) override {
        double thisAmount = 2;
        if ( daysRented > 2 )
            thisAmount += ( daysRented - 2 ) * 1.5 ;
        return thisAmount;
    }
};

class NewRelease : public PriceCode {
public:
    NewRelease() : PriceCode(1) {}

    double calculateAmmount(int daysRented) override {
        return daysRented * 3;
    }
};

class Childrens : public PriceCode {
public:
    Childrens() : PriceCode(2) {}

    double calculateAmmount(int daysRented) override {
        double thisAmount = 1.5;
        if ( daysRented > 3 )
            thisAmount += ( daysRented - 3 ) * 1.5;
        return thisAmount;
    }
};
#endif //GEN05_PRICECODE_H
