#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main() {
	Matrix m1(2);
	Matrix m2(2);
	cin >> m1;
	cout << "m1:" << endl << m1;
	cin >> m2;
	cout << "m2:" << endl << m2;
	cout << "m1[1, 1]:" << endl;
	int test_int;
	cin >> test_int;
	m1.setMatrix(1, 1, test_int);
	cout << "m1:" << endl << m1;
	Matrix m3 = m1 + m2;
	cout << "m1 + m2:" << endl << m3;
	Matrix m4 = m1 - m2;
	cout << "m1 - m2:" << endl << m4;
	Matrix m5 = m1 * m2;
	cout << "m1 * m2:" << endl << m5;
}