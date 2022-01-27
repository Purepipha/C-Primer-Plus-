// tv.h -- class definition for Tv class and Remote class
// friend class

#ifndef TV_H_
#define TV_H_
class Remote;
class Tv
{
private:
    int state;
    int channel;
    int maxchannel;
    int volume;
    int mode;
    int input;
public:
    friend class Remote;
    enum {Off, On};
    enum {MaxChannel = 125};
    enum {MinVol, MaxVol = 25};
    enum {Antenna, Cable};
    enum {TV, DVD};
    Tv(int s = Off, int mc = MaxChannel) : state(s), channel(1), 
        maxchannel(mc), volume(5), mode(Cable), input(TV) { }
    void onoff() { state = (state == On) ? Off : On;}
    bool isOn() { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Cable) ? Antenna : Cable; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void set_rmode(Remote & r);     // set mode of Remote
    void settings() const;
};

class Remote
{
private:
    int mode;       // control TV or DVD
    int r_mode;     // control Normal or Interactive
public:
    friend class Tv;
    enum {Normal, Interactive};
    Remote(int m = Tv::TV, int rm =Normal) : mode(m), r_mode(rm) { }
    void onoff(Tv & t) { t.onoff(); }
    bool volup(Tv & t) { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t) { t.chandown(); } 
    void setchannel(Tv & t, int chan) { t.channel = chan; }
    void set_mode(Tv & t) { t.set_mode(); }
    void set_input(Tv & t) { t.set_input(); }
    void set_rmode(Tv & t);
    void display_mode() const;
};

#endif