#include <iostream>
#include <bitset>

using namespace std;

int main(){

	char a = -1;
	bitset<8> x(a);
	cout << x << endl;

	short c = -315;
	bitset<16> y(c);
	cout << y << endl;
	return 0;
}
