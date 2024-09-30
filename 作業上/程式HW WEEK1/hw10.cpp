#define _CRT_SECURE_NO_WARNINGS
//此程式用於給定兩點後計算該直線的垂直平分線方程式
#include<stdio.h>
int main(void) {
    double x1, y1, x2, y2, x_mid, y_mid, s_perpendicular, con;/*宣告變數:兩點的xy值、兩點中點的xy值、垂直平分線斜率和方程式的常數項*/
//輸入兩點座標
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    scanf("%lf", &x2);
    scanf("%lf", &y2);
    s_perpendicular = -1 / ((y2 - y1) / (x2 - x1));/*計算垂直平分線的斜率*/
   /* 計算中點座標*/
    x_mid = (x1 + x2) / 2;
    y_mid = (y1 + y2) / 2;
    con = y_mid - x_mid * s_perpendicular;/*計算常數項*/
    printf("y= %.1lfx + %.2lf", s_perpendicular, con);/*輸出方程式*/
    return (0);
}
