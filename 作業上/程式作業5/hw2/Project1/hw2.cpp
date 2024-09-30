#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string>

int palindrome(char input[], int first, int last);      //�]�ߨ禡:�˴��O�_�^��
void Tolower(char string[]);                            // ��r������p�g

int main(void) {

	char input[100];           // �]���ܼ�:��J�r��B�O�_�^��
	int is_palindrome;                     

	printf("Enter a string << ");          //��J�r��
	scanf("%s", input);

	Tolower(input);                // �ର�p�g

	is_palindrome = palindrome(input, 0, strlen(input) - 1);     // �˴��O�_�^��

	if (is_palindrome) {                  // ��X
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
		string[i] = tolower(string[i]);   //�ন�p�g
		++i;
	}
}

int palindrome(char input[], int first, int last) {
	int is_palindrome=1;
	if (input[first] != input[last]) {   // �ݭ��쥽��O�_�ۦP
		is_palindrome = 0;
	}
	else if (last - first <= 1) {                //�Y��������̫�h�^��1
		is_palindrome = 1;
	}
	else if(input[first] == input[last]&& is_palindrome==1) {
		is_palindrome = palindrome(input, first + 1, last - 1);   // ���j
	}

	return is_palindrome;
}