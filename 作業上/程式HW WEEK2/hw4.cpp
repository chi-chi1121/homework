#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void) {
	char color;/*�]���ܼ�:�C��*/
	printf("type in the color>");
	scanf("%c", &color);/*��J�C��*/
	switch (color)
	{
	case'O':
	case'o':/*�Y��J��o��ammonia*/
		printf("ammonia");
		break;
	case'B':
	case'b':
		printf("carbon monoxide");/*�Y��J��b��carbon monoxide*/
		break;
	case'Y':
	case'y':
		printf("hydrogen");/*�Y��J��y��hydrogen*/
		break;
	case'G':
	case'g':
		printf("oxygen");/*�Y��J��g��oxygen*/
		break;
	default:
		printf("Contents unknown");/*�Y�ҫD��������*/
		break;
	}
	return(0);
}