// ex4_usestack.cpp -- use stack class to store the custormer
// compile with stack.cpp
#include <iostream>
#include <cstring>
#include "stack.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    Stack st;
    customer ct;
    double sum_pm = 0;
    int count = 0;
    cout << "Enter the customer name(enter empty string to quit): ";
    cin.getline(ct.fullname,NSIZE);
    while (strcmp(ct.fullname, ""))
    {
        cout << "Enter the payment: ";
        while(!(cin >> ct.payment))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input, please input a number: ";
        }
        cin.get();
        st.push(ct);
        if(st.isfull())
            break;
        cout << "Enter next customer name(enter empty string to quit): ";
        cin.getline(ct.fullname,NSIZE);
    }
    while(!st.isempty())
    {
        ++count;
        st.pop(ct);
        sum_pm += ct.payment;
        cout << count  << " customers' total payment is " << sum_pm << endl;
    }
    cout << "Bye\n";
    return 0;
}