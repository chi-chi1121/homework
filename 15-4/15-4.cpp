#include "creature.h"
#include "human.h"
#include "elf.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
#include <iostream>
using namespace std;
void battleArea(creature& c1, creature& c2);
bool battle_end(int, int);
int main() {/*test function*/
	srand(time(0));
	human h(20,20);
	elf e(17,17);
	cyberdemon c;
	balrog b(15,15);
	battleArea(h, e);
	return 0;
}
void battleArea(creature& c1, creature& c2) {
	string list[4] = { "human","cyberdemon","balrog","elf" };
	int e = 0;
	do
	{
		if(e==0){

			c2.setHitpoint(c2.getHitpoint() - c1.getDamage()); /*set point according to the damage and hit point*/
			cout << list[c2.getType()] << "'s HP : " << c2.getHitpoint() << endl;
			if (battle_end && c2.getHitpoint() <= 0) {
				e = 1;
				cout << list[c1.getType()] << " win" << endl;
			}
		}
		if(e==0){
			c1.setHitpoint(c1.getHitpoint() - c2.getDamage());/*set point according to the damage and hit point*/
			cout << list[c1.getType()] << "'s HP : " << c1.getHitpoint() << endl;
			if (battle_end && c1.getHitpoint() <= 0) {
				e = 1;
				cout << list[c2.getType()] << " win" << endl;
			}
		}
	} while (e==0);
}
bool battle_end(int h1, int h2) {/*test if the battle end*/
	return (h1 <= 0 || h2 <= 0);
}