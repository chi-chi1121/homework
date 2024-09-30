#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	double i, p, price, total_payment,mon_pay;/*設立變數利率、不足的錢、車的金額、要花多久把錢還完、每月要花多少*/
	printf("how much is the car>");
	scanf("%lf",&price);/*輸入車的金額*/
	printf("how much is interest rate>");
	scanf("%lf",&i);/*輸入利率*/
	printf("how iong will you pay back the loan>");
	scanf("%lf",&total_payment);/*輸入要花多久把錢還完*/
	p = price - 500;/*計算不足的錢*/
	mon_pay = i * p / (1 - pow((1 + i),-total_payment));/*計算每月要付多少*/
	printf("your monthly payment is $%.2f",mon_pay);
	return(0);
}