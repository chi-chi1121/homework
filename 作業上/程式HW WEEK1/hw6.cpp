#define _CRT_SECURE_NO_WARNINGS
//���{���Ω�p���F�̧C�����ݨD�һݪ�����
#include<stdio.h>
int main(void) {
    char grade;/*�ŧi�ܼ�:����*/
    double min_ave_req, cur_ave, percent; /*�ŧi�ܼ�:�̧C�����ݨD���ơB��e�������ơB�̫���Ʃҥe�ʤ���*/
    printf("Enter desired grade>");
    scanf("%c", &grade);/*��J����*/
    printf("\nEnter minimum average required>");
    scanf("%lf", &min_ave_req);/*��J�̧C�����ݨD����*/
    printf("\nEnter current average in course>");
    scanf("%lf", &cur_ave);/*��J��e��������*/
    printf("\nEnter how much the final counts as a percentage of the course grade>");
    scanf("%lf", &percent);/*��J�̫���Ʃҥe�ʤ���*/
  /* �p��F�̧C�����ݨD�һݪ����ƨÿ�X*/
    printf("you need a score %.2lf on the final to get %c", (min_ave_req - cur_ave * (100 - percent) / 100) / (percent / 100), grade);
    return (0);
}

