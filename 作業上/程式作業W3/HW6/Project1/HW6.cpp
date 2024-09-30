#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
void reverse(int,int);/*�]�ߨ禡:�A��*/
void trans_to_int(char,int*);/*�]�ߨ禡:�r���ഫ���*/
int prime(int);/*�]�ߨ禡:�O�_���*/
int palindrome(int, int);/*�]�ߨ禡:�O�_�^��*/
int main() {
	int num=0 , n = 0;/*�]���ܼ�:�Ʀr�B�Ʀr���X��*/
	char numc;/*�]���ܼ�:�Ʀr(�r��)*/
	do
	{
	scanf("%c", &numc);/*��J�r��Ʀr*/
	trans_to_int(numc, &num);/*�ഫ����ƥΫ��бa�^*/
	n++;/*�C��J�@���W�[�@�����*/
	} while (numc != '\n');/*��JENTER�ɵ�����J*/
	n -= 1;/*�]���|�h��@��ENTER����ҥH-1*/
	reverse(num,n);/*�A�˥L�ÿ�X*/
	
	if (prime(num)) {/*�˴��O�_�����*/
		printf("%d is a prime number\n", num);
	}
	else {
		printf("%d is not a prime number\n", num);
	}
	if (palindrome(num, n)) {/*�˴��O�_���^���*/
		printf("%d is a palindrome number\n", num);
	}
	else {
		printf("%d is not a palindrome number\n", num);
	}
	return 0;
}


void reverse(int num, int n) {
	int rev = 0, rev_n = 0;/*�]���ܼ�:�A�˫᪺�Ʀr�B�A�˫�Ʀr�����*/
	do {
		rev += num % 10;/*���ǤJ���ƭȪ��Ӧ��*/
		rev *= 10;/*���ǤJ���ƭȪ��Ӧ��*/
		num = num / 10;/*�ǤJ�ƭȥh������*/
		rev_n++; /*�A�˫�Ʀr�����+1*/
	} while (num);/*����j�骽��ǤJ�Ʀr�k0*/
		if (rev_n == n) {/*�]���W���j�鰵���|�h���@��10�A�ҥH�Y��Ƭ۵��n��10�A�]����0�b�e�Y�ɷ|�h���@�������p*/
			rev /= 10;
		}
		printf("%d", rev);/*��X*/
		printf("\n");
	}


void trans_to_int(char numc, int* num) {
	if (numc != '\n') {
		*num = *num *10;/*�Ʀr�i�@�쵹�᭱�[�i�����Ʀr�Ŷ��A�o���e������h���@��10*/
		*num += numc - '0';	/*��J���r���ഫ���Ʀr�å[�W�h*/
	}
}

int prime(int num) {
	int count = 0;
	for (int i = 1; i <= num; i++) {/*�ΰj����լO�_�����*/
		if (num % i == 0) {/*�Y�i�H�㰣�h�p��+1*/
			count++;
		}
	}
	if (count == 2) {/*�p�Ƭ�2�N��L�O���*/
		return 1;
	}
	else {
		return 0;
	}
}

int palindrome(int num, int n) {
	for (int i = 0; i < n / 2; i++) {
		if (num / int(pow(10, n - (1 + i * 2))) != num % 10) {/*���խ���M����O�_���P�@�ӼƦr�A�_�hreturn 0*/
			return 0;
		}
		num = num % int(pow(10, n - (1 + i * 2)));/*�h������*/
		num = num / 10;/*�h������*/
	}
	return 1;
}