#include <iostream>

using namespace std;
int main(void) {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    //첫번째 선분이 y축 평행
    if (x1 == x2) {
        if ((x1 <= x3 && x1 >= x4) || (x1 >= x3 && x1 <= x4)) {
            if ((y1 <= y3 && y2 >= y3) || (y1 >= y3 && y2 <= y3)) {
                if (x1 == x3 || x1 == x4 || y1 == y3 || y2 == y4)
                    cout << 2;
                else
                    cout << 1;
            }
        }
        else
            cout << 0;
    }
    //2번째 선분이 y축 평행
    else if (x3 == x4) {
        if ((x3 <= x1 && x3 >= x2) || (x3 >= x1 && x3 <= x2)) {
            if ((y3 <= y1 && y4 >= y1) || (y3 >= y1 && y4 <= y1)) {
                if (y2 == y3 || y2 == y4 || x1 == x3 || x2 == x3)
                    cout << 2;

                else {
                    cout << 1;
                }
            }
            else cout << 0;
        }
        else
            cout << 0;

    }
    else
        cout << 0;
    return 0;
}
