#include <bits/stdc++.h>
using namespace std;

int ans = 30;
void func(vector<int> &scvs, int cnt);

void printV(vector<int> v) {
    for (int num : v) {
        cout << num << ' ';
    }
    cout << '\n';
}

void attack(vector<int> scvs, int cnt) {
    cnt++;
    if (cnt >= ans) return;
    scvs[0] -= 9;
    if (scvs.size() >= 2) {
        scvs[1] -= 3;
    }
    if (scvs.size() == 3) {
        scvs[2] -= 1;
    }

    sort(scvs.begin(), scvs.end(), greater<>());
    while (scvs.size() && scvs[scvs.size()-1] <= 0) {
        scvs.pop_back();
    }

    for (auto it = scvs.begin(); scvs.size() && it != scvs.end(); it++) {
        while (*it <= 0) {
            scvs.erase(it);
        }
    }

    // printV(scvs);

    if (scvs.empty()) {
        ans = min(ans, cnt);
        return;
    }
    // cout << "after attacked\n";
    // printV(scvs);
    // cout << '\n';


    func(scvs, cnt);
}

void func(vector<int> &scvs, int cnt) {
    // sort(scvs.begin(), scvs.end()); // -> 얘 때문에 오래 걸림...? 해봤자 2번 스왑 아닌가..
    // 얘 때문 아닌거 같음 그냥 정렬하고 순열 돌리면 돌리는 횟수가 많아져서 그런 거 같음
    do {
        // cout << "before attacked\n";
        // printV(scvs);
        attack(scvs, cnt);
    } while (next_permutation(scvs.begin(), scvs.end()));
}

int main() {
    int n; cin >> n;
    vector<int> scvs;
    for (int i = 0; i < n; i++) {
        int hp; cin >> hp;
        scvs.push_back(hp);
    }

    func(scvs, 0);    
    cout << ans << '\n';
}