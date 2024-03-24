#include <iostream>
#include <math.h>
using namespace std;
int main() { 
    int rate[3], movie[3], predict[3], total, min = 100, nearest,c,k=0;/*變數:評分、電影編號、預測項、總距離、最小值、計算預測項的控制數*/
    int scale[4][6] = { 3,1,5,2,1,5,
                        4,2,1,4,2,4,
                        3,1,2,4,4,1,
                        5,1,4,2,4,2 };
    cout << "enter three movie numbers then the rates >>";
    for (int i = 0; i < 3; i++) {/*輸入*/
        cin >> movie[i] >> rate[i];
        movie[i] -= 100;
   }

    for (int i = 0; i < 6; i++) {/*計算預測項*/
        c = 0;
        for (int j = 0 ; j < 3; j++) {
            if (i != movie[j]) {
                c++;
            }
       }
        if (c == 3) {
            predict[k] = i;
            k++;
        }
    }
     
    for (int i = 0; i < 4; i++) {/*計算最符合哪個評分者*/
        total = 0;
        for (int j = 0; j < 3; j++) {
            total += pow(rate[j] - scale[i][movie[j]], 2);/*平方加總*/
        }
         if (min > total) {
             min = total;
             nearest = i;
         }
    }

    cout << "you match to reviewer " << nearest<<endl;/*輸出*/
    cout << "your predict>>"<<endl;
    for (int i = 0; i < 3; i++) {
        cout <<"the movie : "<<predict[i]+100<<" the rate : " << scale[nearest][predict[i]] <<endl;
    }
    return 0;
}