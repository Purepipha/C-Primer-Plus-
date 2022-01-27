// coordin.h -- structure templates and function protypes
// structure template
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

// protypes

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif

