#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(const vector<int> &v) {
    for (int num : v) cout << num << ' ';
    cout << '\n';
}

int lis_v1(const vector<int> &v) {

    vector<int> dp(v.size(), 1); // 1로 초기화
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    printVec(dp);
    return *max_element(dp.begin(), dp.end());
}

int lis_v2(const vector<int> &v) {

    vector<int> lis;
    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        if (it == lis.end()) lis.push_back(v[i]);
        else *it = v[i];
    }
    printVec(lis);
    return lis.size();
}

vector<int> get_lis(const vector<int> &v) {
    int n = v.size();
    vector<int> lis;
    vector<int> pos(n);
    vector<int> prev(n);

    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        if (it == lis.end()) {
            // prev는 값 기준이 아닌 인덱스 기준으로 해야 v 안의 요소들의 값이 겹치더라도 문제 되지 않는다.
            // prev[v[i]] = *lis.rbegin();
            lis.push_back(v[i]);
            prev[i] = pos[*lis.rbegin()];
        } else {
            *it = v[i];
        }
        pos[i] = it - lis.begin();
    }

    vector<int> real_lis;
    real_lis.push_back(*lis.rbegin());
    while (real_lis.size() < lis.size()) {
        real_lis.push_back(prev[*real_lis.rbegin()]);
    }
    reverse(real_lis.begin(), real_lis.end());
    return real_lis;
}

int main() {
    vector<int> a = {10, 20, 10, 30, 20, 50};
    int lis_len1 = lis_v1(a);
    int lis_len2 = lis_v2(a);
    cout << lis_len1 << ' ' << lis_len2 << '\n';

    vector<int> b = {3, 5, 7, 9, 2, 1, 4, 8};
    lis_len1 = lis_v1(b);
    lis_len2 = lis_v2(b);
    cout << lis_len1 << ' ' << lis_len2 << '\n';


}