#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_check_digit(const int digits[12], int* check_digit);/*設立函式:取得checkdigit*/
int main() {
	int digits[12], check_digit = 0, final_digit = 0;/*設立變數*/
	printf("Enter 12 digit positive integer number separated by spaces << \n");
	for (int i = 0; i < 12; i++) {
		scanf("%d", &digits[i]);/*輸入digit*/
	}
	final_digit = digits[11];/*令final_digit=最後一位*/
	get_check_digit(digits, &check_digit);/*取得check_digit*/
	if (check_digit == final_digit) {/*如果check_digit=最後一位輸出validated*/
		printf("validated");
	}
	else {
		printf("error in barcode");/*否則輸出error in barcode*/
	}
	return 0;
}

void get_check_digit(const int digits[12], int* check_digit) {
	int odd_sum = 0, even_sum = 0, sum = 0;/*設立變數:機數位、偶數位*/
	for (int i = 0; i < 11; i++) {
		if ((i + 1) % 2 == 1) {
			odd_sum += digits[i];
		}
		else if ((i + 1) % 2 == 0) {
			even_sum += digits[i];
		}
	}
	sum = odd_sum * 3 + even_sum;/*照規則計算check_digit*/
	if (sum % 10 != 0) {
		*check_digit = 10 - (sum % 10);
	}
	else if (sum % 10 == 0) {
		*check_digit = 0;
	}
}