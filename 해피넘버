#include <iostream>
using namespace std;

int getValue(int a);
bool already(int *arr, int a);

int main() {
	int a;
	cin >> a;
	int count = 0;
	int *arr = new int[1000];
	while (1) {
		int num = getValue(a);
		a = num;
		arr[count] = num;
		count++;
		bool answer = already(arr, num);
		if (num == 1) {
			cout << "HAPPY";
			break;
		}
		else if (answer == true) {
			cout << "UNHAPPY";
			break;
		}
	}
	return 0;

}

int getValue(int a) {
	int value = 0;
	while (a >= 10) {
		value += (a % 10) * (a% 10);
		a /= 10;
	}
	return value+(a*a);
}
bool already(int *arr, int a) {
	int count = 0;
	for (int i = 0; i < 1000; i++) {
		if (arr[i] == a) {
			count++;
            if(count == 2)
                return true;
		}
	}
	return false;
}
