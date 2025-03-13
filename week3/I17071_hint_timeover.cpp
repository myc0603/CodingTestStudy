#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int visited[MAX+1], broVisited[MAX+1];

int main() {
    int n, k;
    cin >> n >> k;

    int broPos = k;
    int broSec = 0;
    while (broPos <= MAX) {
        broVisited[broPos] = broSec + 1;
        cout << "bro Position: " << broPos << ", sec: " << broVisited[broPos] << '\n';
        broSec++;
        broPos += broSec;
    }
    
    int sec = 0;
    queue<int> q;
    q.push(n);

    while (q.size()) {
        cout << "sec: " << sec << '\n';
        if (sec > broSec) break;

        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int cur = q.front(); q.pop();

            visited[cur] = sec + 1;

            if (visited[cur] == broVisited[cur]) {
                cout << sec << '\n';
                return 0;
            }
            
            for (int next : {cur + 1, cur - 1, cur * 2}) {
                if (next < 0 || next > MAX) continue;
                q.push(next);
            }
        }

        sec++;
    }
    cout << -1 << '\n';
}