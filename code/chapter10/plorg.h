// plorg.h -- defination of class Plorg
// version 00

#ifndef PLORG_H_
#define PLORG_H_
const int NSIZE = 20;
class Plorg
{
private:
    char name_[NSIZE];
    int CI_;
public:
    Plorg();
    Plorg(const char * name, int CI = 50);
    void setCI(int CI);
    void ShowPlorg() const;
    void setname(const char * name = "Plorga");
};
#endif