#define _CRT_SECURE_NO_WARNINGS
 //���{���Ω�p���ī~����J�t�v
#include<stdio.h>
#define HOUR 60 /*�w�q�@�p��60���� */
int main(void) {
	int vol, min, rate;/* �ŧi�ܼ�:��J�ī~�e�q�B�g�L�ɶ��B�t�v*/
	printf("Volume to be infused (ml)=> ");
	scanf("%d", &vol);/*��J�ī~��J�F�h��*/
	printf("Minutes over which to infuse => ");
	scanf("%d", &min);/*��J�L�F�h�֤���*/
	rate = vol * (HOUR / min);/*�p��t�v*/
	printf("VTBI: %d ml\nRate: %d ml/hr", vol, rate);

	return (0);

}
