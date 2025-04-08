#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({end, start});
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int start = v[0].second;
    int end = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i].second >= end) {
            cnt++;
            end = v[i].first;
        }
    }

    cout << cnt;
}