#include <iostream>
using namespace std;

int main() {

	int alen, blen;
	cin >> alen;
	int A[5];

	for (int i = 0; i < alen; i++) 
		cin >> A[i];

	cin >> blen;
	int B[6];

	for (int i = 0; i < blen; i++)
		cin >> B[i];

	//교집합
	int count1 = 0;
	int *C = new int[100];
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < alen; j++) {
			if (A[j] == i) {
				for (int k : B) {
					if (k == A[j]) {
						C[count1] = k;
						count1++;
						break;
					}
				}
			}
		}
	}
	cout << count1 << " ";
	for (int i = 0; i < count1; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
	//합집합
	int* D = new int[100];
	int count2 = 0;
	for (int i = 1; i <= 100; i++) {
		for (int a : A) {
			if (a == i) {
				D[count2] = a;
				count2++;
				break;
			}
		}
		if(count2 >=1){
			if (D[count2 - 1] == i)
				continue;
	}
		for (int b : B) {
			if (b == i) {
				D[count2] = b;
				count2++;
				break;
			}
		}
	}
	cout << count2 << " ";
	for (int i = 0; i < count2; i++) {
		cout << D[i] << " ";
	}
	cout << endl;

	//차집합
	int* E = new int[100];
	int count3 = 0;
	bool set = false;
	for (int i = 1; i <= 100; i++) {
		for (int a : A) {
			set = false;
			if (a == i) {
				for (int j = 0; j < count1; j++) {
					if (a == C[j]) {
						set = true;
					}
				}
				if (set == false) {
					E[count3] = a;
					count3++;
				}
			}
		}
	}
	cout << count3 << " ";
	for (int i = 0; i < count3; i++) {
		cout << E[i] << " ";
	}
	return 0;
} 
