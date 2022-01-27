// ex1.cpp -- using default argument
#include<iostream>
int count = 0; // count the times of call showstr() function
void showstr(const char * s, int n = 0);

int main()
{
    const char * ps = {"I like C++!"};
    for(int j = 0; j < 5; j++)
    {
        showstr(ps);
        showstr(ps,1);
    }
    return 0;
}

void showstr(const char * s, int n)
{
    using std::cout;
    ++count;
    if(n == 0)
        cout << s << "\n";
    else
    {
        for(int i = 0; i < count; i++)
            cout << s << " ";
        cout << "\n";
    }
}