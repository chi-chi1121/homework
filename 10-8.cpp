#include<iostream>
#include<string>
using namespace std;
class Television /*define class TV*/
{
public:
	Television();/*constructor*/
	Television(const Television&);/*copy constructor*/
	~Television();/*desturctor*/
	double getDiemsion() { return dimension; };/*accessor*/
	string getType() { return displayType;};
	void input();/*mutator*/
	void output();/*accessor*/
	Television& operator =(const Television& t1); /*operator overloading*/
private:
	string displayType;
	double dimension;
	int numofsup;
	string* support;
};
int main() {/*test funtion*/
	char ask;
	int num;
	cout << "enter the number of tv: ";
	cin >> num;
	Television* tv,* copy;	
	tv = new Television[num];
	copy = new Television[num];
	cout << "do you want to cumstomize your TV?(y/n):";
	do{
		cin >> ask;
		if (ask != 'y' && ask != 'n') {
			cout << "wrong input";
		}
	} while (ask != 'y' && ask != 'n');

	if (ask == 'y') {
		for (int i = 0; i < num; i++) {
			tv[i].input();
		}
	}
	cout << "output" << endl;
	for (int i = 0; i < num; i++) {
		tv[i].output();
	}
	
	cout<< "copy:" << endl;
	for (int i = 0; i < num; i++) {
		copy[i]=tv[i];
	}
	for (int i = 0; i < num; i++) {
		copy[i].output();
	}
	delete[] tv;
	delete[] copy;
	return 0;
}

Television::Television():displayType("none"), dimension(0),numofsup(1) /*default constructor*/
{
	support = new string[numofsup];
	support[0] = "none";
}

Television::Television(const Television& t1) :displayType(t1.displayType), dimension(t1.dimension),numofsup(t1.numofsup) {/*copy constructor*/
	support = new string[numofsup];
	for (int i = 0; i < numofsup;i++) {
		support[i] = t1.support[i];
	}
}

Television::~Television() /*destructor*/
{
	delete[] support;
}
void Television::input() {/*mutator*/
	cout << "enter the display type of TV:";
	cin >> displayType;
	cout << "enter the dimension of the TV(inches):";
	cin >> dimension;
	cout  << "enter the number of connectivity support it has:";
	cin >> numofsup;
	cout  << "enter the connectivity support:"<<endl;
	support = new string[numofsup];
	for (int i = 0; i < numofsup; i++) {
		cout << i + 1 << ".";
		cin >> support[i];
	}
}
void Television::output() {/*accessor*/
	cout << "the TV type is " << displayType << endl;
	cout << "the dimensions of the TV is " << dimension << " inches" << endl;
	cout << "the connectivity support is ";
	for (int i = 0; i < numofsup; i++) {
		cout << i + 1 << ".";
		cout<< support[i];
		cout << " ";
	}
	cout << endl<<endl;
}
Television& Television::operator =(const Television& t1) {/*overloading operrator =*/
	/*let each member of tv = each member of t1*/
	delete[] support;
	displayType = t1.displayType;
	dimension = t1.dimension; 
	numofsup=t1.numofsup;
	support = new string[numofsup]; /*re-declare the memory space*/
	for (int i = 0; i < numofsup; i++) {
		support[i] = t1.support[i];
	}
	return (*this);
}