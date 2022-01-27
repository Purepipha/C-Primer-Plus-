// String2.cpp -- methods for String class
#include <cstring>
#include <cctype>
#include "String2.h"


int String::num_strings = 0;
// constructors and other methods
String::String()
{
    len = 0;
    str = new char[len + 1];
    *str = '\0';
    num_strings++;
}

String::String(const char * s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String(const String & s)
{
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    num_strings++;
}

String::~String()
{
    --num_strings;
    delete [] str;
}

void String::Stringlow()
{
    for(int i = 0; i < len; i++)
        str[i]=tolower(str[i]);     //
}

void String::Stringup()
{
    for(int i = 0; i < len; i++)
        str[i]=toupper(str[i]);     //
}

int String::has(char ch)
{
    int count = 0;
    for(int i = 0; i < len; i++)
        if(str[i] == ch)
            ++count;
    return count;
}

String & String::operator=(const String & s) 
{
    if(this == &s)
        return *this;
    len = s.len;
    delete [] str;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}

String & String::operator=(const char * s) 
{
    len = strlen(s);
    delete [] str;
    str = new char[len + 1];
    strcpy(str, s);
    return * this;
}
// String & String::operator+(const String & s)
// {
//     String temp = *this;
//     delete [] str;
//     len += s.len;
//     str = new char[len + 1];
//     str = strcat(temp.str, s.str);
//     return *this;
// }
char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

String  operator+(const String & st1, const String & st2)
{
    char * temp = new char[st1.len + st2.len + 1];
    // temp = strcat(st1.str,st2.str);
    int i;
    for(i = 0; i < st1.len; i++)
        temp[i] = st1.str[i];
    for(; i < st1.len + st2.len + 1; i++)
    {
        temp[i] = st2.str[i - st1.len];
    }
    temp[st1.len + st2.len + 1] = '\0';
    return String(temp);
}

bool operator<(const String & st1, const String & st2)
{
    return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if(is)
        st = temp;
    while(is && is.get() != '\n')
        continue;
    return is;
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

int String::HowMany()
{
    return num_strings;
}