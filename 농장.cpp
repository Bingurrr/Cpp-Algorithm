#include <iostream>

using namespace std;

int main(void) {
    int a, b, n, w, x, y;
    cin >> a >> b >> n >> w;
    if (a == b) {
        cout << -1;
        return 0;
    }
    else if ((w - n * b) * (a - b) <= 0) {
        cout << -1;
        x = -1;
        y = -1;
        return 0;
    }
    else {
        x = (w - n * b) / (a - b);
        if (x <= 0) {
            cout << -1;
            return 0;
        }
    }
    y = n - x;
    cout << x << ' ' << y << endl;
    return 0;
}
