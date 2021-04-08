#include <iostream>
using namespace std;
int main(void) {
    int k; cin >> k;
    int count = 1;
    int *arr = new int[k+1];
    int num = 0;
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;
    for(int i = 5; i<=k; i++){
        int max = arr[i-1];
        int min = arr[i-1]*2;
        for(int j = 1; j < i ; j++){
            num =arr[j]*2;
            if(num <= min && num > max){
                    min = num;
                }
            num = arr[j]*3;
            if(num <= min && num > max){
                    min = num;
                }
            num = arr[j]*5;
            if(num <= min && num > max){
                min = num;
            }
        }
        arr[i] = min;
    }
    cout << arr[k-1];


    return 0;
}
