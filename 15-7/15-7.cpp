#include<iostream>
#include"dice.h"
#include "loadedDice.h"
using namespace std;
int rollTwoDice(const dice& d1, const dice& d2);
int main() {/*test function*/
	loadeddice l,l1(7);
	dice d, d1(10);
	cout << "the first dice: " << l.rollDice() << endl;
	cout << "the second dice: " << d.rollDice()<<endl;
	cout << "the sum of the two dice roll again: " << rollTwoDice(l, d);
	return 0;
}
int rollTwoDice(const dice& d1, const dice& d2) {
	return d1.rollDice() + d2.rollDice();
}