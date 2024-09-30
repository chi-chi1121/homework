#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	char bat;/*設立變數:是否打擊*/
	int i, j = 0, num, n = 17;/*設立變數:控制迴圈變數、球員編號、內迴圈上限*/
	double rate, hit, all;/*設立變數:打擊率、打擊次數、打擊跟揮棒落空次數*/

	for (i = 0; i < 3; i++) {/*共輸入三次，所以進行三次迴圈*/
		hit = 0;/*初始化打擊次數、打擊跟揮棒落空次數*/
		all = 0;
		scanf("%d", &num);/*輸入球員編號*/
		printf("Player %d's record:", num);
		if (i > 0) {/*第二次迴圈開始輸入得數據為15筆，但因需加空格所以為16*/
			n = 16;
		}
		for (j = 0; j < n; j++) {
			scanf("%c", &bat);/*輸入打擊紀錄*/
			printf("%c", bat);

			if (bat == 'H') {/*若為H則打擊次數、打擊跟揮棒落空次數+1*/
				hit += 1;
				all += 1;
			}

			else if (bat == 'O') {/*若為O則打擊跟揮棒落空次數+1*/
				all += 1;
			}
		}
		rate = hit / all;/*計算打擊綠率*/
		printf("\nPlayer %d's batting average: %.3f\n", num, rate);/*輸出*/
	}
	return(0);
}