#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	char digit;/*�]���ܼ�:�U�쪺�Ʀr(�r��Φ�)*/
	int  n,  sum = 0, i, j;/*�]���ܼ�:��J�Ʀr�B�B�[�`�B����j���ܼ�*/
	for (i = 0; i < 3; i++) {/*��J�T�����j��*/
		scanf("%d", &n);/*��J�n�����Ʀr*/
		printf("n = %d\n", n);
		for (j = 0; j < 6; j++) {/*��C��Ʀr�ۥ[���j��*/
			digit = n % 10;/*�n�[���Ʀr����J�Ʀr��10���l��*/
			n = n / 10;/*���J�Ʀr���̫�@�찣��*/
			sum = sum + ((int)digit-(int)0);/*��n�[���Ʀr�[�J�`�M*/
		}
		if (sum % 9 == 0) {/*���󦡧P�_�O�_�i�Q�㰣*/
			printf("n is divisible by 9\n");
		}
		else
		{
			printf("n is not divisible by 9\n");
		}
	}
	return(0);
}