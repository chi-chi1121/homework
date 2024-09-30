#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	double day,rate,cases; /*砞ミ跑计:筁碭ぱ–ぱネ痜计Θぶ%絋禘计*/
	int i=0;/*砞ミ跑计北while*/
	printf("FLU EPIDEMIC PREDICIONS BASESD ON ELAPSED DAYS SINCE FIRST CASE REPORT\n");
	while (i<3)/*狡块Ω*/
	{
		printf("Enter day number>>");
		scanf("%lf", &day);/*块筁碭ぱ*/
		rate = 40000 / (1 + 39999 * (exp(-0.24681)));/*璸衡Θ%计*/
		cases =  pow(rate, day);/*璸衡絋禘计*/
		printf("By day %.0f , model predicts %.2f cases total.\n", day, cases);/*块ぱ计の絋禘计*/
		i++;
	}
		return(0);
}