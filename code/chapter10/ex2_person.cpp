// ex2_person.cpp -- test the class Person
#include <iostream>
#include "person.h"

int main()
{
    using std::cout;
    using std::endl;
    Person one;                         // use default constructor
    Person two("Smythecraft");          // use #2 with one default argument
    Person three("Dimwiddy", "Sam");    // use #2, no defaults
    one.Show();
    cout << endl;
    one.FormalShow();
    // etc. for two and three
    two.Show();
    cout << endl;
    two.FormalShow();
    three.Show();
    cout << endl;
    three.FormalShow();
}