#include "creature.h"
#include <iostream>
using namespace std;
creature::creature():type(0),strength(10),hitpoint(10) {}/*constructor*/
creature::creature(int ntype,int str, int hit) :type(ntype), strength(str), hitpoint(hit) {}/*constructor*/
int creature::getDamage() { /*accordin to different type deal different damage*/
	int damage = (rand() % strength) + 1;
	if (getSpecies() == "cyberdemon"||getSpecies()=="balrog") {
		if (rand() % 100 < 5) {
			damage += 50;
			cout << "demon attack for 50 additional damage points" << endl;
		}
		if (getSpecies() == "balrog") {
			int damage2 = (rand() % strength) + 1;
			damage += damage2;
			cout << "balrog speed attack for " << damage2 << " extra damage points" << endl;
		}
	}
	else if (getSpecies() == "elf") {
		if (rand() % 10 < 1) {
			damage *= 2;
			cout << "elf attack for double magical damage points" << endl;
		}
	}
	cout << getSpecies() << " attack for " << damage << " points" << endl;
	return damage;
}
int creature::getType() {/*accessor*/
	return type;
}
int creature::getStrength() {/*accessor*/
	return strength;
}
int creature::getHitpoint() {/*accessor*/
	return hitpoint;
}
void creature::setType(int t) {/*mutator*/
	type = t;
}
void creature::setStrength(int s) {
	strength = s;
}/*mutator*/
void creature::setHitpoint(int h) {
	hitpoint = h;
}/*mutator*/
string creature::getSpecies() {/*accessor*/
	switch (getType()) {
	case 0: 
		return "human";
	case 1: 
		return "cyberdemon";
	case 2: 
		return "balrog";
	case 3: 
		return "elf";
	}
	return "none";
}