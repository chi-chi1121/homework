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
	};/*�]���ܼ�:x,y,�`��,��*/
	printf("Enter x and y coordinate between 0 to 4 << ");        
	scanf("%d%d", &y, &x);

	cell = blob_check(pic, x, y);         
	printf("The number of cells in the blob: %d", cell);/*��X����*/
	return 0;
}
int blob_check(int pic[][5], int x, int y) {/*�p��۾F���*/
	int ans = 0;
	if (pic[x][y] == 1 && x >= 0 && x < 5 && y>=0 && y < 5) {
		ans += 1;/*�^�ǼƦr+1*/
		pic[x][y] = 0;/*�O�Ӯ欰�ŧ_�h�Xbug*/
		for (int y_near = 1; y_near >=-1; y_near--) {/*�˴��P��|����*/
			for (int x_near = -1; x_near <= 1; x_near++) {
				ans += blob_check(pic, x + x_near,y + y_near);/*���j*/
			}
		}
	}
	return ans;
}