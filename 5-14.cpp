#include <iostream>
#include <math.h>
using namespace std;
int main() { 
    int rate[3], movie[3], predict[3], total, min = 100, nearest,c,k=0;/*�ܼ�:�����B�q�v�s���B�w�����B�`�Z���B�̤p�ȡB�p��w�����������*/
    int scale[4][6] = { 3,1,5,2,1,5,
                        4,2,1,4,2,4,
                        3,1,2,4,4,1,
                        5,1,4,2,4,2 };
    cout << "enter three movie numbers then the rates >>";
    for (int i = 0; i < 3; i++) {/*��J*/
        cin >> movie[i] >> rate[i];
        movie[i] -= 100;
   }

    for (int i = 0; i < 6; i++) {/*�p��w����*/
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
     
    for (int i = 0; i < 4; i++) {/*�p��̲ŦX���ӵ�����*/
        total = 0;
        for (int j = 0; j < 3; j++) {
            total += pow(rate[j] - scale[i][movie[j]], 2);/*����[�`*/
        }
         if (min > total) {
             min = total;
             nearest = i;
         }
    }

    cout << "you match to reviewer " << nearest<<endl;/*��X*/
    cout << "your predict>>"<<endl;
    for (int i = 0; i < 3; i++) {
        cout <<"the movie : "<<predict[i]+100<<" the rate : " << scale[nearest][predict[i]] <<endl;
    }
    return 0;
}