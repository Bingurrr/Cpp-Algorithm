#include <iostream>
using namespace std;

int main() {
	//���������� 1�ǰ��� �عֹ���
	//0 �Ǵ� 1�� ���� ���� �ٸ� �ڸ����� ������ �ع� �Ÿ�
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