// person.h -- protype class Person
#ifndef PERSON_H_
#define PRESON_H_

#include <string>

class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person(){lname = "";fname[0] = '\0';};                  // #1
    Person(const std::string & ln, const char * fn = "Heyyou");   // #2
// the following methods display lname and fname
    void Show()const;           // firstname lastname format
    void FormalShow() const;    // lastname, firstname format
};



#endif