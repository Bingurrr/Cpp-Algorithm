#include <iostream>

using namespace std;

int main(void) {
    int n; cin >> n;
    int x[n], y[n];
    int answer = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];
    for (int i = 0; i < n; i++)
        answer += x[i] * y[i + 1] - y[i] * x[i + 1];

    num = (answer > 0) ? 1 : -1;
    answer = abs(answer);

    cout << answer << " " << num;
    return 0;

}
