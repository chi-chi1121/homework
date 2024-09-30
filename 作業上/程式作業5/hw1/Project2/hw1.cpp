#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int blob_check(int pic[][5], int x, int y);

int main() {
	int x, y, cell;
	int pic[5][5]{
		{0, 1, 0, 1, 1},
		{1, 0, 0, 0, 1},
		{0, 0, 1, 0, 1},
		{0, 1, 1, 0, 0},
		{1, 1, 0, 0, 0}
	};/*設立變數:x,y,總數,圖*/
	printf("Enter x and y coordinate between 0 to 4 << ");        
	scanf("%d%d", &y, &x);

	cell = blob_check(pic, x, y);         
	printf("The number of cells in the blob: %d", cell);/*輸出答案*/
	return 0;
}
int blob_check(int pic[][5], int x, int y) {/*計算相鄰方塊*/
	int ans = 0;
	if (pic[x][y] == 1 && x >= 0 && x < 5 && y>=0 && y < 5) {
		ans += 1;/*回傳數字+1*/
		pic[x][y] = 0;/*令該格為空否則出bug*/
		for (int y_near = 1; y_near >=-1; y_near--) {/*檢測周圍四格方塊*/
			for (int x_near = -1; x_near <= 1; x_near++) {
				ans += blob_check(pic, x + x_near,y + y_near);/*遞迴*/
			}
		}
	}
	return ans;
}