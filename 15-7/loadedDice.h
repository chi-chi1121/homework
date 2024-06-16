#ifndef LOADEDDICE_H
#define LOADEDDICE_H
#include<iostream>
#include"dice.h"
using namespace std;
class loadeddice:public dice
{
public:
	loadeddice();/*constructor*/
	loadeddice(int num);/*constructor*/
	int rollDice() const override;/*virtual function*/
private:
	int sidenum;
};
#endif 