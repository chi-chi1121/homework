#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int binary_srch(int arr[10], int input);/*�]�ߨ禡:�G���j�M*/
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }, input;/*�]���ܼ�:�ۭq�}�C�B��J*/
	int index = 100;/*�]���ܼ�:�޼�*/
	printf("please type in te number you want to search>>");
	do {
		scanf("%d", &input);
		if (input > arr[9] || input < arr[0]) {
			printf("out fo range\n");
		}
	} while (input > arr[9] || input < arr[0]);/*�˴���J�O�_�W�X�d��*/
	index = binary_srch(arr, input);/*�O�޼Ƭ��G���j�M�X�����G*/
	if (index == 100) {
		printf("%d is not in the array", input);
	}
	else {
		printf("%d is the index %d of the array", input, index);
	}
	return 0;
}

int binary_srch(int arr[10], int input) {
	int top = 9, bot = 0, mid, ans, index = 100;/*�]���ܼ�:���B���B�����B�ҨD�B�޼�*/
	do
	{

		mid = (top + bot) / 2;/*�O������=����+����*/
		ans = arr[mid];/*�����]�ҨD���}�C������*/
		if (input == ans) {/*�Y������=��J�h�޼�=������*/
			index = mid;
		}
		else if (input > ans) {/*�Y��J>��e�Ʀr�h�O������������+1*/
			bot = mid + 1;
		}
		else if (input < ans) {/*�Y��J<��e�Ʀr�h�O������������-1*/
			top = mid - 1;
		}
	} while (ans != input);/*��ҨD��=��J�ɭ��ư���*/

	return index;
}