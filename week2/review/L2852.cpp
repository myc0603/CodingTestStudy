#include <bits/stdc++.h>
using namespace std;

int timeConverter(string &time) {
    int min = atoi(time.substr(0, 2).c_str());
    int sec = atoi(time.substr(3, 2).c_str());
    return min * 60 + sec;
}

string timeConverter(int time) {
    string temp = "0" + to_string(time / 60);
    string min = temp.substr(temp.size()-2);
    temp = "0" + to_string(time % 60);
    string sec = temp.substr(temp.size()-2);
    
    return min + ':' + sec;
}

int winning(int score[]) {
    if (score[1] == score[2]) {
        return 0;
    }
    return score[1] > score[2] ? 1 : 2;
}

int main() {
    int n; cin >> n;

    int beforeTime = 0;
    int endTime = 48 * 60;
    int score[3] = {};
    int winningTimes[3] = {};
    while (n--) {
        int team; cin >> team;
        string timeStr; cin >> timeStr;

        int curTime = timeConverter(timeStr);
        winningTimes[winning(score)] += curTime - beforeTime;

        score[team]++;
        beforeTime = curTime;
    }
    winningTimes[winning(score)] += endTime - beforeTime;

    cout << timeConverter(winningTimes[1]) << '\n';
    cout << timeConverter(winningTimes[2]) << '\n';
    
}