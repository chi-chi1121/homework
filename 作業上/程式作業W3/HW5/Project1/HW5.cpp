#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
double func1(double);/*設立函式:G(X)*/
double func2(double);/*設立函式:H(X)*/
void trap(double, double, int, double fun(double));/*設立計算積分的函式*/
int main(void) {
	int n;/*設立變數:切成N等分*/
	double  a, b;/*設立變數:起點、終點*/
	printf("x^2sin(x):\n");
	a = 0;
	b = 3.14159;
	for (n = 2; n <= 128; n *= 2) {
		trap(a, b, n, func1);/*計算G(X)在各等分下的積分值*/
	}
	a = -2;
	b = 2;
	printf("\nsqrt(4 - x^2):\n");
	for (n = 2; n <=128; n *= 2) {
		trap(a, b, n, func2);/*計算H(X)在各等分下的積分值*/
	}
	return(0);
}
void trap(double a, double b, int n,double fun(double)) {
	double t , h = ( b - a ) / n;
	double sum=0,x_now=a;
	for (int i = 0; i < n; i++) {
		sum += fun(x_now);/*計算N等分下的所有Y值加總*/
		x_now += h;
	}
	t = (h / 2) * (fun(a) + fun(b) + 2 * sum);/*按照課本公式計算*/
	printf("when n=%d ,the area under the curve is %lf\n",n, t);
}
double func1(double x) {
	return x * x * sin(x);/*計算x^2sin*(x)*/
}

double func2(double x) {
	return sqrt(4 - x * x);/*計算根號4-x^2*/
}