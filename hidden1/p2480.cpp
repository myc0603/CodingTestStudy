#include <iostream>
using namespace std;

// 주사위 세개
int main() {
    int dice[7] = {};
    int cnt = 1;
    int same;
    int maxNum = 0;
    for (int i = 0; i < 3; i++) {
        int num; cin >> num;
        maxNum = num > maxNum ? num : maxNum;
        if (dice[num]) {
            cnt++;
            same = num;
        }
        dice[num]++;
    }

    if (cnt == 3) {
        cout << 10000 + same * 1000;
    } else if (cnt == 2) {
        cout << 1000 + same * 100;
    } else {
        cout << maxNum * 100;
    }
}