#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	double day,rate,cases; /*�]���ܼ�:�L�X�ѡB�C�ѥͯf�H�Ʀ����h��%�B�T�E�H��*/
	int i=0;/*�]���ܼƱ���while*/
	printf("FLU EPIDEMIC PREDICIONS BASESD ON ELAPSED DAYS SINCE FIRST CASE REPORT\n");
	while (i<3)/*���ƿ�J�T��*/
	{
		printf("Enter day number>>");
		scanf("%lf", &day);/*��J�L�X��*/
		rate = 40000 / (1 + 39999 * (exp(-0.24681)));/*�p�⦨��%��*/
		cases =  pow(rate, day);/*�p��T�E�H��*/
		printf("By day %.0f , model predicts %.2f cases total.\n", day, cases);/*��X�ѼƤνT�E�H��*/
		i++;
	}
		return(0);
}