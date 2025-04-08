#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> jewels;
vector<int> bags;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int mass, value;
        cin >> mass >> value;
        jewels.push_back({mass, value});
    }
    sort(jewels.begin(), jewels.end());

    for (int i = 0; i < k; i++) {
        int capacity;
        cin >> capacity;
        bags.push_back(capacity);
    }
    sort(bags.begin(), bags.end());

    long long ans = 0;

    int j = 0;
    priority_queue<int> pq;
    for (int capacity : bags) {
        while (j < n && capacity >= jewels[j].first) {
            pq.push(jewels[j].second);
            j++;
        }
        if (pq.size()) {
            ans += pq.top(); pq.pop();
        }
    }

    cout << ans;
}