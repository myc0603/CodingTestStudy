#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

struct State {
    string s;
    int cnt;
};

int n;
string from, to;
unordered_set<string> visited;

int main() {
    cin >> n >> from >> to;

    queue<State> q;
    q.push( {from, 0} );
    visited.insert(from);

    while (q.size()) {
        string cur = q.front().s;
        int cnt = q.front().cnt;
        q.pop();

        if (cur == to) {
            cout << cnt;
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int len = 1; len <= 3 && i + len <= n; ++len) {
                for (int rot = -3; rot <= 3; ++rot) {
                    if (rot == 0) continue;

                    string nxt = cur;
                    for (int j = 0; j < len; ++j) {
                        int pos = i + j;
                        int x = nxt[pos] - '0';
                        x = (x + rot + 10) % 10;
                        nxt[pos] = x + '0';
                    }

                    if (!visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push({nxt, cnt + 1});
                    }
                }
            }
        }
    }
}