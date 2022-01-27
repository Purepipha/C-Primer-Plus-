// ex3.cpp -- using struct with function
#include<iostream>
struct box
{
    char maker[40];
    float height;
	float width;
	float length;
	float volume;
};

void show(box b);
void set_volume(box *);

int main()
{
    using namespace std;
    box b1;
    cout << "Enter the maker: ";
    cin.getline(b1.maker,40);
    cout << "Enter the box of hight: ";
    cin >> b1.height;
    cout << "Enter the box of width: ";
    cin >> b1.width;
    cout << "Enter the box of length: ";
    cin >> b1.length;
    set_volume(&b1);
    show(b1);
    return 0;
}

void show(box b)
{
    using namespace std;
    cout << "Maker: " << b.maker << endl;
    cout << "Hight: " << b.height << endl;
    cout << "Width: " << b.width << endl;
    cout << "length: " << b.length << endl;
    cout << "Volume: " << b.volume << endl;
}
void set_volume(box *pb)
{
    pb->volume = pb->height * pb->width * pb->length;
}