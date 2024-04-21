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
    zipcode code1(99504);
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
    int brokenZipCode[5] = { 0 };
    int remainder = 0;
    char stringOfLines[25];
    int index = 0;
    bool flag = false;

    for (int i = 0; i < 5; i++)
    {
        remainder = input % static_cast<int>(pow(10, (5- 1) - i));
        brokenZipCode[i] = input / (pow(10, (5 - 1) - i));
        input = remainder;
    }

    int carryOn = 0;

    while (index < 5)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if ((value[i] + value[j] == brokenZipCode[index]) || ((value[i] + value[j] == 11) && brokenZipCode[index] == 0))
                {
                    stringOfLines[i + carryOn] = '1';
                    stringOfLines[j + carryOn] = '1';
                    flag = true;
                    break;
                }
            }
            if (flag == true)break;
        }
        flag = false;

        for (int i = 0; i <5; i++)
        {
            if (stringOfLines[i + carryOn] != '1')stringOfLines[i + carryOn] = '0';
        }
        index += 1;
        carryOn += 5;
    }

    for (int i = 0; i < 25; i++)
    {
        code += stringOfLines[i];
    }
}

int zipcode::convertToInt() {/*let input convert to int*/
    int decode = 0, toAdd = 0,k=0;
    for (int i = 0; i < 25; i += 5)
    {
        for (int j = 0; j < 5; j++)
        {
            if (code[i + j] == '1') {
                toAdd += value[j];
            }
            if (toAdd == 11)toAdd = 0;
        }
        decode += toAdd * pow(10, (5 - 1) - k);
        toAdd = 0;
        k++;
    }
    return decode;
}

string zipcode::getZipCodeString() {/*accessor*/
    cout << "The zip code encoded is: ";
    return code;
}

int zipcode::getZipCodeNumber(int decodedString) {/*accessor*/
    cout << "The zip code decoded is: ";
    return decodedString;
}