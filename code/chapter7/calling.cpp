// calling.cpp -- defining, prototyping, and calling a function
#include<iostream>
void simple();

int main()
{
    using namespace std;
    cout << "main() will call the simple() function: \n";
    simple();
    cout << "main() is finished with the simple() function.\n";
    return 0;
}

void simple()
{
    std::cout <<"I am but a simple function.\n";
}