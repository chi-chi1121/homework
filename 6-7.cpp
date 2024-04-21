#include <iostream>
using namespace std;
class pizza /*define class pizza*/
{
public:
	void outputDescription();
	void mutator();
	void accessor();
	void computePrice();
private:
	string type,size;
	int topping;

};

int main() {/*main function*/
	pizza pizza1;/*variable:pizza1*/
	pizza1.mutator();
	pizza1.outputDescription();
	pizza1.computePrice();
	return 0;
}

void pizza::mutator() {/*the mutator function*/
	cout << "enter the type(deep_dish / hand_tossed / pan)¡Bsize(small / medium / large) and the number of topping>>";
	cin >> type >> size >> topping;
}
void pizza::accessor() {/*the accessor function*/
	cout << type << size << topping;
}
void pizza::outputDescription(){ /*the output function*/
	cout << "the pizza is " << type << " and " << size << " and the number of topping is " << topping << endl;
}
void pizza::computePrice() {/*the compute price function*/
	if (size == "small") {
		cout << "the price is " << 10 + topping * 2;
	}
	else if (size == "medium") {
		cout << "the price is " << 14 + topping * 2;
	}
	else if (size == "large") {
		cout << "the price is " << 17 + topping * 2;
	}
}