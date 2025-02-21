#include <bits/stdc++.h>
using namespace std;

int main() {
    int fare[4];
    for (int i = 1; i <= 3; i++) {
        cin >> fare[i];
    }

    // 1 ~ 100 -> [1,99]
    int cnt[100] = {};
    for (int i = 0; i < 3; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        for (int t = t1; t < t2; t++) {
            cnt[t]++;
        }
    }

    int tot = 0;
    for (int i = 1; i <= 99; i++) {
        tot += cnt[i] * fare[cnt[i]];
    }
    cout << tot <<  '\n';
}