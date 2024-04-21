#include <iostream>

using namespace std;

void inputTime(int& hours, int& minutes);/*函式:輸入、輸出、時間轉換*/
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

    } while (userAnswer == 'y' || userAnswer == 'Y');/*如果使用者輸入Y重複使用*/
    return 0;
}

void inputTime(int& hours, int& minutes)/*輸入時間*/
{
    cout << "Please enter the current hour: ";
    cin >> hours;

    cout << "Please enter the current minutes: ";
    cin >> minutes;

}

void timeConversion(int& hours, char& timeOfDay)/*時間轉換(24->12)*/
{
    if (hours >= 0 && hours <= 11)/*若小時<12為上午*/
    {
        if (hours == 0) {
            hours += 12;
        }
        timeOfDay = 'A';
    }
    else {
        if (hours > 12) {/*若小時<12為下午*/
            hours -= 12;
        }
        timeOfDay = 'P';
    }

}

void outputTime(int hours, int minutes, char timeOfDay) {/*輸出時間*/

    if (minutes == 0) {
        cout << "The 12-hour notation is " << hours << ":" << minutes << "0 " << timeOfDay << ".M." << endl;
    }
    else {
        cout << "The 12-hour notation is " << hours << ":" << minutes << " " << timeOfDay << ".M." << endl;
    }
}