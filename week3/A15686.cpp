#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> houses, chickens;
vector<int> chickenDis;
int ans = 1e7;

void printV(vector<pair<int, int>> v) {
    cout << "\nprint vector<pair>\n";
    for (auto p : v) {
        cout << p.first << ' ' << p.second << '\n';
    }
    cout << '\n';
}

int getDis(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int cityDis(vector<pair<int, int>> mChickens) {
    int dis = 0;
    int idx = 1; // for debugging
    for (auto house : houses) {
        int temp = n * 2; // 한 집의 치킨거리의 최댓값 2n - 2
        for (auto chicken : mChickens) {
            temp = min(temp, getDis(house, chicken));
        }
        cout << "  " << idx++ << "th house chicken dis: " << temp << '\n';
        dis += temp;
    }

    return dis;
}

void combi(vector<pair<int, int>> &to, int n, int idx) {
    if (to.size() == m) {
        // 치킨집 다 고름!!
        // 이 때 도시의 치킨 거리 구해봐야됨
        // 각 집에서의 치킨거리 구해야 되니까
        printV(to);
        ans = min(ans, cityDis(to));
        cout << "min of city distance: " << ans << '\n';
        return;
    }

    for (int i = idx; i < n; i++) {
        cout << " idx: " << idx << ", push i: " << i << '\n';
        to.push_back(chickens[i]);
        combi(to, n, i + 1);
        cout << " idx: " << idx << ", pop i: " << i << '\n';
        to.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            if (num == 1) {
                houses.push_back({i, j});
            }
            if (num == 2) {
                chickens.push_back({i, j});
            }
        }
    }

    // 이럴 필요없었음 그냥 combi()함수 잘못함
    // 각 집에서 치킨거리를 다 구한다. -> 벡터로? 최솟값 하나로?
    // 최솟값 하나로
    // for (auto house : houses) {
    //     int dis = n * 2; // 한 집의 치킨거리의 최댓값 2n - 2
    //     for (auto chicken : chickens) {
    //         dis = min(dis, getDis(house, chicken));
    //     }
    //     chickenDis.push_back(dis);
    // }

    // cout << "print houses" << '\n';
    // printV(houses);
    // cout << "print chickens" << '\n';
    // printV(chickens);    

    vector<pair<int, int>> mChickens;
    combi(mChickens, chickens.size(), 0);
    cout << ans << '\n';
}