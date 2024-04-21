#include <iostream>
using namespace std;

class weigth  /*define class weight*/
{
public:
	void accessor();/*accessor*/
	void setWeightPound(double p);/*mutator*/
	void setWeightKilogram(double p);
	void setWeightOunce(double p);
private:
	double pound, kg, ounce;
};

int main() {
	weigth weight1;
	double pound;
	cout << "enter the weigth in pound>>";
	cin >> pound;
	weight1.setWeightPound(pound);/*test func*/
	weight1.setWeightKilogram(pound);
	weight1.setWeightOunce(pound);
	weight1.accessor();
	return 0;
}

void weigth::accessor() {/*define func*/
	cout << "the weigth in pound: " << pound << endl<< "in kilogram: " << kg <<endl<< "in ounce: " << ounce;
}

void weigth::setWeightPound(double p) {
	pound = p;
}

void weigth::setWeightKilogram(double p) {
	kg = p / 2.21;
}

void weigth::setWeightOunce(double p) {
	ounce = p * 16;
}