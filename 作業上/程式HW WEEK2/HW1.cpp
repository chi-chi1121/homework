#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	double i, p, price, total_payment,mon_pay;/*�]���ܼƧQ�v�B���������B�������B�B�n��h�[����٧��B�C��n��h��*/
	printf("how much is the car>");
	scanf("%lf",&price);/*��J�������B*/
	printf("how much is interest rate>");
	scanf("%lf",&i);/*��J�Q�v*/
	printf("how iong will you pay back the loan>");
	scanf("%lf",&total_payment);/*��J�n��h�[����٧�*/
	p = price - 500;/*�p�⤣������*/
	mon_pay = i * p / (1 - pow((1 + i),-total_payment));/*�p��C��n�I�h��*/
	printf("your monthly payment is $%.2f",mon_pay);
	return(0);
}