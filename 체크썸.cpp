#include <iostream>
#include <bitset>
using namespace std;

int main() {
    //송/수신 데이터의 크기는 32비트이며, 데이터를 8-비트 단위로 나눠서 체크썸을 계산
    //32비트 중에서 실제데이터는 가장 높은자리 3-바이트이고 체크썸은 가장 낮은자리를 차지하는 한 바이트
    //체크썸을 계산 할 떄 먼저 실제 데이터가 수록된 3바이트를 바이트 단위로 나고, 그 바이트값을 모두 더한다.
    //더한 값이 256보다 크거나 같은 경우, 그값이 256보다 잘아질 떄까지 256을 뺀다.
    //최종적으로 4단계에서 계산한 값을 255에서 뺀 값을 체크썸으로 정한다
    unsigned int n;
    cin >> n;
    int b1, b2, b3, b4;
    int bit = 256;
    b1 = n / (256*256*256);
    b2 = (n - b1 * 256 * 256 * 256) / (256 * 256);
    b3 = (n - b1 * 256 * 256 * 256 - b2 * 256 * 256) / 256;
    b4 = n - b1 * 256 * 256 * 256 - b2 * 256 * 256 - b3 * 256;
    //cout << b1 << " " << b2 << " " << b3;

    int checksum = b1 + b2 + b3;
    while(checksum >= 256){
        checksum -= 256;
    }
    checksum = 255 - checksum;
    int answer = (checksum != b4 ) ? 0 : 1;

    cout << answer;


}
