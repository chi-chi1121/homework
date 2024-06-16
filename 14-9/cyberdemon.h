#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include <iostream>
#include <string>
#include "demon.h"
using namespace std;
class cyberdemon :public demon
{
public:
	cyberdemon();/*constructor*/
	cyberdemon(int str, int hit);/*constructor*/
private:
	int type=1;
	int strength;
	int hitpoint;
};
#endif 
