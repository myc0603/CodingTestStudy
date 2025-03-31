#include <bits/stdc++.h>
using namespace std;

int n, m, a[4][4];

int sum(int cases) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;
            if (cases & (1 << idx)) { // 1
                result += num;
                num = 0;
            } else { // 0
                num = 10 * num + a[i][j];
            }
        }
        result += num;
    }
    
    for (int j = 0; j < m; j++) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            int idx = i * m + j;
            if (cases & (1 << idx)) { // 1
                num = 10 * num + a[i][j];
            } else { // 0
                result += num;
                num = 0;
            }
        }
        result += num;
    }

    return result;
}

int sumWithoutBitMasking() {
    // cout << "without bitmasking\n";
    // cout << " calc sum1\n";
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < m; j++) {
            num = 10 * num + a[i][j];
        }
        sum1 += num;
        // cout << "  num: " << num << '\n';
    }

    // cout << "======================\n";
    // cout << " calc sum2\n";
    int sum2 = 0;
    for (int j = 0; j < m; j++) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            num = 10 * num + a[i][j];
        }
        sum2 += num;
        // cout << "  num: " << num << '\n';
    }

    // cout << "sum1: " << sum1 << ", sum2: " << sum2 << '\n';
    return max(sum1, sum2);
}

int main() {
    bool bitmasking = false;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            if (i == 0 && s[j] == '0') bitmasking = true;
        }
        if (s[0] == '0') bitmasking = true;
    }

    if (!bitmasking) {
        cout << sumWithoutBitMasking() << '\n';
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < (1 << (n*m)); i++) {
        ans = max(sum(i), ans);
    }
    cout << ans << '\n';
}