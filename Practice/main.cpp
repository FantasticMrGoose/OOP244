
#include <iostream>
#include "ram.h"
#include "calculate.h"
using namespace std;
using namespace sdds;

class WEB222
{
	int* ids;
	int size;
public:
	WEB222() {
		ids = nullptr;
	}
	WEB222(const int* ids_, int n) {
		ids = new int[n];
		for (int i = 0; i < n; i++) // add for loop to copy all arrays
		{
			ids[i] = ids_[i];
		}
		size = n;
	}
	~WEB222() { //no parameters allowed in destructor, use variable size instead
		cout << "deleting all " << size << " ids." << endl;
		delete[] ids;
	}
	void display() const {
		for (int i = 0; i < size; i++)
		{
			cout << "id; " << ids[i] << endl; // change to i
		}
	}

	void prn(const WEB222& spp) {
		spp.display(); // since argument is a const, it does not match with the function call for display. either make display const or remove const in prn
	}


};



int main() {
	/*Memory stick(2);
	stick += 500;
	cout << stick;*/

	int ids[3] = { 23135, 52134, 67112 };
	WEB222 sjj(ids, 3), sbb; // no default constructor

	sjj.prn(sjj);// wrong format for function call
	sbb.display();


	double a[3] = { 1.0, 2.0, 3.0 };
	int b[3] = { 1, 2, 3 };
	char c[3] = { 'a','b','c' };
	double x = mult(a, 3);
	cout << x;
	cout << endl;
	int y = mult(b, 3);
	cout << y;
	cout << endl;
	char z = mult(c, 3);
	cout << z;
	cout << endl;
	return 0;

	return 0;

}