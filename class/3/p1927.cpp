#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        int x; cin >> x;
        if (x == 0) {
            if (pq.empty()) ans += to_string(0) + '\n';
            else {
                ans += to_string(pq.top()) + '\n';
                pq.pop();
            }
        } else pq.push(x);
    }
    cout << ans;
}