#include <bits/stdc++.h>
using namespace std;

int n;
int mp, mf, ms, mv;
int p[15], f[15], s[15], v[15], c[15];

bool cmp(vector<int> v1, vector<int> v2) {
    int size = min(v1.size(), v2.size());
    for (int i = 0; i < size; i++) {
        if (v1[i] != v2[i]) {
            return v1[i] < v2[i];
        }
    }
    return v1.size() < v2.size();
}

vector<int> numVectorOf(int num) {
    vector<int> result;

    for (int i = 1; num; i++) {
        if (num % 2) {
            result.push_back(i);
        }
        num >>= 1;
    }
    return result;
}

int calculatePrice(int num) {
    int _p = 0; int _f = 0; int _s = 0; int _v = 0; int _c = 0;

    for (int i = 0; i < n; i++) {
        if (num & (1 << i)) {
            _p += p[i];
            _f += f[i];
            _s += s[i];
            _v += v[i];
            _c += c[i];
        }
    }
    
    if (_p >= mp && _f >= mf && _s >= ms && _v >= mv) {
        return _c;
    }
    return 1e9;
}

int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }


    vector<int> ans;
    int minPrice = 1e8;
    // 경우의 수 000000 ~ 111111
    for (int num = 0; num < (1 << n); num++) {
        int price = calculatePrice(num);
        if (price < minPrice) {
            ans.clear();
            minPrice = price;
            ans.push_back(num);
        } else if (price == minPrice) {
            ans.push_back(num);
        }
    }

    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    cout << minPrice << '\n';
    // cout << ans << '\n';
    vector<vector<int>> v;
    for (int num : ans) {
        v.push_back(numVectorOf(num));
    }
    sort(v.begin(), v.end(), cmp);
    for (int num : v[0]) {
        cout << num << ' ';
    }
}