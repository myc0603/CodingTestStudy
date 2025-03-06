#include <bits/stdc++.h>
using namespace std;

int n, attackCount[61][61][61];
vector<int> initialHp = {0, 0, 0};
vector<int> attackPower[] = {
    {9, 3, 1}, {9, 1, 3},
    {3, 9, 1}, {3, 1, 9},
    {1, 3, 9}, {1, 9, 3}
};

struct SCVs {
    int hp1, hp2, hp3;
};

int main() {
    cin >> n;
    SCVs scvs;
    cin >> scvs.hp1 >> scvs.hp2 >> scvs.hp3;

    queue<SCVs> q;
    q.push(scvs);
    attackCount[scvs.hp1][scvs.hp2][scvs.hp3] = 1;
    while (q.size()) {
        SCVs curHp = q.front(); q.pop();
        
        for (int i = 0; i < 6; i++) {
            SCVs newHp;
            newHp.hp1 = max(0, curHp.hp1 - attackPower[i][0]);
            newHp.hp2 = max(0, curHp.hp2 - attackPower[i][1]);
            newHp.hp3 = max(0, curHp.hp3 - attackPower[i][2]);
 
            if (!attackCount[newHp.hp1][newHp.hp2][newHp.hp3]) {
                attackCount[newHp.hp1][newHp.hp2][newHp.hp3] = attackCount[curHp.hp1][curHp.hp2][curHp.hp3] + 1;
                q.push(newHp);
            }
        }
    }
    cout << attackCount[0][0][0] - 1 << '\n';
}