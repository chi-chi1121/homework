#include "loadedDice.h"
loadeddice::loadeddice() :sidenum(6) {/*constructor*/
	srand(time(0));
}
loadeddice::loadeddice(int num) :sidenum(num) {/*constructor*/
	srand(time(0));
}
int loadeddice::rollDice() const {/*virtual function*/
	if (rand() % 2 == 1) {
		return sidenum;
	}
	else
	{
		return (rand() % sidenum + 1);
	}
}