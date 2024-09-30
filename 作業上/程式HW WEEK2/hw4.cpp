#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void) {
	char color;/*設立變數:顏色*/
	printf("type in the color>");
	scanf("%c", &color);/*輸入顏色*/
	switch (color)
	{
	case'O':
	case'o':/*若輸入為o為ammonia*/
		printf("ammonia");
		break;
	case'B':
	case'b':
		printf("carbon monoxide");/*若輸入為b為carbon monoxide*/
		break;
	case'Y':
	case'y':
		printf("hydrogen");/*若輸入為y為hydrogen*/
		break;
	case'G':
	case'g':
		printf("oxygen");/*若輸入為g為oxygen*/
		break;
	default:
		printf("Contents unknown");/*若皆非為未知物*/
		break;
	}
	return(0);
}