// wine.h -- definition of Wine class
#ifndef WINEC_H_
#define WINEC_H_
#include <string>
#include <valarray>

// template class Pair
template<typename T1, typename T2>
class Pair
{
private:
    T1 t1;
    T2 t2;
public:
    T1 & first() { return t1; }
    T2 & second() { return t2; }
    T1 first() const { return t1; }
    T2 second() const { return t2; }
    Pair(const T1 & t1val, const T2 & t2val) : t1(t1val), t2(t2val) {}
    Pair() {};
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArrayInt;

class Wine : private std::string, private PairArrayInt
{
private:
    int years;
public:
    Wine(const char * l = "no one", int y = 0);
    Wine(const char *l, int y, const int yr[], const int bot[]);
    void GetBottles();
    const std::string & Label() const { return (const std::string &) *this; }
    int sum() const;
    void Show() const;
};

#endif