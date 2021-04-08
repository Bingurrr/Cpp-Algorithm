#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int num;
    cin >> num;
    int a = sqrt(num);
    if(num%2==0) {cout << 0; return 0;}
    for (int i = 3; i < a+1; i+=2) {
        if (num % i == 0) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
