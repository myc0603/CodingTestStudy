#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int mid = m/2;
    vector<int> front;
    vector<int> back;

    int cnt = 0;
    while (n--) {
        int temp; cin >> temp;
        if (temp <= mid) front.push_back(temp);
        else back.push_back(temp);
    }

    for (int n1 : front) {
        for (int n2 : back) {
            cnt += n1 + n2 == m ? 1 : 0;
        }
    }
    cout << cnt << '\n';
}