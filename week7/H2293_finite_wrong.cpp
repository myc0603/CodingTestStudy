#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> coins(n);
    for (auto &c : coins) cin >> c.first >> c.second; // value, number

    vector<long long> dp(k + 1);
    vector<int> cnt(k + 1);
    dp[0] = 1;
    for (auto c : coins) {
        for (int i = c.first; i <= k; i++) {
            int prev = i - c.first;
            // c를 사용해서 i-c.first원을 만드는 경우를 생각했는데도 가능한 경우의 수가 없다는 뜻
            // 이걸 continue;로 넘겨야 cnt가 업데이트 되지 않는다.
            // 원래는 dp[i-c.first]를 더하기만 하는 로직만 있어서 0인 dp[i-c.first]값을 더할 필요 없었기 때문에 신경 안 써도 됐었음
            if (dp[prev] == 0) continue;

            cnt[i] = cnt[prev] + 1;
            if (cnt[i] > c.second) continue; // break; -> cnt가 항상 같거나 증가하지는 않기 때문에 그 뒤의 경우도 확인해봐야 됨
            dp[i] += dp[prev]; // -> c 사용
        }
        // cnt.clear(); // -> size가 0이 됨
        fill(cnt.begin(), cnt.end(), 0);
    }

    cout << dp[k];
}

/**
 * 잘못된 풀이
 * 3원코인이 무한개 있고, 6원코인이 최대 2개 사용할 수 있을 때, 
 * 3원짜리에 처리한 후에 6원 코인에 대해서 처리할 때 dp[12] = 3이고 이때 cnt[12] = 2이다.
 * (12원을 만들 수 있는 경우의 수가 3가지이고 이때 사용되는 6원짜리 동전의 개수는 최대 2.)
 * (각각의 경우의 수는 3,3,3,3 / 6,3,3 / 6,6)
 * 그리고나서 dp[18]을 구할 때 cnt[12] = 2라서 여따가 1을 더하면 6원 코인의 최대 개수 2개를 넘게 된다.
 * -> 원래 코드대로라면 continue로 스킵하고 다음으로 넘어간다.
 * 하지만 dp[12] = 3 중의 2가지 경우는 6을 1가지 이하로 쓰는거라서 2에다가 원래 dp[18]값인 1을 더해서
 * dp[18]이 3이 되어야 한다.
 * 
 * => 다른 방식의 풀이 필요
 */