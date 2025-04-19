#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(const vector<int> &v) {
    for (int num : v) cout << num << ' ';
    cout << '\n';
}

int lis_v1(const vector<int> &v) {
    int n = v.size();
    vector<int> dp(n, 1); // 1로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // printVec(dp);
    return *max_element(dp.begin(), dp.end());
}

int lis_v2(const vector<int> &v) {
    int n = v.size();
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        if (it == lis.end()) lis.push_back(v[i]);
        else *it = v[i];
    }
    // printVec(lis);
    return lis.size();
}

vector<int> get_lis_gpt(const vector<int> &v) {
    int n = v.size();
    vector<int> lis;
    vector<int> lis_idx;
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        int idx = it - lis.begin();

        if (it == lis.end()) {
            lis.push_back(v[i]);
            lis_idx.push_back(i);
        } else {
            *it = v[i];
            lis_idx[idx] = i;
        }

        if (idx > 0) prev[i] = lis_idx[idx-1];
    }

    vector<int> real_lis;
    int cur = lis_idx.back();
    while (cur != -1) {
        real_lis.push_back(v[cur]);
        cur = prev[cur];
    }
    reverse(real_lis.begin(), real_lis.end());
    
    for (int num : real_lis) cout << num << ' ';
    cout << '\n';

    return real_lis;
}

vector<int> get_lis_gpt_with_debug(const vector<int>& v) {
    int n = v.size();
    vector<int> lis;                  // 현재까지의 LIS 끝값들
    vector<int> lis_idx;             // lis[i]의 실제 v[]에서의 인덱스
    vector<int> prev(n, -1);         // 역추적을 위한 연결 정보
    vector<int> pos(n);              // v[i]가 LIS의 몇 번째 자리에 들어갔는지

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        int idx = it - lis.begin(); // v[i]가 들어갈 자리 = 길이 idx+1짜리 LIS

        if (it == lis.end()) {
            lis.push_back(v[i]);
            lis_idx.push_back(i);
        } else {
            *it = v[i];
            lis_idx[idx] = i;
        }

        pos[i] = idx; // v[i]가 길이 idx+1짜리 LIS의 끝이 되었다는 뜻
        if (idx > 0) {
            prev[i] = lis_idx[idx - 1]; // 바로 앞 길이의 LIS 마지막 원소 인덱스를 저장
        }

        // 🔍 디버깅 출력
        cout << "i = " << i << ", v[i] = " << v[i] << '\n';
        cout << "  -> position to enter in(idx): " << idx << '\n';
        cout << "  -> lis: ";
        for (auto x : lis) cout << x << ' ';
        cout << "\n  -> lis_idx: ";
        for (auto x : lis_idx) cout << x << ' ';
        cout << "\n  -> prev[" << i << "] = " << prev[i];
        cout << "\n  -> pos[" << i << "] = " << pos[i] << "\n\n";
    }

    // 역추적
    vector<int> res;
    int cur = lis_idx.back();
    while (cur != -1) {
        res.push_back(v[cur]);
        cur = prev[cur];
    }
    reverse(res.begin(), res.end());
    return res;
}
    
int main() {
    vector<int> a = {10, 20, 10, 30, 20, 50};
    int lis_len1 = lis_v1(a);
    int lis_len2 = lis_v2(a);
    cout << "length of LIS of vector a: ";
    cout << lis_len1 << ' ' << lis_len2 << '\n';

    vector<int> b = {3, 5, 7, 9, 2, 1, 4, 8};
    lis_len1 = lis_v1(b);
    lis_len2 = lis_v2(b);
    cout << "length of LIS of vector b: ";
    cout << lis_len1 << ' ' << lis_len2 << '\n';

    cout << "LIS of vector a: \n";
    auto real_lis1 = get_lis_gpt(a);
    // auto real_lis1 = get_lis_gpt_with_debug(a);
    for (int num : real_lis1) cout << num << ' ';
    cout << '\n';

    cout << "LIS of vector b: \n";
    auto real_lis2 = get_lis_gpt(b);
    // auto real_lis2 = get_lis_gpt_with_debug(b);
    for (int num : real_lis2) cout << num << ' ';
    cout << '\n';

}