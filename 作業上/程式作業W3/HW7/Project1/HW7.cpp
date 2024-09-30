#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void charge_f(double,double*,double*);/*計算收費*/
double round_money(double);/*取到小數點後二位*/

int main() {
	FILE* useage = fopen("usage.txt", "r"), * charge = fopen("charges.txt", "w");/*打開檔案*/
	int month, year, ID;/*設立變數:月份、年、ID*/
	double hour, charge_per_hour, avg_cost;/*設立變數:時數、每小時收費、平均花費*/
	fscanf(useage, "%d %d", &month, &year);/*讀取檔案*/
	fprintf(charge, "Charges for %d/%d\n", month, year);/*把年份月分都輸出*/
	fprintf(charge, "\nCustomer \t Hours used\t Charge per hour \t Average cost\n");
	while (fscanf(useage, "%d", &ID) != EOF) {
		fscanf(useage, "%lf", &hour);/*讀取檔案中的小時數*/
		charge_f(hour, &charge_per_hour, &avg_cost);/*計算收費*/
		fprintf(charge, "%d %9c %.1f %13c %.2f %9c %.2f\n", ID,' ', hour,' ', charge_per_hour,' ', avg_cost);/*輸出*/
	}
	fclose(useage);/*關閉檔案*/
	fclose(charge);
	return 0;
}
void charge_f(double hour, double* charge_per_hour, double* avg_cost) {
	int hour_int=0;
	if (int(hour * 10) % 10 != 0) {/*無條件進位小時數*/
		hour_int = (int)hour + 1;
	}
	else
	{
		hour_int = (int)hour;
	}
	if (hour > 10) {/*計算收費*/
		*charge_per_hour = 7.99 + (hour_int-10) * 1.99;
	}
	else {
		*charge_per_hour = 7.99;
	}
	*avg_cost = *charge_per_hour / hour;/*計算平均收費*/
	*avg_cost = round_money(*avg_cost);/*取到小數點第二位*/
	*charge_per_hour = round_money(*charge_per_hour);/*取到小數點第二位*/
}
double round_money(double num) {
	num = int(num * 100 + 0.5)*0.01 ;/*取到小數點第二位*/
	return num;
}