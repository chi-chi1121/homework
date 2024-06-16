#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
using namespace std;
class creature
{
public:
	creature();/*constructor*/
	creature(int ntype,int str,int hit);/*constructor*/
	int getDamage();/*accessor*/
	int getType();/*accessor*/
	int getStrength();/*accessor*/
	int getHitpoint();/*accessor*/
	void setType(int t);/*mutator*/
	void setStrength(int s);/*mutator*/
	void setHitpoint(int h);/*mutator*/
private:
	int type; 
	int strength;
	int hitpoint;
	string getSpecies();
};
#endif // !CREATURE_H

