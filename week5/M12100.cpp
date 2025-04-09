#include <bits/stdc++.h>
using namespace std;

int n;

int getMaxBlockValue(const vector<vector<int>> &board) {
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mx = max(mx, board[i][j]);
        }
    }
    return mx;
}

vector<int> go_left(vector<int> v) {
    vector<int> temp, result;
    for (int num : v) {
        if (num) temp.push_back(num);
    }
    if (temp.empty()) return vector<int>(n);

    int prev = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (prev == temp[i]) {
            result.push_back(2 * prev);
            prev = 0;
        } else {
            if (prev) result.push_back(prev);
            prev = temp[i];
        }

    }
    if (prev) result.push_back(prev);

    while (result.size() < n) result.push_back(0);

    return result;
}

void transpose(vector<vector<int>> &board) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(board[i][j], board[j][i]);
        }
    }
}

void go(vector<vector<int>> &board, int direction) {
    if (direction & 2) transpose(board);

    for (auto &line : board) {

        if (direction & 1) reverse(line.begin(), line.end());
        
        line = go_left(line);
        
        if (direction & 1) reverse(line.begin(), line.end());
    }
    
    if (direction & 2) transpose(board);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        a.push_back(v);
    }

    int ans = 0;
    for (int i = 0; i < (1 << 10); i++) {
        vector<vector<int>> copy_board = a;

        int temp = i;
        while (temp) {
            go(copy_board, temp);
            temp >>= 2;
        }

        ans = max(getMaxBlockValue(copy_board), ans);
    }
    cout << ans;
}