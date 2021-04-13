#include <iostream>

using namespace std;

int main() {

	int r, s;
	cin >> r >> s;
	int** A = new int* [r];
	int** B = new int* [r];
	//A행렬 입력
	for (int i = 0; i < r; i++) {
		A[i] = new int[s];
		for (int j = 0; j < s; j++) {
			cin >> A[i][j];
		}
	}
	//B행렬 입력
	for (int i = 0; i < r; i++) {
		B[i] = new int[s];
		for (int j = 0; j < s; j++) {
			cin >> B[i][j];
		}
	}
	//답 출력
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			cout << A[i][j] + B[i][j] << " ";
		}
		cout << endl;
	}

}
