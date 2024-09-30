#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void charge_f(double,double*,double*);/*�p�⦬�O*/
double round_money(double);/*����p���I��G��*/

int main() {
	FILE* useage = fopen("usage.txt", "r"), * charge = fopen("charges.txt", "w");/*���}�ɮ�*/
	int month, year, ID;/*�]���ܼ�:����B�~�BID*/
	double hour, charge_per_hour, avg_cost;/*�]���ܼ�:�ɼơB�C�p�ɦ��O�B������O*/
	fscanf(useage, "%d %d", &month, &year);/*Ū���ɮ�*/
	fprintf(charge, "Charges for %d/%d\n", month, year);/*��~���������X*/
	fprintf(charge, "\nCustomer \t Hours used\t Charge per hour \t Average cost\n");
	while (fscanf(useage, "%d", &ID) != EOF) {
		fscanf(useage, "%lf", &hour);/*Ū���ɮפ����p�ɼ�*/
		charge_f(hour, &charge_per_hour, &avg_cost);/*�p�⦬�O*/
		fprintf(charge, "%d %9c %.1f %13c %.2f %9c %.2f\n", ID,' ', hour,' ', charge_per_hour,' ', avg_cost);/*��X*/
	}
	fclose(useage);/*�����ɮ�*/
	fclose(charge);
	return 0;
}
void charge_f(double hour, double* charge_per_hour, double* avg_cost) {
	int hour_int=0;
	if (int(hour * 10) % 10 != 0) {/*�L����i��p�ɼ�*/
		hour_int = (int)hour + 1;
	}
	else
	{
		hour_int = (int)hour;
	}
	if (hour > 10) {/*�p�⦬�O*/
		*charge_per_hour = 7.99 + (hour_int-10) * 1.99;
	}
	else {
		*charge_per_hour = 7.99;
	}
	*avg_cost = *charge_per_hour / hour;/*�p�⥭�����O*/
	*avg_cost = round_money(*avg_cost);/*����p���I�ĤG��*/
	*charge_per_hour = round_money(*charge_per_hour);/*����p���I�ĤG��*/
}
double round_money(double num) {
	num = int(num * 100 + 0.5)*0.01 ;/*����p���I�ĤG��*/
	return num;
}