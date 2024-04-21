#include <iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> grades;
	int grade, max = 0;
	cout << "Enter quiz scores," << "when you are finished enter -1." << endl;
	do
	{
		cin >> grade; /*input and fill the vector*/
		grades.push_back(grade);
	} while (grade != -1);
	grades.resize(grades.size() - 1);  /*subtract -1*/
	for (int i = 0; i < grades.size(); i++) {
		if (max < grades[i]) { /*pick the maxium grade*/
			max = grades[i];
		}
	}
	cout << "the maxium grade is " << max << endl;
	vector<int> hist(max+1); /*create new vector histogram*/
	for (int i = 0; i < grades.size(); i++) {
		hist[grades[i]]++;
	}
	for (int i = 1; i < hist.size(); i++) {
		cout << hist[i] << " grade(s) of " << i << endl; /*output*/
	}
	return 0;
}