#include<iostream>
using namespace std;
class complex {
public:
	complex(); /*constructor*/
	complex(double, double);
	complex(double);
	double getReal() const { return real; }; /*accessor*/
	double getImaginary() const { return imaginary; };
	friend const complex operator +(const complex& c1, const complex c2);/*overloaded operator*/
	friend const complex operator -(const complex& c1, const complex c2);
	friend const complex operator *(const complex& c1, const complex c2);
	friend bool operator ==(const complex& c1, const complex c2);
	friend ostream& operator <<(ostream& output, complex& c1);
	friend istream& operator >>(istream& input, complex& c1);
private:
	double real;
	double imaginary;
};
int main() {/*Test function*/
	complex first(0,0), second(10, 20), third(2), fourth, fifth;
	cout << "Default constructor complex: " << first.getReal() << " " << first.getImaginary() << endl;
	cout << "Two double constructor complex : " << second.getReal() << " " << second.getImaginary() << endl;
	cout << "One double constructor complex: " << third.getReal() << " " << third.getImaginary() << endl;
	fourth = second + third;
	cout << "Adding second and third complex: " << fourth.getReal() << " " << fourth.getImaginary() << endl;
	fourth = second - third;
	cout << "Subtracting second and third complex: " << fourth.getReal() << " " << fourth.getImaginary() << endl;
	fourth = second * third;
	cout << "Multiplying second and third complex: " << fourth.getReal() << " " << fourth.getImaginary() << endl;
	cout << "Displaying complex numbers with cout: " << endl << first << endl << second << endl << third << endl << fourth<<endl;
	cout << "Enter a complex number: "<<endl;
	cin >> fifth;
	cout << "You entered: " << fifth << endl;
	return 0;

}
complex::complex() {}/*constructor*/
complex::complex(double r, double i) :real(r), imaginary(i) {}
complex::complex(double r) :real(r), imaginary(0) {}
const complex operator +(const complex& c1, const complex c2) {/*overloaded operator:real part + real part,imaginary part + imaginary part*/
	return complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}
const complex operator -(const complex& c1, const complex c2) {/*overloaded operator:real part - real part,imaginary part - imaginary part*/
	return complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
}
const complex operator *(const complex& c1, const complex c2) {/*overloaded operator:real part * real part,imaginary part * imaginary part*/
	return complex(c1.real * c2.real, c1.imaginary * c2.imaginary);
}
bool operator ==(const complex& c1, const complex c2) {/*if the first complex number equal to another one*/
	if (c1.imaginary==c2.imaginary&&c1.real==c2.real){
		return true;
	}
	else {
		return false;
	}
}
ostream& operator <<(ostream& output, complex& c1) { /*overloaded output operator*/
	if (c1.imaginary == 0) {
		output << c1.real;
	}
	else if (c1.imaginary != 0) {
		if (c1.real != 0) {
			if (c1.imaginary < 0) {
				output << c1.real << "-" << abs(c1.imaginary) << "i";
			}
			else { output << c1.real << "+" << c1.imaginary << "i"; }
		}
		else if (c1.real == 0) {
			output << c1.imaginary << "i";
		}
	}
	return output;
}
istream& operator >>(istream& input, complex& c1) {/*overloaded input operator*/
	char plus, i;
	int error = 0;
	cout << "according to the form: a+bi or a-bi" << endl;
	do
	{
		error = 0;
		input >> c1.real >> plus >> c1.imaginary >> i;
		if (i != 'i') {
			error = 1;
			cout << "error enter again";
		}
	} while (error == 1);

	if (plus == '-')
	{
		c1.imaginary *= -1;
	}
	return input;
}