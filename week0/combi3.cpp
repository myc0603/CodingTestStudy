#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void print(const vector<int> &v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}
void combi3(const vector<int> &from, vector<int> &to) {
    int n = from.size();
    to.clear();
    for (int i = 0; i < n; i++) {
        to.push_back(from[i]);
        for (int j = i + 1;  j < n; j++) {
            to.push_back(from[j]);
            for (int k = j + 1; k < n; k++) {
                to.push_back(from[k]);
                printf("%d : ", ++cnt);
                print(to);
                to.pop_back();
            }
            to.pop_back();
        }
        to.pop_back();
    }
}

int main() {
    vector<int> to = {};
    combi3({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, to);
    return 0;
}