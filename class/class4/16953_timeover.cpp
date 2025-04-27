#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int a, b, cnt;
unordered_set<int> visited;

int main() {
    cin >> a >> b;

    queue<int> q;
    q.push(a);
    visited.insert(a);

    while (q.size()) {
        int qSize = q.size();

        if (q.front() > b) {
            cout << -1;
            return 0;
        }

        cnt++;

        for (int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();

            if (cur == b) {
                cout << cnt;
                return 0;
            }

            for (int next : {cur * 2, cur * 10 + 1}) {
                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
    }
}