// personmi.cpp -- methods for Person claa
#include <iostream>
#include <cstdlib>      // for rand() and srand()
#include <ctime>
#include "personmi.h"

using std::cin;
using std::cout;
using std::endl;
// methods for Person class
void Person::Get()
{
    cout << "Enter firstname: ";
    cin >> firstname;
    cout << "Enter lastname: ";
    cin >> lastname;
}

void Person::Data() const
{
    cout << "Name: " << lastname << ", " << firstname << endl;
}

void Person::Set()
{
    Get();
}

void Person::Show() const
{
    Data();
}

// methods for Gunlinger class
void Gunslinger::Get()
{
    cout << "Enter the seconds of taking guns: ";
    cin >> guns;
    cout << "Enter the number of noches: ";
    cin >> noches;
}
void Gunslinger::Data() const
{
    cout << "Seconds: " << guns << endl;
    cout << "Noches: " << noches << endl;
}
void Gunslinger::Set()
{
    cout << "Category gunslinger:\n";
    Person::Get();
    Get();
}
void Gunslinger::Show() const
{
    Person::Data();
    Data();
}

// methods for Card class
char * Card::pc[CTypes] = {"heart", "dianmond", "spade", "club"};
char * Card::pp[PNums] = {"A", "2", "3", "4", "5", "6", "7", "8", 
                            "9", "10", "J", "Q", "K"};
Card::Card()
{
    srand(time(0));
    pcolor = rand() % 4;
    poke = rand() % 13;
}

void Card::Show() const
{
    cout << "Card: " << pc[pcolor] << ' ' << pp[poke] << endl;
}

// methods for PokerPlayer class
void PokerPlayer::Data() const
{
    card.Show();
}

void PokerPlayer::Set()
{
    cout << "Category pokeplayer\n";
    Person::Get();
    Get();
}
void PokerPlayer::Show() const
{
    Person::Show();
    card.Show();
}

// methods for BadDude class
void BadDude::Set()
{
    cout << "Category baddude\n";
    Person::Get();
    Gunslinger::Get();
    PokerPlayer::Get();
}
void BadDude::Show() const
{
    Person::Data();
    Gunslinger::Data();
    PokerPlayer::Data();
}
double BadDude::Gdraw() const
{
    return Gunslinger::Draw();
}
Card BadDude::Cdraw() const
{
    return PokerPlayer::Draw();
}