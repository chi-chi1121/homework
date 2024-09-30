#define _CRT_SECURE_NO_WARNINGS
/*此程式用於計算溫度在冰箱中經過一段時間後會變多少*/ 
#include<stdio.h>
int main(void) {
	double time_h, time_m, temp;/*宣告變數:小時、分鐘和溫度*/
	
	printf("type in the elapsetime >");
	scanf("%lf", &time_h);/*輸入小時*/
	scanf("%lf", &time_m);/*輸入分鐘*/
	time_h = time_h + time_m / 60;/*將分鐘換算成小時*/
	temp = 4 * time_h * time_h / (time_h + 2) - 20;/*按照公式用時間去計算溫度*/
	printf("the temperture after %.0lf hour %.0lf minutes is %.2lf",time_h-time_m/60,time_m, temp);/*輸出溫度*/
	return (0);

}
