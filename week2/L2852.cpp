#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int times[n+1] = {};
    int status[n+1] = {}; // 이기고 있는 팀, 0 : 비기는 중
    int score[3] = {};
    int before = 0;

    for (int i = 0; i < n; i++) {
        int team; cin >> team;
        score[team]++;

        string timeStr; cin >> timeStr;
        int min = atoi(timeStr.substr(0, 2).c_str());
        int sec = atoi(timeStr.substr(3, 2).c_str());
        int time = min * 60 + sec;
        times[i] = time - before;

        if (score[1] > score[2]) {
            status[i+1] = 1;
        } else if (score[1] < score[2]) {
            status[i+1] = 2;
        }




        before = time;
    }
    times[n] = 60 * 48 - before;

    // debugging
    cout << "times : ";
    for (int num : times) {
        cout << num << ' ';
    }
    cout << '\n';

    cout << "status: ";
    for (int num : status) {
        cout << num << ' ';
    }
    cout << '\n';

    cout << "score : ";
    for (int num : score) {
        cout << num << ' ';
    }
    cout << '\n';

    int winningTimes[3] ={};
    // 실수로 i를 n+1까지 돌려버림
    for (int i = 0; i <= n; i++) {
        cout << "i: " << i << ", status[i]: " << status[i] << ", times[i]: " << times[i] << '\n';
        winningTimes[status[i]] += times[i];
    }

    cout << "\nprint winningTimes: ";
    for (int t : winningTimes) {
        cout << t << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= 2; i++) {
        int min = winningTimes[i] / 60;
        int sec = winningTimes[i] % 60;
        cout << setfill('0') << setw(2) << min << ':' << setw(2) << sec << '\n';
    }   
}