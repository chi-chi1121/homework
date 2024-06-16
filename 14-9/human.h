#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;
class human:public creature
{
public:
	human();/*constructor*/
	human(int str, int hit);/*constructor*/
private:
	int type=0;
	int strength;
	int hitpoint;
};
#endif 
