#include <iostream>
using namespace std;

int main() {
    long long total_cnt, win_cnt;
    cin >> total_cnt >> win_cnt;

    long long cur_rate = win_cnt * 100 / total_cnt;
    long long goal_rate = cur_rate + 1;

    if (goal_rate >= 100) {
        cout << -1;
        return 0;
    }

    long long temp = goal_rate * total_cnt - 100 * win_cnt;
    long long m = 100 - goal_rate;

    
    long long ans = (temp + m - 1) / m;
    cout << ans;
}