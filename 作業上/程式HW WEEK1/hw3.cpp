#define _CRT_SECURE_NO_WARNINGS
/*���{���Ω�p��ūצb�B�c���g�L�@�q�ɶ���|�ܦh��*/ 
#include<stdio.h>
int main(void) {
	double time_h, time_m, temp;/*�ŧi�ܼ�:�p�ɡB�����M�ū�*/
	
	printf("type in the elapsetime >");
	scanf("%lf", &time_h);/*��J�p��*/
	scanf("%lf", &time_m);/*��J����*/
	time_h = time_h + time_m / 60;/*�N�������⦨�p��*/
	temp = 4 * time_h * time_h / (time_h + 2) - 20;/*���Ӥ����ήɶ��h�p��ū�*/
	printf("the temperture after %.0lf hour %.0lf minutes is %.2lf",time_h-time_m/60,time_m, temp);/*��X�ū�*/
	return (0);

}
