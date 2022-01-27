// usevintageport.cpp -- test VintagePort class
// compile with vintageport.cpp
#include "vintageport.h"

int main()
{
	Port gal("Gallo", "tawny", 20);
	Port * pp;
	VintagePort vp("Chateau Margaux", 10, "The Noble",1999);
	VintagePort * pvp;
	pp = &vp;
	pvp = &vp;
	cout << "Output with Show():\n";
	pp->Show();
	pp = &gal;
	pp->Show();
	cout << "Take out 30 bottles:\n"; 
	*pp -= 30;
	pp->Show();
	cout << "After add 10 bottles:\n";
	*pp += 10;
	pp->Show();
	pp = &vp;
	cout << "Output with operator<< :\n";
	cout << "Object: " << vp << endl;
	cout << "Pointer Port: " << *pp << endl;
	cout << "Pointer VintagePort: " << *pvp << endl;
	return 0;
}