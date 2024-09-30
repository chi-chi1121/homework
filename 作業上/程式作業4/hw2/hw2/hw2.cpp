#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_check_digit(const int digits[12], int* check_digit);/*�]�ߨ禡:���ocheckdigit*/
int main() {
	int digits[12], check_digit = 0, final_digit = 0;/*�]���ܼ�*/
	printf("Enter 12 digit positive integer number separated by spaces << \n");
	for (int i = 0; i < 12; i++) {
		scanf("%d", &digits[i]);/*��Jdigit*/
	}
	final_digit = digits[11];/*�Ofinal_digit=�̫�@��*/
	get_check_digit(digits, &check_digit);/*���ocheck_digit*/
	if (check_digit == final_digit) {/*�p�Gcheck_digit=�̫�@���Xvalidated*/
		printf("validated");
	}
	else {
		printf("error in barcode");/*�_�h��Xerror in barcode*/
	}
	return 0;
}

void get_check_digit(const int digits[12], int* check_digit) {
	int odd_sum = 0, even_sum = 0, sum = 0;/*�]���ܼ�:���Ʀ�B���Ʀ�*/
	for (int i = 0; i < 11; i++) {
		if ((i + 1) % 2 == 1) {
			odd_sum += digits[i];
		}
		else if ((i + 1) % 2 == 0) {
			even_sum += digits[i];
		}
	}
	sum = odd_sum * 3 + even_sum;/*�ӳW�h�p��check_digit*/
	if (sum % 10 != 0) {
		*check_digit = 10 - (sum % 10);
	}
	else if (sum % 10 == 0) {
		*check_digit = 0;
	}
}