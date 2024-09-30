#define _CRT_SECURE_NO_WARNINGS
 //此程式用於計算藥品的輸入速率
#include<stdio.h>
#define HOUR 60 /*定義一小時60分鐘 */
int main(void) {
	int vol, min, rate;/* 宣告變數:輸入藥品容量、經過時間、速率*/
	printf("Volume to be infused (ml)=> ");
	scanf("%d", &vol);/*輸入藥品輸入了多少*/
	printf("Minutes over which to infuse => ");
	scanf("%d", &min);/*輸入過了多少分鐘*/
	rate = vol * (HOUR / min);/*計算速率*/
	printf("VTBI: %d ml\nRate: %d ml/hr", vol, rate);

	return (0);

}
