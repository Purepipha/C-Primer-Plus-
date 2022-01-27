// dma.cpp -- methods for Class DMAABC
#include <cstring>
#include "dma.h"

// methods for DMAABC class
DMAABC::DMAABC(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

DMAABC::DMAABC(const DMAABC & rda)
{
    label = new char[strlen(rda.label) + 1];
    strcpy(label, rda.label);
    rating = rda.rating;
}

DMAABC::~DMAABC()
{
    delete [] label;
}

DMAABC & DMAABC::operator=(const DMAABC & rda)
{
    if (this == &rda)
        return *this;
    else
    {
        delete [] label;
        label = new char[strlen(rda.label) + 1];
        strcpy(label, rda.label);
        rating = rda.rating;
        return *this;
    }
}

void DMAABC::View() const
{
    std::cout << "Lable: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

// methods for BaseDMA class
void baseDMA::View() const
{
    DMAABC::View();
}

// methods for lacksDMA class
lacksDMA::lacksDMA(const char * c, const char * l, int r) : DMAABC(l, r)
{
    strcpy(color, c);
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : DMAABC(rs)
{
    strcpy(color, c);
}

void lacksDMA::View() const
{
    std::cout << "Color: " << color << std::endl;
    DMAABC::View();
}

// derived class with DMA

hasDMA::hasDMA(const char * s, const char * l, int r) : DMAABC(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) : DMAABC(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : DMAABC(hs)
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    else
    {
        DMAABC::operator=(hs);
        delete [] style;
        style = new char[strlen(hs.style) + 1];
        strcpy(style, hs.style);
        return * this;
    }
}

void hasDMA::View() const
{
    std::cout << "Style: " << style << std::endl;
    DMAABC::View();
}