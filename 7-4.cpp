#include<iostream>
using namespace std;
class hotdogstand {/*define class hotdogstand*/
public:
	hotdogstand();
	hotdogstand(int id, int sold_hotdog);
	void setinfo();
	void accessor();
	void justsold();
	void calculate_total();
	static void total_sold();
	static int get_totalsold();

private:
	int ID, sold;
	static int totalsold ;
};

int hotdogstand::totalsold = 0;/*init the static member*/

int main() {/*test func*/
	hotdogstand stand1, stand2(2, 5);
	stand1.accessor();
	stand1.justsold();
	stand1.calculate_total();
	stand1.accessor();
	cout << endl;
	stand2.accessor();
	stand2.justsold();
	stand2.calculate_total();
	stand2.accessor();
	cout << "total sold: " << hotdogstand::get_totalsold(); /*output the total sold*/
	return 0;
}
hotdogstand::hotdogstand(){ /*default constructor*/
	setinfo();
}
hotdogstand::hotdogstand(int id, int sold_hotdog) :ID(id), sold(sold_hotdog) {}/*constructor*/

void hotdogstand::setinfo() {/*mutator*/
	cout << "enter the number of the stand and the sold number>>";
	cin >> ID >> sold;
}
void hotdogstand::accessor() {/*accessor*/
	cout << ID << " stand sold " << sold<<endl;
}
void  hotdogstand::justsold() {
	cout << "sold" << endl;
	sold += 1;
}
void  hotdogstand::calculate_total() {/*calculate_total*/
	for (int i = 0 ; i < sold; i++) {
		total_sold();
	}
}
void  hotdogstand::total_sold() { /*calculate_total*/
		totalsold+=1;
}
int hotdogstand::get_totalsold() { /*accessor of  the static member*/
	return totalsold;
}