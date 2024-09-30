#define _CRT_SECURE_NO_WARNINGS
//此程式用於計算到達最低平均需求所需的分數
#include<stdio.h>
int main(void) {
    char grade;/*宣告變數:評級*/
    double min_ave_req, cur_ave, percent; /*宣告變數:最低平均需求分數、當前平均分數、最後分數所占百分比*/
    printf("Enter desired grade>");
    scanf("%c", &grade);/*輸入評級*/
    printf("\nEnter minimum average required>");
    scanf("%lf", &min_ave_req);/*輸入最低平均需求分數*/
    printf("\nEnter current average in course>");
    scanf("%lf", &cur_ave);/*輸入當前平均分數*/
    printf("\nEnter how much the final counts as a percentage of the course grade>");
    scanf("%lf", &percent);/*輸入最後分數所占百分比*/
  /* 計算達最低平均需求所需的分數並輸出*/
    printf("you need a score %.2lf on the final to get %c", (min_ave_req - cur_ave * (100 - percent) / 100) / (percent / 100), grade);
    return (0);
}

