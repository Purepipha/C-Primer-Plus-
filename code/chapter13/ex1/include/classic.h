// classic.h -- definition of Classic class

#ifndef CLASSIC_H_
#define CLASSIC_H_
// base class
class Cd {  // repersents a CD disk
private:
    char performers[50];
    char label[20];
    int selections;     // number of selections
    double playtime;    // playing time in minutes
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd();
    virtual void Report() const;    // reports all CD data
};

class Classic : public Cd
{
private:
    char song[60];
public:
    Classic(char * fn, char * pf, char * lb, int sel, double pt);
    Classic();
    virtual void Report() const;
};


#endif