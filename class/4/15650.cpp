#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void combi(int idx) {
    if (v.size() == m) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i <= n; ++i) {
        v.push_back(i);
        combi(i + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    combi(1);
}