#include <iostream>
using namespace std;
double convertToMPH(int min ,int sec);/*�����禡:������MPH�BKPH��MPH*/
double convertToMPH(double kph);

int main() {
	int min, sec;/*�ܼ�:���ءB��ơBKPH�BMPH*/
	double kph, mph;
	cout << "enter minutes: ";
	cin >> min;
	cout << "enter seconds: ";
	cin >> sec;
	cout << "the mph is : ";
	cout << convertToMPH(min, sec) << endl;
	cout << "enter the kph: ";
	cin >> kph;
	cout << "the mph is : ";
	cout << convertToMPH(kph);
	return 0;
}

double convertToMPH(int min, int sec) {
	double total_min = min + sec / 60.0;/*���`������*/
	return(60 / total_min);/*�^���ഫ���p�ɪ�*/
}

double convertToMPH(double kph) {
	return(kph * 1.61);/*�ഫ��MPH*/
}