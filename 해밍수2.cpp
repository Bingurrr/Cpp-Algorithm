//while로 돌리기
//엄청난 반복으로 해결하기?!?? 낭비되는게 너무 많다.

int main(void) {
    int k; cin >> k;
    int count = 1;
    int i;
    for (i = 2; count != k; i++) {
        int num = i;
        while (num % 2 == 0) {
            num = num / 2;
        }
        while (num % 3 == 0) {
            num = num / 3;
        }
        while (num % 5 == 0) {
            num = num / 5;
        }
        if (num == 1) {
            count++;
        }

    }
    cout << i - 1;
    return 0;
}
