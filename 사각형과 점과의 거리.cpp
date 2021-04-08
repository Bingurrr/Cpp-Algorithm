#include <iostream>

using namespace std;

int main() {

	int x1, y1, x2, y2, x, y;

	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	int d1, d2;
	//가지 경우의수 1,2,3,4,5,6,7,8,9
	if (x1 <= x && x <= x2) {
		//5
		if (y1 <= y && y <= y2)
			cout << 0 << " " << 0;
		//2
		else if (y2 <= y) {
			d1 = (y - y2) * (y - y2);
			d2 = y - y2;
			cout << d1 << " " << d2;
		}
		//8
		else {
			d1 = (y - y1) * (y - y1);
			d2 = y1 - y;
			cout << d1 << " " << d2;
		}
	}

	else if (y1 <= y && y <= y2) {
		//6
		if (x2 <= x) {
			d1 = (x - x2) * (x - x2);
			d2 = x - x2;
			cout << d1 << " " << d2;
		}
		//4
		else {
			d1 = (x - x1) * (x - x1);
			d2 = x1 - x;
			cout << d1 << " " << d2;
		}
	}
	else {
		//1
		if (x <= x1 && y >= y2) {
			d1 = (x1 - x) * (x1 - x) + (y2 - y) * (y2 - y);
			d2 = (x1 - x) + (y - y2);
			cout << d1 << " " << d2;
		}
		//3
		else if (x >= x2 && y >= y2) {
			d1 = (x - x2) * (x - x2) + (y2 - y) * (y2 - y);
			d2 = (x - x2) + (y - y2);
			cout << d1 << " " << d2;
		}
		//7
		else if(x <= x1 && y <= y1) {
			d1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
			d2 = (x1 - x) + (y1 - y);
			cout << d1 << " " << d2;
		}
		//9
		else {
			d1 = (x2 - x) * (x2 - x) + (y1 - y) * (y1 - y);
			d2 = (x - x2) + (y1 - y);
			cout << d1 << " " << d2;
		}
	}
	return 0;


}
