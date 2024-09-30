#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string>

int palindrome(char input[], int first, int last);      //設立函式:檢測是否回文
void Tolower(char string[]);                            // 把字全部轉小寫

int main(void) {

	char input[100];           // 設立變數:輸入字串、是否回文
	int is_palindrome;                     

	printf("Enter a string << ");          //輸入字串
	scanf("%s", input);

	Tolower(input);                // 轉為小寫

	is_palindrome = palindrome(input, 0, strlen(input) - 1);     // 檢測是否回文

	if (is_palindrome) {                  // 輸出
		printf("Is palindrome\n");
	}
	else {
		printf("Is not palindrome\n");
	}

	return 0;
}

void Tolower(char string[]) {
	int i = 0;
	while (string[i]) {
		string[i] = tolower(string[i]);   //轉成小寫
		++i;
	}
}

int palindrome(char input[], int first, int last) {
	int is_palindrome=1;
	if (input[first] != input[last]) {   // 看首位末位是否相同
		is_palindrome = 0;
	}
	else if (last - first <= 1) {                //若持續執行到最後則回傳1
		is_palindrome = 1;
	}
	else if(input[first] == input[last]&& is_palindrome==1) {
		is_palindrome = palindrome(input, first + 1, last - 1);   // 遞迴
	}

	return is_palindrome;
}