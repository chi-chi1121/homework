#include<iostream>
using namespace std;
class PrimeNumber /*define class primenumber*/
{
public:
	PrimeNumber();/*constructor*/
	PrimeNumber(int);
	int getPrime() { return prime; };
	PrimeNumber operator++();/*overloading operator++ prefix*/
	PrimeNumber operator++(int);/*overloading operator++ postfix*/
	PrimeNumber operator--();/*overloading operator-- prefix*/
	PrimeNumber operator--(int);/*overloading operator-- postfix*/
	friend ostream& operator<<(ostream&, const PrimeNumber&);/*output operator overloading*/

private:
	int prime;
	bool isprime(int); /*test if it's a prime number*/
};


int main() {/*test funtion*/
	PrimeNumber a;
	cout << "PrimeNumber, a: " << a << endl;
	cout << "Using prefix ++ operator on a: " << ++a << endl;
	cout << "Using prefix -- on a: " << --a << endl;
	PrimeNumber c;
	cout << "Using postfix ++ operator on c: " << c++ << endl;
	cout << "now c is:" << c.getPrime() << endl;

	PrimeNumber d;
	cout << "Using postfix -- operator on d: " << d-- << endl;
	cout <<"now d is:" << d.getPrime() << endl;

	PrimeNumber b(13);
	cout << " PrimeNumber with a prime, b: " << b << endl;
	cout << "Using prefix ++ operator on b: " << ++b << endl;
	cout << "Using prefix -- on b: " << --b << endl;
	cout << "Using postfix ++ operator on b: " <<b++ << endl;
	cout << "Using postfix -- operator on b: " << b-- << endl;
	return 0;
}
bool PrimeNumber::isprime(int temp){ /*test if it's a prime number*/
	bool isP = false;
	int count=0;
		for (int i = 2; i < temp; i++) {
			if (temp % i == 0) {
				count++;
			}
		}
		if (count == 0) {
			isP = true;
		}/*if it's a prime return true*/
		return isP;
}
PrimeNumber::PrimeNumber():prime(1){}

PrimeNumber::PrimeNumber(int p):prime(p){}

PrimeNumber PrimeNumber:: operator++(){/*overloading operator++ prefix*/
	int temp = prime + 1;
	while (!isprime(temp)) {
		temp++;
	}
	return PrimeNumber(temp);
}
PrimeNumber PrimeNumber:: operator++(int) {/*overloading operator++ postfix*/
	int origianl=prime, temp = prime+1;
	while (!isprime(temp)) {
		temp++;
	}
	prime = temp;
	return PrimeNumber(origianl);
}

PrimeNumber PrimeNumber:: operator--() {/*overloading operator-- prefix*/
	int temp = prime-1;
	while (!isprime(temp) && temp > 0) {
		temp--;
	}
	return PrimeNumber(temp);
}
PrimeNumber PrimeNumber:: operator--(int) {/*overloading operator-- postfix*/
	{
		int origianl = prime, temp = prime-1;
		while (!isprime(temp)&&temp>0) {
			temp--;
		}
		prime = temp;
		return PrimeNumber(origianl);
	}
}

ostream& operator<<(ostream& output, const PrimeNumber& p) {/*output operator overloading*/
	output << p.prime;
	return output;
}