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

void printWinningTimes(int winningTimes[]) {
    for (int i = 1; i <= 2; i++) {
        int min = winningTimes[i] / 60;
        int sec = winningTimes[i] % 60;
        cout << setfill('0') << setw(2) << min << ':' << setw(2) << sec << '\n';
    }   
}

int main() {
    int n; cin >> n;

    int score[3] = {};
    int winningTimes[3] = {};
    int before = 0; int end = 60 * 48;
    while (n--) {
        int team; cin >> team;
        string timeStr; cin >> timeStr;

        int time = timeConvertStoI(timeStr);
        winningTimes[winning(score)] += time - before;

        score[team]++;

        before = time;
    }
    winningTimes[winning(score)] += end - before;

    printWinningTimes(winningTimes);
}