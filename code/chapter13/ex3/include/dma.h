// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
# include <iostream>
// ABC Class using DMA
class DMAABC
{
private:
    char * label;
    int rating;
public:
    DMAABC(const char * l = "null", int r = 0);
    DMAABC(const DMAABC & rda);
    virtual ~DMAABC();
    DMAABC & operator=(const DMAABC & rda);
    virtual void View() const =0;
};

// BaseDMA class definition
class baseDMA : public DMAABC
{
public:
    baseDMA(const char * l = "null", int r = 0) : DMAABC(l, r) { }
    virtual void View() const;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public DMAABC
{
private:
    enum{ COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    virtual void View() const;
};

// derived class with DMA
class hasDMA : public DMAABC
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
            int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    virtual void View() const;
};
#endif