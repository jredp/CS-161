#include "ShoppingCart.hpp"
#include <string>

using std::cout;
using std::endl;

int main()
{
	Item a("affidavit", 179.99, 12); //2159.88
	Item b("Bildungsroman", 0.7, 20); //14
	Item c("capybara", 4.5, 6); //27
	Item d("dirigible", 0.05, 16); //0.80
	ShoppingCart sc1;
	sc1.addItem(&a);
	sc1.addItem(&b);
	sc1.addItem(&c);
	sc1.addItem(&d);
	double diff = sc1.totalPrice();
	
	cout << diff << endl;
	cout << a.getName() << endl;
	cout << a.getPrice() << endl;
	cout << a.getQuantity() << endl;
	
	//system("PAUSE");
	return 0;
}