	#define _CRT_SECURE_NO_WARNINGS
/*此程式用計算計程車的費用 */
#include<stdio.h>
#define FARE_PER_MILE 1.5 /*定義每英里的花費為1.5元*/
int main(void) {
    double beg_odo, end_odo;/*宣告變數:起始時的里程及終點里程*/
    printf("TAXI FARE CALCULATOR\n");
    printf("Enter beginning odometer reading=>");
    scanf("%lf", &beg_odo);/*輸入起程時的里程*/
    printf("Enter  ending odometer reading=>");
    scanf("%lf", &end_odo);/*輸入終點里程*/

    /*計算總共行駛的里程及所花費的金額並輸出*/
    printf("you traveled a distance of %.1lf miles. At $1.50 per mile, your fare is $ %.2lf", end_odo - beg_odo, (end_odo - beg_odo) * FARE_PER_MILE);
    return (0);
}
