#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[200001];

void printV(vector<int> & v) {
    for (int num : v) {
        cout << num << ' ';
    }
}

// void dfs(int cur, vector<int> &path) {
//     cout << "call dfs(), cur: " << cur << '\n';
//     visited[cur] = 1;

//     if (cur == k) {
//         printV(path);
//         return;
//     }

//     for (int next : {cur + 1, cur - 1, cur * 2}) {
//         if (next < 0 || next > 200000) continue;
//         if (!visited[next]) {
//             path.push_back(next);
//             dfs(next, path);
//             path.pop_back();
//         }
//     }
// }

int main() {
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    stack<pair<int, int>> path;
    while (q.size()) {
        int cur = q.front(); q.pop();

        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (next < 0 || next > 200000) continue;
            if (!visited[next]) {
                // cout << cur << " -> " << next << '\n';
                q.push(next);
                visited[next] = visited[cur] + 1;
                path.push({cur, next});
                if (next == k) break;
            }
        }
        if (visited[k] != 0) break;
    }

    vector<int> ans;
    ans.push_back(k);
    int cur = k;
    while (path.size()) {
        pair<int, int> p = path.top(); path.pop();
        if (p.second == cur) {
            ans.push_back(p.first);
            cur = p.first;
        }
    }
    string output = to_string(visited[k]-1) + '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        output += to_string(ans[i]) + ' ';
    }
    cout << output;
}