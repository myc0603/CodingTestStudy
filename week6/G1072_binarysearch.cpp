#include <iostream>
using namespace std;

long long total_cnt, win_cnt, cur_rate, goal_rate;

bool check(long long mid) {
    long long new_total = total_cnt + mid;
    long long new_win = win_cnt + mid;

    long long rate = new_win * 100 / new_total;
    return rate >= goal_rate;
}

int main() {
    cin >> total_cnt >> win_cnt;

    cur_rate = win_cnt * 100 / total_cnt;
    goal_rate = cur_rate + 1;

    long long left = 0;
    long long right = 1LL << 30;
    if (!check(right)) {
        cout << -1;
        return 0;
    }
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }

    cout << right;
}