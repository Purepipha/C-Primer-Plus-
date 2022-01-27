// classic.cpp -- methods for Classic class
#include <iostream>
#include <cstring>
#include "classic.h"

// methods of Cd
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[1];
    performers[0] = '\0';
    label = new char[1];
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const
{
    using std::cout;
    using std::endl;
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
        return *this;
    else
    {
        delete [] performers;
        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);
        delete [] label;
        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
        return *this;
    }
}

// methods of Classic
Classic::Classic(const char * sg, const char * pf, const char * lb, 
        int sel, double pt) : Cd(pf, lb, sel, pt)
{
    song = new char[strlen(sg) + 1];
    strcpy(song, sg);
}

Classic::Classic(const Classic & c) : Cd(c)
{
    song = new char[strlen(c.song) + 1];
    strcpy(song, c.song);
}

Classic::Classic():Cd()
{
    song = new char[1];
    song[0] = '\0';
}

Classic::~Classic()
{
    delete [] song;
}

void Classic::Report() const
{
    std::cout << "Song: " << song << std::endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & c)
{
    if (this == &c)
        return *this;
    else
    {
        delete [] song;
        song = new char[strlen(c.song) + 1];
        strcpy(song, c.song);
        Cd::operator=(c);
        return *this;
    }
    
}