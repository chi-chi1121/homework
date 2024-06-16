#ifndef DICE_H
#define DICE_H
#include<iostream>
using namespace std;
class dice
{
public:
	dice();/*constructor*/
	dice(int num);/*constructor*/
	int getSidenum();/*accessor*/
	int virtual rollDice() const; /*virtual function*/
private:
	int sidenum;
};


#endif // !DICE_H

