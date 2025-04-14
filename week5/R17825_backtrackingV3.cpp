#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int START = 0, END = 32;
int a[10], positions_of_horse[4], ans;

struct Node {
    int score;
    vector<int> next_nodes; // 0-based index
};
Node board[33];

void buildBoard() {
    for (int i = 0; i <= 20; i++) {
        board[i].score = 2 * i;
        if (i % 5 == 0) continue;
        for (int j = 1; j <= 5 && i + j <= 20; j++) {
            board[i].next_nodes.push_back(i + j);
        }
    }
    for (int i = 16; i <= 20; i++) {
        board[i].next_nodes.push_back(END);
    }

    board[21].score = 13;
    board[22].score = 16;
    board[23].score = 19;
    board[24].score = 22;
    board[25].score = 24;
    board[26].score = 28;
    board[27].score = 27;
    board[28].score = 26;
    board[29].score = 25;
    board[30].score = 30;
    board[31].score = 35;
    board[END].score = 0;

    board[START].next_nodes = {1, 2, 3, 4, 5};
    board[5].next_nodes = {21, 22, 23, 29, 30};
    board[10].next_nodes = {24, 25, 29, 30, 31};
    board[15].next_nodes = {26, 27, 28, 29, 30};
    board[21].next_nodes = {22, 23, 29, 30, 31};
    board[22].next_nodes = {23, 29, 30, 31, 20};
    board[23].next_nodes = {29, 30, 31, 20, END};
    board[24].next_nodes = {25, 29, 30, 31, 20};
    board[25].next_nodes = {29, 30, 31, 20, END};
    board[26].next_nodes = {27, 28, 29, 30, 31};
    board[27].next_nodes = {28, 29, 30, 31, 20};
    board[28].next_nodes = {29, 30, 31, 20, END};
    board[29].next_nodes = {30, 31, 20, END};
    board[30].next_nodes = {31, 20, END};
    board[31].next_nodes = {20, END};
}

bool can_move(int cur_horse, int next_position) {
    if (next_position != END) {
        for (int i = 0; i < 4; i++) {
            if (i == cur_horse) continue;
            if (positions_of_horse[i] == next_position) return false;
        }
    }
    return true;
}

void dfs(int turn, int score) {
    if (turn == 10) {
        ans = max(score, ans);
        return;
    }

    vector<pair<int, int>> horses;
    for (int horse = 0; horse < 4; horse++) {
        int cur_position = positions_of_horse[horse];
        if (cur_position == END) continue;
    
        Node &cur_node = board[cur_position];
        int move_cnt = a[turn];
        int next_position = move_cnt >= cur_node.next_nodes.size() ? END : cur_node.next_nodes[move_cnt];
        if (!can_move(horse, next_position)) continue;

        horses.push_back( { board[next_position].score, horse } );
    }

    // greedy한 방법이지만 이 문제에서 통하지 않음
    sort(horses.rbegin(), horses.rend());
    for (auto h : horses) {
        int horse = h.second;
        int cur_position = positions_of_horse[horse];
        int next_position = a[turn] >= board[cur_position].next_nodes.size() ? END : board[cur_position].next_nodes[a[turn]];

        positions_of_horse[horse] = next_position;
        dfs(turn + 1, score + board[next_position].score);
        positions_of_horse[horse] = cur_position;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        a[i]--;
    }

    buildBoard();
    dfs(0, 0);

    cout << ans;
}