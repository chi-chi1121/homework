#include "dice.h"
#include <iostream>
using namespace std;
dice::dice():sidenum(6){/*constructor*/
	srand(time(0));
}
dice::dice(int num):sidenum(num) {/*constructor*/
	srand(time(0));
}
int dice::getSidenum() {/*accessor*/
	return sidenum;
}
int dice::rollDice() const {/*virtual function*/
	return (rand() % sidenum + 1);
}