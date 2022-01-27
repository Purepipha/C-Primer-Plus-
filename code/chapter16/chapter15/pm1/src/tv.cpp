// tv.cpp -- methods for Tv class and Remote class
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
    if (volume < MaxVol)
    {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if (volume > MinVol)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < MaxVol)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = MaxChannel;
}

void Tv::set_rmode(Remote & r)
{
    if (isOn())
        r.r_mode = (r.r_mode == Remote::Normal) ? 
            Remote::Interactive : Remote::Normal;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
             << (mode == Antenna ? "antenna" : " cable") << endl;
        cout << "Input = "
             << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Remote::set_rmode(Tv & t)
{
    t.set_rmode(* this);
}

void Remote::display_mode() const
{
    using std::cout;
    using std::endl;
    cout << "Remote is " << (r_mode == Normal ? "Normal" : "Interactive") << endl;
}