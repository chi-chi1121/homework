#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
bool within_x_percent(double ref, double data);/*;設立一個函式回傳輸入的數字是否在題目要求之區間*/
int main(void) {
	double ref, data;/*設立變數輸入溫度和標準沸點*/
	int i = 1; /*設立變數來控制swich*/
	scanf("%lf", &ref);/*輸入溫度*/
	switch (i)/*用swich來切換不同沸點的case*/
	{	case 1:
			data = 100;/*令標準沸點=該物體的沸點*/
			if (within_x_percent(ref,data) ){/*利用條件式判斷是否符合敘述*/
				printf("Water");
				break;
			}
			i++;
		case 2:
			data = 357;/*令標準沸點=該物體的沸點*/
			if (within_x_percent(ref, data)) {/*利用條件式判斷是否符合敘述*/
				printf("Mercury");/*輸出物體*/
				break;	
			}
			i++;
		case 3:
			data = 1187;/*令標準沸點=該物體的沸點*/
			if (within_x_percent(ref, data)) {/*利用條件式判斷是否符合敘述*/
				printf("Copper");/*輸出物體*/
				break;
			}
			i++;
		case 4:
			data = 2193;/*令標準沸點=該物體的沸點*/
			if (within_x_percent(ref, data)) {/*利用條件式判斷是否符合敘述*/
				printf("Silver");/*輸出物體*/
				break;
			}
			i++;
		case 5:
			data = 2660;/*令標準沸點=該物體的沸點*/
			if (within_x_percent(ref, data)) {/*利用條件式判斷是否符合敘述*/
				printf("Gold");/*輸出物體*/
				break;
			}
		default:
			printf("Substance unknown");/*輸出物體*/
			break;
	}
	return(0);
}
bool  within_x_percent(double ref, double data) {
	if (ref - ref * 5 / 100 <= data && ref + ref * 5 / 100 >= data) {/*計算輸入溫度是否在沸點的正負5%內*/
		return true;
	}
	else
	{
		return false;
	}
	
}