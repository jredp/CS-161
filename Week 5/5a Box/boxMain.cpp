#include <iostream>
#include "Box.hpp"
using namespace std;

int main()
{
	Box Test1;
	cout << "Volume: " << Test1.getVolume() << endl;
	cout << "Surface Area: " << Test1.getSurfaceArea() << endl;
		
	Box Test2(1,2,3);
	cout << "Volume: " << Test2.getVolume() << endl;
	cout << "Surface Area: " << Test2.getSurfaceArea() << endl;

	Box Test3(2, 2, 2);
	cout << "Volume: " << Test3.getVolume() << endl;
	cout << "Surface Area: " << Test3.getSurfaceArea() << endl;
	Test3.setHeight(3);
	Test3.setLength(3);
	Test3.setWidth(3);
	cout << "Volume: " << Test3.getVolume() << endl;
	cout << "Surface Area: " << Test3.getSurfaceArea() << endl;
	
	return 0;
}