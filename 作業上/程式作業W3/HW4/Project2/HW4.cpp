#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	int i = 0;/*�]���ܼ�:����j���ܼ�*/
	double x, c, p, y,m;/*�]���ܼ�:X�B�`�ơB���ơBY*/
	printf("type in c and power>>");
	scanf("%lf%lf", &c, &p);/*��J�`�Ƹ����*/
	printf("\nthe formula is x^%.0f=%.0f\n", p, c);/*��X�⦡*/
	x = c / 2;/*���D�ص��o���qc/2�}�l��*/
	do /*��Y>0�B�̱���0���Ʀr*/
	{
		x = x - (pow(x, p) - c) / (p * pow(x, p - 1));/*�ӽҥ�������U��X*/
		y = pow(x, p) - c;/*�p��Y��*/

		i++;
	} while (y>0||i<100);/*Y>0�ΰj�鰵100��*/
	printf("x=%lf\n", x);/*��XY���ڮɪ�X*/
	return(0);
}