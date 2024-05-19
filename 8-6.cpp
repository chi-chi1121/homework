#include <iostream>
#include<math.h>
using namespace std;
class MyInteger
{
public:
	MyInteger();/*default constrcture*/
	void setnumber(int n) { number = n; };/*mutator*/
	int getnumber() { return number; };/*accessor*/
	int operator[](int index);/*overloaded operator*/

private:
	int number;
};
int main() {/*test function*/
	MyInteger a;
	cout << a.getnumber();
	for(int i=3;i>=0;i--)
	{
		cout << a[i]<<" ";
	}
	cout << endl;
	a.setnumber(5231);
	cout << a.getnumber();
	for (int i = 4; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	return 0;
}
MyInteger::MyInteger() :number(481) {}/*default number is 481*/

int MyInteger:: operator [](int index) {/*overloaded operator*/
	int temp, size=0;
	temp = number;
	if (temp == 0) {
		size = 1;
	}
	else{
		do /*calculate the size of the number*/
		{
			temp /= 10;
			size++;

		} while (temp>0);
	}
	if(index<size)
	{/*get the digit you want*/
		temp = number;
		temp %= (int)pow(10, index + 1);
		temp /= pow(10, index);
	}
	else if (index >= size) {/*if out of range return -1*/
		return -1;
	}
	return temp;
}