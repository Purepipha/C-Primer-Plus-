// stonewt.h -- definetion for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

using std::ostream;
class Stonewt
{
    public:
    enum MODE {STONE, POUNDS, INT_POUNDS};
    private:
        enum{Lbs_per_stn = 14};     // pounds per stone
        double pounds;              // entire weight in pounds
        MODE mode;
    public:
        Stonewt(double lbs, MODE form = POUNDS);
        Stonewt(int stn, double lbs, MODE form = STONE);
        Stonewt(int lbs, MODE form = INT_POUNDS);
        Stonewt();
        ~Stonewt();
        //get value
        int stone_val() const;
        double pds_left_val() const;
        double pounds_val() const;
        int int_pounds_val() const;

        // set mode
        void pounds_mode();
        void int_pounds_mode();
        void stone_mode();


        // operator + - *
        Stonewt operator+(const Stonewt & st) const;
        Stonewt operator-(const Stonewt & st) const;
        Stonewt operator*(double n) const;

    //friend
        // operator*
        friend Stonewt operator*(double n, const Stonewt & st);

        // oprator == != < > <= >=
        friend bool operator==(const Stonewt & st1, const Stonewt & st2);
        friend bool operator!=(const Stonewt & st1, const Stonewt & st2);
        friend bool operator>(const Stonewt & st1, const Stonewt & st2);
        friend bool operator<(const Stonewt & st1, const Stonewt & st2);
        friend bool operator<=(const Stonewt & st1, const Stonewt & st2);
        friend bool operator>=(const Stonewt & st1, const Stonewt & st2);
        //operator<<
        friend ostream & operator<<(ostream & os, const Stonewt & st);
};
#endif