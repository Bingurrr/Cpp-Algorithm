#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				int t = arr[j];
				arr[j] = arr[i];
				arr[i] = t;
			}
		}
	}
	int maxnum=1;
	int plus = 1;
	int minus = 1;
	if (arr[0] * arr[1] > 0) minus = arr[0] * arr[1];
	if (arr[n - 1] * arr[n - 2] > 0) plus = arr[n - 1] * arr[n - 2];
	maxnum = (plus > minus) ? plus : minus;
	if (maxnum == plus) {
		if (arr[n - 3] > 0) maxnum *= arr[n - 2];
	}
	else if (maxnum == minus) {
		if (arr[n - 1] > 0) maxnum *= arr[n - 1];
	}

	cout << maxnum;

	return 0;

}
	

