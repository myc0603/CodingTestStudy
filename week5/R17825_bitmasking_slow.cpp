#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int START = 0, END = 32;
int a[10], positions_of_horse[4];

struct Node {
    int score;
    vector<int> next_nodes; // 0-based index
    unordered_set<int> on_horses;
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

    for (int i = 0; i < 4; i++) board[START].on_horses.insert(i);
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        a[i]--;
    }

    buildBoard();

    int ans = 0;
    for (int i = 0; i < (1 << 20); i++) {
        
        int score = 0;
        int horse_order = i;
        for (int j = 0; j < 10; j++) {
            
            int cur_horse = horse_order & 3;
            int cur_position = positions_of_horse[cur_horse];
            if (cur_position == END) {
                score = 0;
                break;
            }

            Node &cur_node = board[cur_position];

            int move_cnt = a[j];
            int next_position = move_cnt >= cur_node.next_nodes.size() ? END : cur_node.next_nodes[move_cnt];
            Node &next_node = board[next_position];
            

            if (next_position != END && board[next_position].on_horses.size()) {
                score = 0;
                break;
            }

            cur_node.on_horses.erase(cur_horse);
            next_node.on_horses.insert(cur_horse);
            positions_of_horse[cur_horse] = next_position;
            score += next_node.score;

            horse_order >>= 2;
        }
        ans = max(score, ans);

        fill(positions_of_horse, positions_of_horse + 4, 0);
        for (int i = 0; i < 4; i++) board[START].on_horses.insert(i);
        for (int i = 1; i <= END; i++) {
            board[i].on_horses.clear();
        }
    }

    cout << ans;
}