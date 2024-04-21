#include<iostream>
using namespace std;
class zipcode {/*define class zipcode*/
public:
    zipcode(int);
    zipcode(string);

    int getZipCodeNumber(int);
    string getZipCodeString();

private:
    string code;
    int value[5] = { 7,4,2,1,0 };
    void convertToString(int);
    int convertToInt();
};
int main() {/*test func*/
    zipcode code1(98504);
    cout << "1" + code1.getZipCodeString() + "1" << endl;
    zipcode code2(92627);
    cout << "1" + code2.getZipCodeString() + "1" << endl;

    zipcode code3("1010010100010101100001001");
    cout << endl;

    zipcode code4("0101000101011000010110001");
    cout << endl;

    zipcode code5(12345);
    cout << "1" + code5.getZipCodeString() + "1" << endl;

    zipcode code6(00000);
    cout << "1" + code6.getZipCodeString() + "1" << endl;
}

zipcode::zipcode(string input):code(input) {/*constructor*/
    cout << "POST NET CODE: " << "1" + input + "1" << endl;
    cout << getZipCodeNumber(convertToInt());
}

zipcode::zipcode(int input) {/*constructor*/
    cout << "ZIP CODE: " << input << endl;
    convertToString(input);
}

void zipcode::convertToString(int input) {/*let input convert to string*/
    int digits[5] = { 0 }, digit, reminder, c = 0;
    char array[25];
    bool flag = false;
    reminder = input;
    for (int i = 0; i < 5; i++) {
        digit = reminder / pow(10, 4 - i);
        digits[i] = digit;
        reminder = reminder % int(pow(10, 4 - i));
    }
    while (c<5)
    {
        for (int i = 0; i < 5; i++) {
              for (int j = i + 1; j < 5; j++) {
                  if ((value[i] + value[j] == digits[c]) || ((value[i] + value[j] == 11) && digits[c] == 0)) {
                      array[i + 5 * c] = '1';
                      array[j + 5 * c] = '1';
                      break;
                  }
              }       
          }   
        for (int k = 0; k < 5; k++) {
              if (array[k + c * 5] != '1') {
                   array[k + c * 5] = '0';
              }
        }
     c++;
    }
    for (int i = 0; i < 25; i++) {
        code += array[i];
    }
}

int zipcode::convertToInt() {/*let input convert to int*/
    int number=0, digit=0;
    for (int i = 0; i < 5; i++) {
        digit = 0;
        for (int j = 0 + i * 5; j < (i + 1) * 5; j++) {
            digit+=value[j - (i * 5)] * (code[j]-'0');
            cout << " " << digit;
        }
        if (digit != 11) {
        number *= 10;
        number += digit;
        }
        else if (digit == 11) {
            number *= 10;
        }
        
    }
    return number;
}

string zipcode::getZipCodeString() {/*accessor*/
    cout << "The zip code encoded is: ";
    return code;
}

int zipcode::getZipCodeNumber(int decodedString) {/*accessor*/
    cout << "The zip code decoded is: ";
    return decodedString;
}