#include <iostream>

using namespace std;

int main() {
	
	int x;
	cin >> x;
	int num = 0;
	int line = 0;
	string str = "";
	//위쪽 모래시계
	for (int i = 0; i < x/2+1; i++) {
		string str = "";
		for (int j = 0; j < i; j++) {
			str += "-";
		}
		for (int k = 0; k < x/2-i; k++) {
			str += "*+";
		}
		str += "*";
		for (int j = 0; j < i; j++) {
			str += "-";
		}
		cout << str << endl;
	}
	//아래쪽 모래시계
	for (int i = x/2; i>0; i--) {
		string str = "";
		for (int j = 0; j < i-1; j++) {
			str += "-";
		}
		for (int k = 0; k < x / 2 - i+1; k++) {
			str += "*+";
		}
		str += "*";
		for (int j = 0; j < i-1; j++) {
			str += "-";
		}
		cout << str << endl;
	}

}
