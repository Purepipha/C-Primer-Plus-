//assign_st.cpp -- assignment structure
#include<iostream>
struct inflatable
{
    std::string name;
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable bouquet {"sunflowers", 0.20, 12.49};
    inflatable choice;
    cout << "bouquet: " << bouquet.name << " for $";
    cout << bouquet.price << endl;
    choice = bouquet;
    cout << "choice: " << choice.name << " for $";
    cout << choice.price << endl;
    return 0;
}
