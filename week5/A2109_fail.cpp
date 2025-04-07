#include <bits/stdc++.h>
using namespace std;

int n, income;
vector<pair<int, int>> suggests;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int price, day;
        cin >> price >> day;
        suggests.push_back({price, day});
    }

    sort(suggests.begin(), suggests.end(), cmp);
    
    int day = 1;
    for (auto suggest : suggests) {
        cout << "day: " << day << ", suggested price: " << suggest.first << ", day: " << suggest.second;
        if (day > suggest.second) {
            cout << " -> X\n";
            continue;
        }
        cout << " -> O\n";
        income += suggest.first;
        day++;
    }
    cout << income;
}