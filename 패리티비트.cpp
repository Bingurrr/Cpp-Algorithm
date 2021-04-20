#include <iostream>
using namespace std;

int main(void) {
	unsigned int n, v;
	bool parity = false;

	cin >> n;
	v = n & 0x7FFFFFFF;
	for (int i = 0; i < 31; i++, v >>= 1) {
		if (v % 2) parity = !parity;
	}
	if (parity) { n += 0x80000000; }
	cout << n << endl;

	return 0;
}
