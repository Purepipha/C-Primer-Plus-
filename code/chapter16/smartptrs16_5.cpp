// smartptrs.cpp -- using three kinds of smart pointers
// requiress support of C++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s)
        { std::cout << "Object created!\n"; }
    ~Report() { std::cout << "Object deleted!\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main()
{
    {
        std::auto_ptr<Report> ps (new Report("using auto_ptr"));
        ps->comment();  // use -> to invoke a member function
    }
    {
        std::shared_ptr<Report> pd (new Report("using auto_ptr"));
        pd->comment();
    }
    {
        std::unique_ptr<Report> pd (new Report("using auto_ptr"));
        pd->comment();
    }
    return 0;
}