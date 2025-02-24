#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int scores[3] = {};
    int winningTimes[3] ={};
    int beforeTime = 0;
    int endTime = 48 * 60;
    while (n--) {
        int team; string time;
        cin >> team >> time;

        scores[team]++;

        int min = atoi(time.substr(0, 2).c_str());
        int sec = atoi(time.substr(3, 2).c_str());
        int curTime = min * 60 + sec;

        if (scores[1] > scores[2]) {
            winningTimes[1] += curTime - beforeTime;
        } else if (scores[1] < scores[2]) {
            winningTimes[2] += curTime - beforeTime;
        }

        beforeTime = curTime;
    }

    if (scores[1] > scores[2]) {
        winningTimes[1] += endTime - beforeTime;
    } else if (scores[1] < scores[2]) {
        winningTimes[2] += endTime - beforeTime;
    }



    for (int i = 1; i <= 2; i++) {
        int min = winningTimes[i] / 60;
        int sec = winningTimes[i] % 60;
        cout << setfill('0') << setw(2) << min << ':' << setw(2) << sec << '\n';
    }
    
}