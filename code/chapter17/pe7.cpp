// pe7.cpp 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Store
{
private:
    std::ofstream & os;
public:
    Store(std::ofstream & fo) : os(fo){ }
    void operator()(const std::string & s);
};
void Store::operator()(const std::string & s)
{
    auto len = s.size();                            // get length of string
    os.write((char *)&len, sizeof(std::size_t));    // write len
    os.write(s.data(), len);                        // write string data
}

int GetStrs(std::ifstream & is, std::vector<std::string> & vs)
{
    size_t len;                                     // to store the length of string
    int j = 0;
    while (is.read((char *)&len, sizeof(std::size_t)))
    {
        char temp[len + 1];
        for (int i = 0; i < len; i++)
        {
            is.read(&temp[i], 1);                   // get every char
        }
        temp[len] = '\0';
        vs.push_back(std::string(temp));            // add string to vector
        j++;
    }
    return j;                                       // return the number of strings
    
}

void ShowStr(const std::string & s) { std::cout << s << std::endl;};
int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

// acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

// stroe in a file
    ofstream fout("string.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

// recover file contents
    vector<string> vistr;
    ifstream fin("string.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}