// ex6_usemove.cpp -- test class Move
// compile with move.cpp

#include <iostream>
#include "move.h"

int main()
{
    using std::cin;
    using std::cout;
    Move point;
    double a, b;
    Move mv;
    Move result;
    cout << "Enter the point of x,y position: ";
    cin >> a >> b;
    point.reset(a,b);
    point.showmove();
    cout << "Enter the move x y: ";
    cin >> a >> b;
    mv.reset(a,b);
    result = point.add(mv);
    cout << "After move, the point of position is ";
    result.showmove();
    return 0;
}