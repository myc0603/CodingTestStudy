#include <iostream>
using namespace std;
int cnt[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    string ans;
    for (int i = 1; i <= 10000; i++) {
        int count = cnt[i];
        while (count--) cout << i << '\n';
    }
}