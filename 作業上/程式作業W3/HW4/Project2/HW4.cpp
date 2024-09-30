#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	int i = 0;/*設立變數:控制迴圈變數*/
	double x, c, p, y,m;/*設立變數:X、常數、指數、Y*/
	printf("type in c and power>>");
	scanf("%lf%lf", &c, &p);/*輸入常數跟指數*/
	printf("\nthe formula is x^%.0f=%.0f\n", p, c);/*輸出算式*/
	x = c / 2;/*依題目給得先從c/2開始找*/
	do /*找Y>0且最接近0的數字*/
	{
		x = x - (pow(x, p) - c) / (p * pow(x, p - 1));/*照課本公式找下個X*/
		y = pow(x, p) - c;/*計算Y值*/

		i++;
	} while (y>0||i<100);/*Y>0或迴圈做100次*/
	printf("x=%lf\n", x);/*輸出Y為根時的X*/
	return(0);
}