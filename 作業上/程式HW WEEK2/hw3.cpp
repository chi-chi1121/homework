#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void) {
	double wt_lb, ht_in,bmi;/*設立變數:體重、身高、bmi*/
	printf("type in your weight>");
	scanf("%lf", &wt_lb);/*輸入體重*/
	printf("type in your height>");
	scanf("%lf", &ht_in);/*輸入身高*/
	bmi = 703 * wt_lb / pow(ht_in, 2);/*計算bmi*/
	if (bmi < 18.5) {/*用if判斷式判斷bmi位於哪個區間*/
		printf("Underweight");
	}
	else if (bmi >= 18.5 && bmi <= 24.9) {/*若bmi介於18.5和24.9中間為正常*/
		printf("Normal");
	}
	else if (bmi >= 25.0 && bmi <= 29.9) {/*若bmi介於25和29.9中間為過重*/
		printf("Overweight");
	}
	else {/*其他為超重*/
		printf("Obese");
	}
	return(0);
}