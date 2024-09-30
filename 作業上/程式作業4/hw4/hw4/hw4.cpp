#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int binary_srch(int arr[10], int input);/*設立函式:二分搜尋*/
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }, input;/*設立變數:自訂陣列、輸入*/
	int index = 100;/*設立變數:引數*/
	printf("please type in te number you want to search>>");
	do {
		scanf("%d", &input);
		if (input > arr[9] || input < arr[0]) {
			printf("out fo range\n");
		}
	} while (input > arr[9] || input < arr[0]);/*檢測輸入是否超出範圍*/
	index = binary_srch(arr, input);/*令引數為二分搜尋出的結果*/
	if (index == 100) {
		printf("%d is not in the array", input);
	}
	else {
		printf("%d is the index %d of the array", input, index);
	}
	return 0;
}

int binary_srch(int arr[10], int input) {
	int top = 9, bot = 0, mid, ans, index = 100;/*設立變數:頂、底、中間、所求、引數*/
	do
	{

		mid = (top + bot) / 2;/*令中間項=頂項+底項*/
		ans = arr[mid];/*先假設所求為陣列中間項*/
		if (input == ans) {/*若中間項=輸入則引數=中間項*/
			index = mid;
		}
		else if (input > ans) {/*若輸入>當前數字則令底項為中間項+1*/
			bot = mid + 1;
		}
		else if (input < ans) {/*若輸入<當前數字則令頂項為中間項-1*/
			top = mid - 1;
		}
	} while (ans != input);/*當所求不=輸入時重複執行*/

	return index;
}