#include <iostream>
using namespace std;

int main() {
	//이진수에서 1의개수 해밍무게
	//0 또는 1의 값이 서로 다른 자리수의 개수를 해밍 거리
	unsigned int n1, n2;
	cin >> n1 >> n2;
	int h1, h2, hcode;
	int bit;
	h1 = h2 = hcode = 0;

	bit = n1 ^ n2;


	while (n1 > 0) {
		h1 += n1 % 2;
		n1 /= 2;
	}
	while (n2 > 0) {
		h2 += n2 % 2;
		n2 /= 2;
	}
	while (bit > 0) {
		hcode += bit % 2;
		bit /= 2;
	}


	cout << h1 << " " << h2 << " "<< hcode;


}