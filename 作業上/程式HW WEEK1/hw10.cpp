#define _CRT_SECURE_NO_WARNINGS
//���{���Ω󵹩w���I��p��Ӫ��u�����������u��{��
#include<stdio.h>
int main(void) {
    double x1, y1, x2, y2, x_mid, y_mid, s_perpendicular, con;/*�ŧi�ܼ�:���I��xy�ȡB���I���I��xy�ȡB���������u�ײv�M��{�����`�ƶ�*/
//��J���I�y��
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    scanf("%lf", &x2);
    scanf("%lf", &y2);
    s_perpendicular = -1 / ((y2 - y1) / (x2 - x1));/*�p�⫫�������u���ײv*/
   /* �p�⤤�I�y��*/
    x_mid = (x1 + x2) / 2;
    y_mid = (y1 + y2) / 2;
    con = y_mid - x_mid * s_perpendicular;/*�p��`�ƶ�*/
    printf("y= %.1lfx + %.2lf", s_perpendicular, con);/*��X��{��*/
    return (0);
}
