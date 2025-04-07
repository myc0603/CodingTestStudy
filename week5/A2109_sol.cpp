#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> suggests;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int pay, day;
        cin >> pay >> day;
        suggests.push_back({day, pay});
    }

    /**
     * day 오름차순으로 정렬, pay는 순서 상관없음
     * 어차피 pq에 넣어봐서 해당 강연의 day가 pq의 사이즈보다 작으면 pq.pop()
    */
    sort(suggests.begin(), suggests.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto suggest : suggests) {
        pq.push(suggest.second);
        cout << "push -> day: " << suggest.first << ", pay: " << suggest.second << '\n';
        if (suggest.first < pq.size()) { // suggest.first: 현재 루프를 돌면서 current의 역할 current_day
            cout << "  pop: " << pq.top() << '\n';
            pq.pop();
        }
    }

    int income = 0;
    while (pq.size()) {
        income += pq.top(); pq.pop();
    }
    cout << income;
}