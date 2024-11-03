#include <iostream>
using namespace std;
#include "matrix.cpp"

int main() {
	Matrix m1(5);
	Matrix m2(5);
	float val = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			m1.SetValue(i, j, val);
			m2.SetValue(i, j, 25 - val);
			val++;
		}
	}

	m1.Print();
	cout << endl;
	m2.Print();
	cout << endl;
	(m1 + m2).Print();
 
	return 0;
}