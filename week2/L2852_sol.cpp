#include <bits/stdc++.h>
using namespace std;

int timeConvertStoI(string time) {
    int min = atoi(time.substr(0, 2).c_str());
    int sec = atoi(time.substr(3, 2).c_str());
    return min * 60 + sec;
}

int winning(int score[]) {
    if (score[1] > score[2]) return 1;
    else if (score[1] < score[2]) return 2;
    return 0;
}

int main() {
    int n; cin >> n;

    int score[3] = {};
    int winningTimes[3] = {};

    int before = 0; int end = 60 * 48;

    for (int i = 0; i < n; i++) {
        int team; cin >> team;
        score[team]++;

        string timeStr; cin >> timeStr;
        int time = timeConvertStoI(timeStr);
        winningTimes[winning(score)] += time - before;

        before = time;
    }
    winningTimes[winning(score)] += end - before;

    for (int t : winningTimes) {
        cout << setfill('0') << setw(2) << t / 60 << ':' << setw(2) << t % 60 << '\n';
    }
}