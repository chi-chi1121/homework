#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void) {
	double wt_lb, ht_in,bmi;/*�]���ܼ�:�魫�B�����Bbmi*/
	printf("type in your weight>");
	scanf("%lf", &wt_lb);/*��J�魫*/
	printf("type in your height>");
	scanf("%lf", &ht_in);/*��J����*/
	bmi = 703 * wt_lb / pow(ht_in, 2);/*�p��bmi*/
	if (bmi < 18.5) {/*��if�P�_���P�_bmi�����Ӱ϶�*/
		printf("Underweight");
	}
	else if (bmi >= 18.5 && bmi <= 24.9) {/*�Ybmi����18.5�M24.9���������`*/
		printf("Normal");
	}
	else if (bmi >= 25.0 && bmi <= 29.9) {/*�Ybmi����25�M29.9�������L��*/
		printf("Overweight");
	}
	else {/*��L���W��*/
		printf("Obese");
	}
	return(0);
}