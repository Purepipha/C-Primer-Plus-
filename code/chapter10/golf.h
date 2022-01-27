// golf.h -- definate Golf class

# ifndef GOLF_H_
# define GOLF_H_

class Golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf();
    Golf(const char * name, int hc);
    ~Golf();
    int setgolf();
    void set_handicap(int hc);
    void Show() const;
};
# endif

