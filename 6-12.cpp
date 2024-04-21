#include <iostream>
#include  <fstream>
using namespace std;

void readfile(string produce[]);

class BoxOfProduce /*define class boxofproduce*/
{
public:
	void mutator();
	void accessor();
	void substitute();

private:
	string produce[3];
};

int main() {/*test all the function*/
	srand(time(0));
	BoxOfProduce box1;
	box1.mutator();
	box1.accessor();
	cout << endl; 
	cout << endl;
	box1.substitute();
	cout << endl;
	box1.accessor();
	return 0;
}

void readfile(string produce[]) {/*read the file and fill the sring array*/
	fstream input;
	input.open("product.txt");
	for (int i = 0; i < 5; i++) {
		input >> produce[i];
	}
}

void BoxOfProduce::mutator() {/*let the private member filled with 3 random produce from total produce*/
	int rand_num;
	string total_produce[5];
	readfile(total_produce);
	for (int i = 0; i < 3; i++) {
		rand_num = rand() % 5;
		produce[i] = total_produce[rand_num];
	}
}

void BoxOfProduce::accessor() {/*cout the produce*/
	cout << "accessor:";
	for (int i = 0; i < 3; i++) {
		cout << produce[i]<<" ";
	}
}

void BoxOfProduce::substitute() {/* substitute  one produce in the private member array*/
	int replaced;
	string sub;
	for (int i = 0; i < 3; i++) {
		cout << produce[i] << " ";
	}
	cout << endl;
	cout << "which one you want to replace(eneter the number according to the above order)";
	cin >> replaced;
	replaced -= 1;
	cout  << "then enter the fruit or vagetable yuou want to substitute";
	cin >> sub;
	produce[replaced] = sub;
}