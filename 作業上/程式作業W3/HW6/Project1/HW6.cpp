#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
void reverse(int,int);/*砞ミㄧΑ:腁*/
void trans_to_int(char,int*);/*砞ミㄧΑ:﹃锣传俱计*/
int prime(int);/*砞ミㄧΑ:琌借计*/
int palindrome(int, int);/*砞ミㄧΑ:琌ゅ*/
int main() {
	int num=0 , n = 0;/*砞ミ跑计:计计Τ碭*/
	char numc;/*砞ミ跑计:计(﹃)*/
	do
	{
	scanf("%c", &numc);/*块﹃计*/
	trans_to_int(numc, &num);/*锣传俱计ノ夹盿*/
	n++;/*–块Ω糤Ω计*/
	} while (numc != '\n');/*块ENTER挡块*/
	n -= 1;/*穦衡ΩENTER┮-1*/
	reverse(num,n);/*腁块*/
	
	if (prime(num)) {/*浪代琌借计*/
		printf("%d is a prime number\n", num);
	}
	else {
		printf("%d is not a prime number\n", num);
	}
	if (palindrome(num, n)) {/*浪代琌ゅ计*/
		printf("%d is a palindrome number\n", num);
	}
	else {
		printf("%d is not a palindrome number\n", num);
	}
	return 0;
}


void reverse(int num, int n) {
	int rev = 0, rev_n = 0;/*砞ミ跑计:腁计腁计计*/
	do {
		rev += num % 10;/*肚计计*/
		rev *= 10;/*肚计计*/
		num = num / 10;/*肚计奔Ю计*/
		rev_n++; /*腁计计+1*/
	} while (num);/*尿癹伴肚计耴0*/
		if (rev_n == n) {/*癹伴暗Ч穦Ω10┮璝计单璶埃10ňゎ0玡繷穦埃Ω猵*/
			rev /= 10;
		}
		printf("%d", rev);/*块*/
		printf("\n");
	}


void trans_to_int(char numc, int* num) {
	if (numc != '\n') {
		*num = *num *10;/*计秈倒秈计丁硂︽玡ňゎΩ10*/
		*num += numc - '0';	/*块﹃锣传计*/
	}
}

int prime(int num) {
	int count = 0;
	for (int i = 1; i <= num; i++) {/*ノ癹伴代刚琌借计*/
		if (num % i == 0) {/*璝俱埃玥璸计+1*/
			count++;
		}
	}
	if (count == 2) {/*璸计2琌借计*/
		return 1;
	}
	else {
		return 0;
	}
}

int palindrome(int num, int n) {
	for (int i = 0; i < n / 2; i++) {
		if (num / int(pow(10, n - (1 + i * 2))) != num % 10) {/*代刚㎝ソ琌计玥return 0*/
			return 0;
		}
		num = num % int(pow(10, n - (1 + i * 2)));/*奔*/
		num = num / 10;/*奔ソ*/
	}
	return 1;
}