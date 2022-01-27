// ex8_uselist.cpp -- test class List
// compile with list.cpp

#include <iostream>
#include "list.h"
void Show(Item & item);
int main()
{
    using std::cout;
    Item num;
    List ld1;
    double arr[10] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
    if(ld1.isempty())
        cout << "List of double is empty\n";
	List ld2;
	for(int i = 0; i < 10; i++)
		ld2.enlist(arr[i]);
    if(ld2.isfull())
        cout << "List of double is full\n";
    ld2.visit(Show);
    cout << '\n';
    cout << "Before add data:\n";
    ld1.visit(Show);
    cout << '\n';
    cout << "Enter the number you want to add: ";
    std::cin >> num;
    ld1.enlist(num);
    cout << "After add data:\n";
    ld1.visit(Show);
    cout << '\n';
    cout << "Bye\n";
    return 0;
}
void Show(Item & item)
{
    std::cout << item << " "; 
}