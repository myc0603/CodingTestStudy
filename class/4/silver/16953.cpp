#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int a, b, cnt;
unordered_map<int, int> visited;

int main() {
    cin >> a >> b;

    queue<int> q;
    q.push(b);
    visited[b] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        vector<int> v;
        if (cur % 2 == 0) v.push_back(cur / 2);
        if (cur % 10 == 1 && cur > 10) v.push_back((cur - 1) / 10);
        for (int next : v) {
            if (next == a) {
                cout << visited[cur] + 1;
                return 0;
            }
            if (next < a) continue;
            if (visited.find(next) == visited.end()) {
                q.push(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }
    cout << -1;
}