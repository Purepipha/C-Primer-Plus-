// mixtype.cpp -- some type combinations
#include<iostream>

struct antartica_year_end
{
    int year;
};

int main()
{
    antartica_year_end s1, s2 , s3;
    s1.year = 1998;
    antartica_year_end * pa = &s2;
    pa->year = 1999;
    antartica_year_end arr[3];
    arr[0].year = 2003;
    std::cout << arr->year << std::endl;
    const antartica_year_end *arp[3] = {&s1, &s2, &s3};
    std::cout << arp[1]->year << std::endl;
    const antartica_year_end* *ppa = arp;
    auto ppb = arp;
    std::cout << (*ppa)->year << std::endl;
    std::cout << (*(ppb+1))->year << std::endl;
    return 0;
}