#include <iostream>
using namespace std;
//�ֽ� �Ⱓ�� �ֽ� ������ �Է� �޴´�.
//��� �ֽ��� ��� �Ⱦƾ� �̵��� ���� ������
//�ֽ��� �Ϸ翡 1���ް� ���� ���Ѵ�. �Ĵ°Ϳ��� ������ ����.
void findmax(int i, int* arr);
int money;
int day;
int main() {
	
	cin >> day;
	int* price = new int[day];
	for (int i = 0; i < day; i++) {
		cin >> price[i];
	}
	findmax(0,price);

	cout << money;

}
void findmax(int i, int* arr) {
	int max = 0;
	int maxday = 0;
	for (int j = i; j < day; j++) {
		if (arr[j] > max) {
			max = arr[j];
			maxday = j;
		}
	}
	for (int j = i; j < maxday; j++) {
		money += max - arr[j];
	}
	i = maxday+1;
	if (i == day) return;
	findmax(i, arr);
}