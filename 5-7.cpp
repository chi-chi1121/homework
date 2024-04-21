#include <iostream>
using namespace std;
int main() {
	int student, scale[6] = { 0 }, grade;/*變數:學生數量、分數陣列、輸入成績*/
	cout << "enter the number of student>> ";
	cin >> student;
	cout << "enter the grade >> ";
	for (int i = 0; i < student; i++) {/*輸入成績在該陣列位置+1*/
		cin >> grade;
		scale[grade]++;
	}
	for (int i = 0; i < 6; i++){
		cout << scale[i] << " grade(s) of " << i << endl;/*輸出*/
	}
	return 0;
}