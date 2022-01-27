// cow.cpp -- methods for Cow class
#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
    name[0] = '\0';
    hobby = NULL;
    weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name, nm);
    hobby = new char [strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    strcpy(name, c.name);
    hobby = new char [strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    strcpy(name, c.name);
    hobby = new char [strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const
{
    std::cout << "Name: " << name << ", hobby: " << hobby << ", weight = " << weight << '\n';
}