// String2.h -- definiton of String class
// version2.0
#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::istream;
using std::ostream;
class String
{
private:
        char * str;                     // pointer to string
        int len;                        // length of string
        static int num_strings;         // number of objects
        static const int CINLIM = 80;   // cin input limit
    public:
    // constructors and other methods
        String(const char * s);
        String();
        String(const String &);
        ~String();
        int length() const { return len; }
        void Stringlow();
        void Stringup();
        int has(char ch);
    // overloaded operator methods
        String & operator=(const String &);
        String & operator=(const char *);
        // String & operator+(const String &);
        char & operator[](int i);
        const char & operator[](int i) const;
    // overloaded operator friends
        friend bool operator<(const String & st1, const String & st2);
        friend bool operator>(const String & st1, const String & st2);
        friend bool operator==(const String & st1, const String & st2);
        friend istream & operator>>(istream & is, String & st);
        friend ostream & operator<<(ostream & os, const String & st);
    // static function
        static int HowMany();
    // operator + methods
        String operator+(const String & st);
        friend String operator+(const char * sar, const String & st);
        
};

#endif