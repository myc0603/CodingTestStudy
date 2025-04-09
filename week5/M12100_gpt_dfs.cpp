#include <bits/stdc++.h>
using namespace std;

int n, max_val, a[21][21];

int getMaxBlockValue(int board[21][21]) {
    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mx = max(mx, board[i][j]);
    return mx;
}

void go_left(int row[21]) {
    int temp[21] = {0}, result[21] = {0};
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (row[i] != 0) temp[idx++] = row[i];
    }

    int ri = 0;
    for (int i = 0; i < idx; i++) {
        if (i + 1 < idx && temp[i] == temp[i + 1]) {
            result[ri++] = temp[i] * 2;
            i++;
        } else {
            result[ri++] = temp[i];
        }
    }

    for (int i = 0; i < n; i++) row[i] = result[i];
}

void transpose(int board[21][21]) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(board[i][j], board[j][i]);
}

void reverse_row(int row[21]) {
    for (int i = 0; i < n / 2; i++)
        swap(row[i], row[n - 1 - i]);
}

void move_board(int board[21][21], int direction) {
    if (direction & 2) transpose(board);

    for (int i = 0; i < n; i++) {
        if (direction & 1) reverse_row(board[i]);
        go_left(board[i]);
        if (direction & 1) reverse_row(board[i]);
    }

    if (direction & 2) transpose(board);
}

bool is_same_board(int b1[21][21], int b2[21][21]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (b1[i][j] != b2[i][j]) return false;
    return true;
}

void dfs(int board[21][21], int depth) {
    if (depth == 5) {
        max_val = max(max_val, getMaxBlockValue(board));
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int next[21][21];
        memcpy(next, board, sizeof(next));
        move_board(next, dir);
        if (!is_same_board(board, next)) {
            dfs(next, depth + 1);
        } else max_val = max(max_val, getMaxBlockValue(board));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    dfs(a, 0);
    cout << max_val;
    return 0;
}
