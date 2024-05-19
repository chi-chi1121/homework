#include<iostream>
#include<string>
using namespace std;

class subscriber
{
public:
	subscriber();/*constructor*/
	int getNumchannel() { return numchannel; };/*accessor*/
	string getName() { return name; };
	void getChannelList();/*accessor*/
	void outPut();
	void inPut();/*mutator*/
	void resetSubscriber(); /*reset funciton*/
	subscriber& operator =(const subscriber&); /*operator = overloading*/
	~subscriber();/*desturctor*/
private:
	string name;
	int numchannel;
	string* channelLists; /*dynamic array of string*/
};

int main() { /*test function*/
	subscriber user, copy;
	user.inPut();
	user.outPut();

	cout << endl << "The copy of the first sub:" << endl;
	copy = user;
	copy.outPut();
	cout << endl << "Reset the first sub:" << endl;
	user.resetSubscriber();
	user.outPut();
	return 0;
}


subscriber::subscriber() :name("me"), numchannel(1)/*constructor*/
{
	channelLists = new string[numchannel]; /*new an array*/
}

subscriber::~subscriber()
{
	delete[] channelLists; /*destructor*/
}
void subscriber::getChannelList() {/*accessor*/
	for (int i = 0; i < numchannel; i++) {
		cout << channelLists[i];/*cout the arrray*/
	}
}
void subscriber::outPut() {/*accessor*/
	cout << "name:" << name << endl;/*cout the name*/
	cout << "numberchannel:" << numchannel << endl;/*cout the number of channel*/
	cout << "channelList:";/*cout the arrray*/
	for (int i = 0; i < numchannel; i++) {
		cout << channelLists[i];
		if (i != numchannel - 1)
		{
			cout << ",";
		}
	}
	cout << endl;
}

void subscriber::inPut() {/*mutator*/
	cout << "enter the channel name ? >> ";/*setinfo*/
	cin >> name;
	cout << "enter the number of the channel? >> ";
	cin >> numchannel;
	channelLists = new string[numchannel]; /*new an array*/
	cout << "Input each channel name: " << endl;
	for (int i = 0; i < numchannel; i++) {
		cout << i + 1 << ". ";
		cin >> channelLists[i];
	}
}

void subscriber::resetSubscriber() {/*reset member fo the sub*/
	for (int i = 0; i < numchannel; i++)
	{
		channelLists[i].erase();/*reset the arrary*/
	}
	numchannel = 0;
}

subscriber& subscriber:: operator =(const subscriber& s2) {
	/*let all of the s2 member equals to the s1*/
	name = s2.name;
	numchannel = s2.numchannel;
	delete[] channelLists;
	channelLists = new string[numchannel];
	for (int i = 0; i < s2.numchannel; i++) {
		channelLists[i] = s2.channelLists[i];
	}
	return (*this);
}
