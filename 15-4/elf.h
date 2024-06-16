#ifndef ELF_H
#define ELF_H
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;
class elf :public creature
{
public:
	elf();/*constructor*/
	elf(int str, int hit);/*constructor*/
private:
	int type = 3;
	int strength;
	int hitpoint;
};
#endif 

