#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, psumA[1002], psumB[1002];
vector<int> subSumA, subSumB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        psumA[i] = psumA[i-1] + x;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x; cin >> x;
        psumB[i] = psumB[i-1] + x;
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            subSumA.push_back(psumA[i+len] - psumA[i]);
        }
    }

    for (int len = 1; len <= m; ++len) {
        for (int i = 0; i + len <= m; ++i) {
            subSumB.push_back(psumB[i+len] - psumB[i]);
        }
    }

    sort(subSumA.begin(), subSumA.end());
    sort(subSumB.begin(), subSumB.end());

    long long cnt = 0;
    for (int x : subSumA) {
        int value = t - x;
        cnt += upper_bound(subSumB.begin(), subSumB.end(), value) - lower_bound(subSumB.begin(), subSumB.end(), value);
    }
    cout << cnt;
}