#include <bits/stdc++.h>
using namespace std;

int n, attackCount[61][61][61];
vector<int> initialHp = {0, 0, 0};
vector<int> attackPower[] = {
    {9, 3, 1}, {9, 1, 3},
    {3, 9, 1}, {3, 1, 9},
    {1, 3, 9}, {1, 9, 3}
};

bool allDie(vector<int> scvsHp) {
    return scvsHp[0] == 0 && scvsHp[1] == 0 && scvsHp[2] == 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> initialHp[i];
    }

    queue<vector<int>> q;
    q.push(initialHp);
    attackCount[initialHp[0]][initialHp[1]][initialHp[2]] = 1;
    while (q.size()) {
        vector<int> curHp = q.front(); q.pop();
        // printf("curHp: %d, %d, %d attackCount: %d\n", curHp[0], curHp[1], curHp[2], attackCount[curHp[0]][curHp[1]][curHp[2]]);
        
        for (int i = 0; i < 6; i++) {
            vector<int> newHp;
            for (int j = 0; j < 3; j++) {
                int hp = curHp[j] - attackPower[i][j];
                hp = hp < 0 ? 0 : hp;
                newHp.push_back(hp);
            }
            if (allDie(curHp)) {
                // cout << "find" << '\n';
                cout << attackCount[0][0][0] - 1 << '\n';
                return 0;
            }
            // printf("  newHp: %d, %d, %d attackCount: %d\n", newHp[0], newHp[1], newHp[2], attackCount[newHp[0]][newHp[1]][newHp[2]]);
            if (!attackCount[newHp[0]][newHp[1]][newHp[2]]) {
                // printf("  %d,%d,%d -> %d,%d,%d\n", curHp[0], curHp[1], curHp[2], newHp[0], newHp[1], newHp[2]);
                attackCount[newHp[0]][newHp[1]][newHp[2]] = attackCount[curHp[0]][curHp[1]][curHp[2]] + 1;
                q.push(newHp);
            }
        }
    }
}