#4.1 
    char actor[30];
    shott betsie[100];
    float chuck[13];
    long double dipsea[64];
#4.2
    array<char,30> actor;
    array<short,100> betsie;
    array<float,13> chuck;
    array<long double,64> dipsea;
#4.3
    int arr[5] = {1, 3, 5, 7, 9};
#4.4 
    int even = arr[0] + arr[4];
#4.5
    std::cout << ideas[1] << std::endl;
#4.6
    char strar[20] = "cheeseburger";
#4.7
    string str = "Waldorf Salad";
#4.8
    struct fish
    {
        char kind[20];
        int weight; //
        double length;//inch
    };
#4.9
    fish tuna {"tuna", 30, 14.3};
#4.10
    enum Response{No, Yes, Maybe};
#4.11
    double ted = 2.1;
    double* p;
    p = &ted;
    // or double* p = &ted;
#4.12
    float treacle[10];
    float* ptr = treacle;//or float* ptr = &treacle[0];
    using namespace std;
    cout << *ptr << *(ptr + 9);//<font color=red> cout << ptr[0] << ptr[9] <<endl;</font>
#4.13
    #include<iostream>
    int main()
    {
        using namespace std;
        int n;
        cout << "Enter an integer:"
        cin >> n;
        int* pt = new int[n];
        delete [] pt;
        return 0;
    }
    #include<iostream>
    #include<vector>
    int main()
    {
        using namespace std;
        int n;
        cout << "Enter an integer:"
        cin >> n;
        vector<int,n> v1;
        return 0;
    }
#4.14
    cout << (int *) "Home of the jolly bytes";
    effective, will output Home of the jolly bytes.
#4.15
    fish* tuna = {"tuna", 20, 15.2};
    cout << tuna->kind << tuna->weight << tuna->length;
#4.16
    改变为 cin >> address,将无法读全地址，遇到空格即结束读取。
#4.17
    #include<string>
    #include<vector>
    #include<array>
    int main()
    {
        const int n = 10;
    ~~vector<std::string,n> v1~~;
        array<std::string,n> v2;
    }