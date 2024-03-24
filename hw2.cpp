#include <iostream>
using namespace std;
double convertToMPH(int min ,int sec);/*重載函式:分鐘轉MPH、KPH轉MPH*/
double convertToMPH(double kph);

int main() {
	int min, sec;/*變數:分種、秒數、KPH、MPH*/
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
	double total_min = min + sec / 60.0;/*算總分鐘數*/
	return(60 / total_min);/*回傳轉換成小時的*/
}

double convertToMPH(double kph) {
	return(kph * 1.61);/*轉換成MPH*/
}