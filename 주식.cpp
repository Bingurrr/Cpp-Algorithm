#include <iostream>
using namespace std;
//주식 기간과 주식 가격을 입력 받는다.
//어떻게 주식을 사고 팔아야 이득을 볼수 있을까
//주식은 하루에 1개받게 사지 못한다. 파는것에는 제한이 없다.
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