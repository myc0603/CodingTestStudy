#include <bits/stdc++.h>
using namespace std;

int n, a[20][20], team_size, diff;
vector<int> t1, t2;

int getDiff() {
    int stat1 = 0; int stat2 = 0;
    for (int i = 0; i < team_size; i++) {
        for (int j = i + 1; j < team_size; j++) {
            stat1 += a[t1[i]][t1[j]] + a[t1[j]][t1[i]];
            stat2 += a[t2[i]][t2[j]] + a[t2[j]][t2[i]];
        }
    }
    return abs(stat1 - stat2);
}

void combi(int idx) {
    if (t1.size() == team_size) {
        // build t2
        t2.clear();
        for (int i = 0; i < n; i++) t2.push_back(i);
        for (int i = team_size - 1; i >= 0; i--) t2.erase(t2.begin() + t1[i]);

        diff = min(diff, getDiff());
    }

    for (int i = idx; i < n; i++) {
        t1.push_back(i);
        combi(i + 1);
        t1.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    team_size = n / 2;
    diff = 100 * n * n;
    t1.push_back(0); // 0이 있는 팀을 t1으로 정할 수 있다.
    combi(1);
    cout << diff;
}
