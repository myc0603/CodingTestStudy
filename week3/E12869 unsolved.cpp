#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
void func(vector<int> scvs, int cnt);
void attack(vector<int> scvs, int cnt) {
    cnt++;
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

    if (scvs.empty()) {
        ans.push_back(cnt);
        return;
    }

    func(scvs, cnt);
}

void func(vector<int> scvs, int cnt) {
    sort(scvs.begin(), scvs.end());
    do {
        attack(scvs, cnt);
    } while (next_permutation(scvs.begin(), scvs.end()));
}

// hp 높은거부터 때린다고 좋은거 아님 -> 문제 힌트
int main() {
    int n; cin >> n;
    vector<int> scvs;
    for (int i = 0; i < n; i++) {
        int hp; cin >> hp;
        scvs.push_back(hp);
    }

    func(scvs, 0);

    // for (int num : ans) {
    //     cout << num << ' ';
    // }
    // cout << '\n';
    
    cout << *min_element(ans.begin(), ans.end()) << '\n';
}