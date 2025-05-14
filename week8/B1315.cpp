#include <iostream>
#include <cstring>
using namespace std;

int N, STR[52], INT[52], PNT[52], points[1002][1002], clearCnts[1002][1002], dp[1002][1002];

int dfs(int curStr, int curInt) {
    int &result = dp[curStr][curInt];
    if (result != -1) return result;

    int getPoints = points[curStr][curInt] - (curStr + curInt - 2);
    result = clearCnts[curStr][curInt];
    for (int p = 0; p <= getPoints; ++p) {
        int nextStr = curStr + p;
        int nextInt = curInt + getPoints - p;
        if (nextStr >= 1000 || nextInt >= 1000) return result = N;
        if (clearCnts[nextStr][nextInt] > clearCnts[curStr][curInt]) {
            result = max(result, dfs(nextStr, nextInt));
        }
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> STR[i] >> INT[i] >> PNT[i];

    for (int q = 0; q < N; ++q) {
        for (int s = 0; s <= 1000; ++s) {
            for (int i = s < STR[q] ? INT[q] : 0; i <= 1000; ++i) {
                points[s][i] += PNT[q];
                ++clearCnts[s][i];    
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1);
}