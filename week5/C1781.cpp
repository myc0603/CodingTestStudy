#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> problems;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int deadline, cnt;
        cin >> deadline >> cnt;
        problems.push_back({deadline, cnt});
    }

    sort(problems.begin(), problems.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto problem : problems) {
        pq.push(problem.second);
        if (pq.size() > problem.first) pq.pop();
    }

    long long total = 0;
    while (pq.size()) {
        total += pq.top(); pq.pop();
    }
    cout << total;
}