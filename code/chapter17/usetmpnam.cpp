// usetmpnam.cpp -- use tmpnam() function 
#include <cstdio>
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "This system can generate up to " << TMP_MAX
         << " temporary names of up to " << L_tmpnam
         << " characters.\n";
    char pszName[ L_tmpnam ] = {'\0'};
    cout << "Here are ten names:\n";
    for (int i = 0; i < 10; i++)
    {
        tmpnam( pszName );
        cout << pszName << endl;
    }
    return 0;
}