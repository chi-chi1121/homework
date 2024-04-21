#include <iostream>

using namespace std;

void inputTime(int& hours, int& minutes);/*�禡:��J�B��X�B�ɶ��ഫ*/
void timeConversion(int& hours, char& timeOfDay);
void outputTime(int hours, int minutes, char timeOfDay);
int main()
{
    char timeOfDay = ' ', userAnswer = ' ';
    int hours = 0, minutes = 0;

    do {
        inputTime(hours, minutes);
        timeConversion(hours, timeOfDay);
        outputTime(hours, minutes, timeOfDay);
        cout << "Would you like to calculate another time(Enter y or Y)?: ";
        cin >> userAnswer;

    } while (userAnswer == 'y' || userAnswer == 'Y');/*�p�G�ϥΪ̿�JY���ƨϥ�*/
    return 0;
}

void inputTime(int& hours, int& minutes)/*��J�ɶ�*/
{
    cout << "Please enter the current hour: ";
    cin >> hours;

    cout << "Please enter the current minutes: ";
    cin >> minutes;

}

void timeConversion(int& hours, char& timeOfDay)/*�ɶ��ഫ(24->12)*/
{
    if (hours >= 0 && hours <= 11)/*�Y�p��<12���W��*/
    {
        if (hours == 0) {
            hours += 12;
        }
        timeOfDay = 'A';
    }
    else {
        if (hours > 12) {/*�Y�p��<12���U��*/
            hours -= 12;
        }
        timeOfDay = 'P';
    }

}

void outputTime(int hours, int minutes, char timeOfDay) {/*��X�ɶ�*/

    if (minutes == 0) {
        cout << "The 12-hour notation is " << hours << ":" << minutes << "0 " << timeOfDay << ".M." << endl;
    }
    else {
        cout << "The 12-hour notation is " << hours << ":" << minutes << " " << timeOfDay << ".M." << endl;
    }
}