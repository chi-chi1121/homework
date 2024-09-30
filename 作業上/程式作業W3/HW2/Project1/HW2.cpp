#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	char digit;/*設立變數:各位的數字(字串形式)*/
	int  n,  sum = 0, i, j;/*設立變數:輸入數字、、加總、控制迴圈變數*/
	for (i = 0; i < 3; i++) {/*輸入三次的迴圈*/
		scanf("%d", &n);/*輸入要除的數字*/
		printf("n = %d\n", n);
		for (j = 0; j < 6; j++) {/*把每位數字相加的迴圈*/
			digit = n % 10;/*要加的數字為輸入數字除10的餘數*/
			n = n / 10;/*把輸入數字的最後一位除掉*/
			sum = sum + ((int)digit-(int)0);/*把要加的數字加入總和*/
		}
		if (sum % 9 == 0) {/*條件式判斷是否可被整除*/
			printf("n is divisible by 9\n");
		}
		else
		{
			printf("n is not divisible by 9\n");
		}
	}
	return(0);
}