#include <bits/stdc++.h>
using namespace std;

int n = 9, r = 2, tot = 0;
int a[9];
bool solved = false;
void printAns(vector<int> &to) {
    cout << "printAns called\nparameter to: ";
    for (int i : to) {
        cout << i << ' ';
    }
    cout << endl;

    vector<int> ans = {};
    for (int i : a) {
        if (i == to[0] || i == to[1]) {
            continue;
        }
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());

    for (int i : ans) {
        cout << i << '\n';
    }
}
bool check100(vector<int> &to) {    
    int sum = 0;
    for (int i: to) {
        sum += i;
    }
    printf("tot: %d, sum: %d\n", tot, sum);
    return tot - sum == 100;
}
void combi(int start, vector<int> &to) {
    if (solved) return;
    if (to.size() == r && check100(to)) {
        printAns(to);
        solved = true;
        return;
    }
    
    for (int i = start + 1; i < n; i++) {
        to.push_back(a[i]);
        combi(i, to);
        to.pop_back();
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        tot += a[i];
    }
    vector<int> to = {};
    combi(-1, to);
    return 0;
}