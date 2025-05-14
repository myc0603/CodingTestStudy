#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, STR[52], INT[52], PNT[52], dp[1002][1002], visited[52];

// 전처리 안 해서 걸린 시간 증가, 사용 메모리 감소
int dfs(int curStr, int curInt) {
    int &result = dp[curStr][curInt];
    if (result != -1) return result;

    vector<int> complete;
    result = 0;
    int point = 0;
    for (int q = 0; q < N; ++q) {
        if (curStr >= STR[q] || curInt >= INT[q]) {
            ++result;
            if (!visited[q]) {
                point += PNT[q];
                visited[q] = 1;
                complete.push_back(q);
            }
        }
    }

    for (int p = 0; p <= point; ++p) {
        int nextStr = min(1000, curStr + p);
        int nextInt = min(1000, curInt + point - p);
        result = max(result, dfs(nextStr, nextInt));
    }
    for (int q : complete) visited[q] = 0;
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> STR[i] >> INT[i] >> PNT[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1);
}