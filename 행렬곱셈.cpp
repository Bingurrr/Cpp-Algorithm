#include <iostream>

using namespace std;

int main() {
	
	int a, b, c;
	cin >> a >> b >> c;
	int **matrixA = new int*[a];
	int **matrixB = new int*[b];
	int **answer = new int*[a];

	//A행렬 값입력
	for (int i = 0; i < a; i++) {
		matrixA[i] = new int[b];
		for (int j = 0; j < b; j++) {
			cin >> matrixA[i][j];
		}
	}
	//B행렬 값입력
	for (int i = 0; i < b; i++) {
		matrixB[i] = new int[c];
		for (int j = 0; j < c; j++) {
			cin >> matrixB[i][j];
		}
	}
	//answer행렬
	for (int i = 0; i < a; i++) {
		answer[i] = new int[c];
		for (int j = 0; j < c; j++) {
			answer[i][j] = 0;
		}
	}
	//answer 행렬 곱셈
	int s = 0;
	int t = 0;
	for (int r = 0; r < a * c; r++) {
		if (t == c) {
			s++;
			t = 0;
		}
		for (int i = 0; i < b; i++) {
			answer[s][t] += matrixA[s][i] * matrixB[i][t];
		}
		t++;
	}
	//답 출려
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < c; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	
	
}
