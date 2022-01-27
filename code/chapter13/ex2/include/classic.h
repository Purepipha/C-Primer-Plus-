// classic.h -- definition of Classic class

#ifndef CLASSIC_H_
#define CLASSIC_H_
// base class
class Cd {  // repersents a CD disk
private:
    char * performers;
    char * label;
    int selections;     // number of selections
    double playtime;    // playing time in minutes
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;    // reports all CD data
    Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
    char * song;
public:
    Classic(const char * sg, const char * pf, const char * lb, int sel, double pt);
    Classic(const Classic & c);
    Classic();
    ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & c);
};


#endif