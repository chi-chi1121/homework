	#define _CRT_SECURE_NO_WARNINGS
/*���{���έp��p�{�����O�� */
#include<stdio.h>
#define FARE_PER_MILE 1.5 /*�w�q�C�^������O��1.5��*/
int main(void) {
    double beg_odo, end_odo;/*�ŧi�ܼ�:�_�l�ɪ����{�β��I���{*/
    printf("TAXI FARE CALCULATOR\n");
    printf("Enter beginning odometer reading=>");
    scanf("%lf", &beg_odo);/*��J�_�{�ɪ����{*/
    printf("Enter  ending odometer reading=>");
    scanf("%lf", &end_odo);/*��J���I���{*/

    /*�p���`�@��p�����{�ΩҪ�O�����B�ÿ�X*/
    printf("you traveled a distance of %.1lf miles. At $1.50 per mile, your fare is $ %.2lf", end_odo - beg_odo, (end_odo - beg_odo) * FARE_PER_MILE);
    return (0);
}
