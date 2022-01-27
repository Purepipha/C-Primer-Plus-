// pe5.cpp -- read name form file and store name to vector
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>

inline void Showname(const std::string & s) { std::cout << s << "\t"; }

int main()
{
    using namespace std;
// prototype fstream
    ifstream fin;
    ofstream fout;
// file name
    string mat_file("mat.dat");
    string pat_file("pat.dat");
    string mat_pat_file("mat_pat.dat");
// prototype vector
    vector<string> mat;
    vector<string> pat;
    vector<string> mat_pat;
// file link with fstream
    string name;                    // temp to get a line
// get name from mat.dat
    fin.open(mat_file.c_str());
    if (!fin.is_open())
    {
        cerr << "Could not open " << mat_file << endl;
        exit(EXIT_FAILURE);
    }
    while (getline(fin, name))
    {
        mat.push_back(name);
    }
    cout << "Read " << mat_file << " complete.\n";
    cout << "Mat's friends list:\n";
    for_each(mat.begin(), mat.end(), Showname);
    cout << endl;

    fin.clear();
    fin.close();

// get name from pat.dat
    fin.open(pat_file.c_str());
    if (!fin.is_open())
    {
        cerr << "Could not open " << mat_file << endl;
        exit(EXIT_FAILURE);
    }
    while (getline(fin, name))
    {
        pat.push_back(name);
    }
    cout << "Read " << pat_file << " complete.\n";
    cout << "Pat's friends list:\n";
    for_each(mat.begin(), mat.end(), Showname);
    cout << endl;
    
    fin.clear();
    fin.close();

// set_union(mat and pat)
    // before use set_union(), need to sort() two contains
    sort(mat.begin(), mat.end());
    sort(pat.begin(), pat.end());
    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), 
        insert_iterator< vector<string> >(mat_pat, mat_pat.begin()));
// restore the result to mat_pat.dat
    fout.open(mat_pat_file.c_str());
    for (auto X : mat_pat)
    {
        fout << X << endl;
    }

    fout.clear();
    fout.close();

    cout << "Done\n";
    return 0;
}