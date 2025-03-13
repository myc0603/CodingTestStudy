#include <bits/stdc++.h>
using namespace std;

int k;
char ops[10];
vector<string> ans;
bool used[10];

bool check(char x, char y, char op) {
    if (op == '>' && x > y) return true;
    if (op == '<' && x < y) return true;
    return false;
}

void makeNum(int idx, string makingNum) {
    if (idx == k + 1) {
        ans.push_back(makingNum);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (used[i]) continue;
        if (idx == 0 || check(makingNum[idx-1], i + '0', ops[idx-1])) {
            used[i] = true;
            makeNum(idx + 1, makingNum + to_string(i));
            used[i] = false;
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ops[i];
    }
    makeNum(0, "");
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << '\n';
    cout << ans[0] << '\n';
}