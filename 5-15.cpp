#include <iostream>
using namespace std;
int main() {
	int num[10], pin[5] = { 1,2,3,4,5 }, input, correct = 1, digit;/*變數:隨機數列、PIN碼、輸入、是否正確、單位數字*/
	srand(time(0));/*設定亂數種子*/
	for (int i = 0; i < 10; i++) {/*設定隨機數列*/
		num[i] = rand() % 3 + 1;
	}
	cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "NUM: ";
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	cout << "enter the num>>";
	cin >> input;/*輸入數字*/
	for (int i = 4; i >= 0; i--) {/*逐位檢查是否符合*/
		digit = input % 10;
		input = input / 10;
		if (num[pin[i]] != digit) {
			correct = 0;
		}
	}
	if (correct == 0) {/*正確判定*/
		cout << "incorrect";
	}
	else if (correct == 1) {
		cout << "correct";
	}
	return 0;
}