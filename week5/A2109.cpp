#include <bits/stdc++.h>
using namespace std;

int n, income, visited[10001];
vector<pair<int, int>> suggests;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int price, day;
        cin >> price >> day;
        suggests.push_back({price, day});
    }

    sort(suggests.begin(), suggests.end(), cmp);

    for (auto suggest : suggests) {
        int day = suggest.second;
        while (visited[day]) day--;
        if (day <= 0) continue;
        visited[day] = 1;
        income += suggest.first;
    }

    cout << income;
}