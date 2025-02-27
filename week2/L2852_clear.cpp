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

    int times[n+1] = {};
    int status[n+1] ={};
    int score[3] = {};
    int before = 0;

    for (int i = 0; i < n; i++) {
        int team; cin >> team;
        score[team]++;

        string timeStr; cin >> timeStr;
        int time = timeConvertStoI(timeStr);
        times[i] = time - before;

        status[i+1] = winning(score);

        before = time;
    }
    times[n] = 60 * 48 - before;

    int winningTimes[3] = {};
    for (int i = 0; i <= n; i++) {
        winningTimes[status[i]] += times[i];
    }

    for (int i = 1; i <= 2; i++) {
        int min = winningTimes[i] / 60;
        int sec = winningTimes[i] % 60;
        cout << setfill('0') << setw(2) << min << ':' << setw(2) << sec << '\n';
    }   
}