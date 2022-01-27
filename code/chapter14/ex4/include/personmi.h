// personmi.h -- definition Person class and using inheritance
#ifndef PERSONMI_H_
#define PERSONMI_H_
#include <string>

// class Person definition
class Person
{
private:
    std::string firstname;
    std::string lastname;
protected:
    void Get();
    void Data() const;
public:
    Person(const std::string & fn, const std::string ln) : firstname(fn), lastname(ln) { }
    Person() { }
    virtual ~Person() { }
    virtual void Set();
    virtual void Show() const = 0;
    // virtual void Draw() const;
};

class Gunslinger : virtual public Person
{
private:
    double guns;
    int noches;
protected:
    void Get();
    void Data() const;
public:
    Gunslinger() { }
    Gunslinger(const std::string & fn, const std::string ln, double g = 0.0, int n = 0) :
    Person(fn, ln), guns(g), noches(n) { }
    Gunslinger(const Person & p, double g, int n) : Person(p), guns(g), noches(n) { }
    Gunslinger(const Gunslinger & g) : Person(g), guns(g.guns), noches(g.noches) { }
    virtual double Draw() const { return guns; }
    virtual void Set();
    virtual void Show() const;
};

class Card
{
protected:
    enum {heart, dianmond, spade, club};
    enum {CTypes = 4,PNums = 13};
private:
    static char * pc[CTypes];
    static char * pp[PNums];
    int pcolor;
    int poke;
public:
    Card();
    Card(int c, int p) : pcolor(c), poke(p) { }
    Card(const Card & c) : pcolor(c.pcolor), poke(c.poke) { }
    void Show() const;
};

class PokerPlayer : virtual public Person
{
private:
    Card card;
protected:
    void Get() {};
    void Data() const;
public:
    PokerPlayer() { }
    PokerPlayer(const std::string & fn, const std::string ln, const Card & c) : 
    Person(fn,ln), card(c) {}
    PokerPlayer(const Person & p, const Card & c) : Person(p), card(c) { }
    PokerPlayer(const Person & p) : Person(p){ }
    PokerPlayer(const std::string & fn, const std::string ln) : 
    Person(fn,ln) { }
    PokerPlayer(const PokerPlayer & pp) : Person(pp), card(pp.card) { }
    virtual Card Draw() const { Card c; return c; }
    virtual void Set();
    virtual void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude() { }
    BadDude(const std::string & fn, const std::string ln, const Card & c ,double g = 0.0, int n = 0) :
    Person(fn, ln), Gunslinger(fn, ln, g, n), PokerPlayer(fn, ln, c) { }
    BadDude(const Person & p, const Card & c ,double g = 0.0, int n = 0) :
    Person(p), Gunslinger(p, g, n), PokerPlayer(p, c) { }
    BadDude(const Person & p,double g, int n) :
    Person(p), Gunslinger(p, g, n), PokerPlayer(p) { }
    BadDude(const Gunslinger & g, const Card & c) : Person(g), Gunslinger(g), PokerPlayer(g, c) { }
    BadDude(const PokerPlayer & pp, double g, int n) : Person(pp), Gunslinger(pp, g, n), PokerPlayer(pp) { }
    BadDude(const BadDude & bd) : Person(bd), Gunslinger(bd), PokerPlayer(bd) { }
    virtual void Set();
    virtual void Show() const;
    double Gdraw() const;
    Card Cdraw() const;
};
#endif