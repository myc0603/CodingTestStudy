#include <bits/stdc++.h>
using namespace std;

int n, a[21][21];

int getMaxBlockValue(int board[21][21]) {
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mx = max(mx, board[i][j]);
        }
    }
    return mx;
}

void go_left(int v[21]) {
    int temp[21] = {};

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (v[i]) temp[idx++] = v[i];
    }

    int vidx = 0;
    for (int i = 0; i < idx; i++) {
        if (i + 1 < idx && temp[i] == temp[i+1]) {
            v[vidx++] = temp[i] * 2;
            i++;
        } else {
            v[vidx++] = temp[i];
        }
    }
    while (vidx < n) v[vidx++] = 0;
}

void transpose(int board[21][21]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(board[i][j], board[j][i]);
        }
    }
}

void go(int board[21][21], int direction) {
    if (direction & 2) transpose(board);

    for (int i = 0; i < n; i++) {

        if (direction & 1) reverse(board[i], board[i] + n);
        
        go_left(board[i]);
        
        if (direction & 1) reverse(board[i], board[i] + n);
    }
    
    if (direction & 2) transpose(board);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int ans = 0;
    int copy_board[21][21];
    for (int i = 0; i < (1 << 10); i++) {
        memcpy(copy_board, a, sizeof(a));

        int temp = i;
        while (temp) {
            int dir = temp & 3;
            go(copy_board, dir);
            temp >>= 2;
        }

        ans = max(getMaxBlockValue(copy_board), ans);
    }
    cout << ans;
}