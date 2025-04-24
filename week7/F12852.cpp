#include<bits/stdc++.h>
using namespace std;

int dp[1000003], nextNumber[1000003];

int sol(int n) {
    if (n == 1) return 0;

    int &result = dp[n];
    if (result != -1) return result;

    result = sol(n - 1) + 1;
    nextNumber[n] = n - 1;
    if (n % 2 == 0) {
        int t = sol(n / 2) + 1;
        if (t < result) {
            result = t;
            nextNumber[n] = n / 2;
        }
    }
    if (n % 3 == 0) {
        int t = sol(n / 3) + 1;
        if (t < result) {
            result = t;
            nextNumber[n] = n / 3;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x; cin >> x;

    memset(dp, -1, sizeof(dp));
    memset(nextNumber, -1, sizeof(nextNumber));

    int cnt = sol(x);
    cout << cnt << '\n';

    vector<int> path;
    int cur = x;
    while (cur != -1) {
        path.push_back(cur);
        cur = nextNumber[cur];
    }

    for (int num : path) cout << num << ' ';
}