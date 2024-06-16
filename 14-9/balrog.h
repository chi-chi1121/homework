#ifndef BALROG_H
#define BALROG_H
#include <iostream>
#include <string>
#include "demon.h"
using namespace std;
class balrog :public demon
{
public:
	balrog();/*constructor*/
	balrog(int str, int hit);/*constructor*/
private:
	int type = 1;
	int strength;
	int hitpoint;
};
#endif 