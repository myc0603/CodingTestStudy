#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_ans = -1e9, min_ans = 1e9;
int n, a[105];
vector<int> operateors; // +, -, *, / 개수

int calculate(int op, int x1, int x2) {
    if (op == 0) return x1 + x2;
    else if (op == 1) return x1 - x2;
    else if (op == 2) return x1 * x2;
    else if (op == 3) return x1 / x2;
    else return 0;
}

void dfs(int index, int result) {
    if (index == n) {
        max_ans = max(max_ans, result);
        min_ans = min(min_ans, result);
        return;
    }

    for (int op = 0; op < 4; op++) {
        if (operateors[op] == 0) continue;
        operateors[op]--;
        dfs(index + 1, calculate(op, result, a[index]));
        operateors[op]++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 4; i++) {
        int cnt; cin >> cnt;
        operateors.push_back(cnt);
    }

    dfs(1, a[0]);
    cout << max_ans << '\n' << min_ans;
}