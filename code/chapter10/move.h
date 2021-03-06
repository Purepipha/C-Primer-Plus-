// move.h -- defination of Move class for move.cpp
// version

#ifndef MOVE_H_
#define MOVE_H_

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0.0,double b = 0.0);    // sets x, y to a, b
    void showmove() const;                  // shows current x, y values
    Move add(const Move & m) const;
// this function adds x of m to x of invoking object to get new x,
// adds y to y of invokeing object to get new y, create a new
// move object initialized to new x, y values and returns it
    void reset(double a = 0.0, double b = 0.0);  // resets x,t to a,b
};
#endif