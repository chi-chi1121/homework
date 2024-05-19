#include<iostream>
#include<string>
using namespace std;
int main() {
	int c = 0;  /*the count of the char*/
	string input; /*input*/
	cout << "enter the text"<<endl;
	getline(cin,input); /*input the string*/
	for (int i = 0; i < input.length(); i++) {
		c++;
		if (input[i] == ' ') {/*if the char is blank*/
			if (c == 5) {
				/*check if it's a four letter word*/
				if(!isupper(input[i-4]))
				{
					input.erase(i - 4, 4);/*replace it to love*/
					input.insert(i-4, "love");
				}
				else if (isupper(input[i - 4])) {
					/*check if it's an upper word*/
					input.erase(i - 4, 4);
					input.insert(i-4, "Love");
				}
			}
			c = 0;		
		}

		if (i == input.length() - 1) { /*do the same check when the string end*/
			if (c == 4) {
				if (!isupper(input[i - 3]))
				{
					input.erase(i - 3, 4);
					input.insert(i - 3, "love");
				}
				else if (isupper(input[i - 3])) {
					input.erase(i - 3, 4);
					input.insert(i - 3, "Love");
				}
			}
		}
	}
	cout << input; /*output*/
	return 0;
}
