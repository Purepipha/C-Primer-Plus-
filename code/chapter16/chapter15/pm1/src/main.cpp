// usetv.cpp -- test Tv and Remote class
// compile with tv.cpp
#include <iostream>
#include "tv.h"
int main()
{
	using std::cout;
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();

    Remote grey;

    grey.setchannel(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.setchannel(s58, 28);
    cout << "\n58\" settings:\n";
	s58.settings();				
	grey.display_mode();
	grey.set_rmode(s58);		// test set_rmode
    grey.display_mode();
    return 0;
}