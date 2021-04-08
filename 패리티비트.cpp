#include <iostream>
#include<cmath>;

using namespace std;

int main() {

	int num = 1;
	long long answer = num;
	int count = 0;

	while (num > 0){
		if ((num%2) == 1) {
			count++;
		}
		num = num / 2;

	}
	if ((count%2) == 1) {
		answer += pow(2,31);
	}
	cout << answer;


	return 0;
}
