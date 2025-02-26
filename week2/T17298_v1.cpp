#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n; // 100만...
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans[n];
    // memset(ans, -1, sizeof(ans)); // 0, -1만 가능
    fill(ans, ans + n, -1);

    // 아마 안될듯 시간 복잡도 너무 커짐
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                ans[i] = a[j];
                break;
            }
        }
    }

    string s;
    for (int num : ans) {
        s += to_string(num) + ' ';
    }
    cout << s;
}