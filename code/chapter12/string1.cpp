// string1.cpp -- String class methods
#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;
String::String(const char * s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 0;
    str = new char[len + 1];
    *str = '\0';
    num_strings++;
}

String::String(const String & st)
{
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    num_strings++;
}

String::~String()
{
    --num_strings;
    len = 0;
    delete[]str;
}

String & String::operator=(const String & st)
{
    if(*this == st)
    {
        return *this;
    }
    len = st.len;
    delete[]str;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char *sar)
{
    len = strlen(sar);
    delete []str;
    str = new char[len + 1];
    strcpy(str, sar);
    return *this;
}

char & String::operator[](int i)
{
    return *(str + i);
}

const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String & st1, const String & st2)
{
    if(strcmp(st1.str,st2.str) < 0)
        return true;
    else
        return false;
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}

// input is important 
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
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