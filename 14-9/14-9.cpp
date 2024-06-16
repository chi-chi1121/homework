#include "creature.h"
#include "human.h"
#include "elf.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
#include <iostream>
using namespace std;
int main() {/*test function*/
	srand(time(0));
	human h(20,20);
	elf e(17,17);
	cyberdemon c;
	balrog b(15,15);
	cout << "damage: " << h.getDamage() << endl << "hitpoint: " << h.getHitpoint() << endl;
	cout << "damage: " << e.getDamage() << endl << "hitpoint: " << e.getHitpoint() << endl;
	cout << "damage: " << c.getDamage() << endl << "hitpoint: " << c.getHitpoint() << endl;
	cout << "damage: " << b.getDamage() << endl << "hitpoint: " << b.getHitpoint() << endl;
	return 0;
}