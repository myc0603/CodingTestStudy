#include <iostream>
#include <cstring>
using namespace std;

int s, m, pos[105], dp[105][2][35];

int go(int sec, int curPos, int moveCount) {
    if (moveCount > m) return -1e9;
    if (sec == s) return 0;
    
    int &result = dp[sec][curPos][moveCount];
    if (result != -1) return result;

    int moveResult = go(sec + 1, curPos ^ 1, moveCount + 1);
    int stayResult = go(sec + 1, curPos, moveCount);
    result = max(moveResult, stayResult) + (curPos == pos[sec]);
    return result;
}

int main() {
    cin >> s >> m;
    for (int i = 0; i < s; i++) {
        cin >> pos[i];
        pos[i]--;
    }

    memset(dp, -1, sizeof(dp));
    int moveStart = go(0, 1, 1);
    int stayStart = go(0, 0, 0);
    cout << max(moveStart, stayStart);
}