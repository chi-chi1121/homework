#include <iostream>
using namespace std;
int main() {
	int student, scale[6] = { 0 }, grade;/*�ܼ�:�ǥͼƶq�B���ư}�C�B��J���Z*/
	cout << "enter the number of student>> ";
	cin >> student;
	cout << "enter the grade >> ";
	for (int i = 0; i < student; i++) {/*��J���Z�b�Ӱ}�C��m+1*/
		cin >> grade;
		scale[grade]++;
	}
	for (int i = 0; i < 6; i++){
		cout << scale[i] << " grade(s) of " << i << endl;/*��X*/
	}
	return 0;
}