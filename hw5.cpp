#include <iostream>
using namespace std;
int main() {
	int num[10], pin[5] = { 1,2,3,4,5 }, input, correct = 1, digit;/*�ܼ�:�H���ƦC�BPIN�X�B��J�B�O�_���T�B���Ʀr*/
	srand(time(0));/*�]�w�üƺؤl*/
	for (int i = 0; i < 10; i++) {/*�]�w�H���ƦC*/
		num[i] = rand() % 3 + 1;
	}
	cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "NUM: ";
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	cout << "enter the num>>";
	cin >> input;/*��J�Ʀr*/
	for (int i = 4; i >= 0; i--) {/*�v���ˬd�O�_�ŦX*/
		digit = input % 10;
		input = input / 10;
		if (num[pin[i]] != digit) {
			correct = 0;
		}
	}
	if (correct == 0) {/*���T�P�w*/
		cout << "incorrect";
	}
	else if (correct == 1) {
		cout << "correct";
	}
	return 0;
}