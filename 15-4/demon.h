#ifndef DEMON_H
#define DEMON_H
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;
class demon :public creature
{
public:
	demon();/*constructor*/
	demon(int dtype,int str, int hit);/*constructor*/
private:
	int dtype;
	int strength;
	int hitpoint;
};
#endif 
