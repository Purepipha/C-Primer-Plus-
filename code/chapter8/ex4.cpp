// ex4.cpp -- write the rest procedures
#include<iostream>
using namespace std;
#include<cstring>
struct stringy
{
    char * str;
    int ct;
};

// prototypes for set(), show() and show() go here
void set(stringy &,char []);
void show(const stringy &, int n = 1);
void show(const char [], int n = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing); // first argument is a reference,
                // allocates space to hold copy of testing,
                // sets str memebr of beany to point to the
                // new block, copies testing to new block,
                // and sets ct member of beany
    show(beany);        // prints member string once
    show(beany, 2);     // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);      // prints testing string once
    show(testing, 3);   // prints testing string thrice
    show("Done!");
    delete [] beany.str;
    return 0;
}

void set(stringy & s,char cs[])
{
    s.ct = strlen(cs);
    s.str = new char[s.ct + 1];
    strcpy(s.str,cs);
}

void show(const stringy & s, int n)
{
    for(int i = 0; i < n; i++)
        cout << s.str << endl;
}

void show(const char cs[], int n)
{
    for(int i = 0; i < n; i++)
        cout << cs << endl;
}