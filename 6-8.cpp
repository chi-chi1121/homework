#include <iostream>
using namespace std;

class money /*define class money*/
{
public:
	void mutator();/*mutator and accessor*/
	void accessor();
	
private:
	int dollar, cent;
};

int main() {
	money money1,money2;
	cout << "enter the money>>" << endl;
	money1.mutator();
	money1.accessor();
	cout << endl;
	cout << "enter the money>>" << endl;
	money2.mutator();
	money2.accessor();
	return 0;
}

void money::mutator() {/*set the dollar and cent*/
	char dot;
	cin >> dollar >> dot >> cent;
}

void money::accessor() { /*get the money*/
	cout <<"the money is :" << dollar << "." << cent << "$" << endl;
}