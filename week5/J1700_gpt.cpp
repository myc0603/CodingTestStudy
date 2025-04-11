#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int n, k;
vector<int> schedule;
unordered_map<int, vector<int>> device_future;
unordered_map<int, int> next_index;
unordered_set<int> concents;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    schedule.resize(k);

    // 입력 받기 & future usage 기록
    for (int i = 0; i < k; i++) {
        cin >> schedule[i];
        device_future[schedule[i]].push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int cur_device = schedule[i];
        // 이번에 사용했으니 다음 인덱스로 이동
        next_index[cur_device]++;
        
        if (concents.count(cur_device)) continue;

        if (concents.size() < n) {
            concents.insert(cur_device);
            continue;
        }

        // 가장 늦게 사용될 장치 선택
        int farthest = -1, to_unplug = -1;
        for (int plugged : concents) {
            int idx = next_index[plugged];
            if (idx >= device_future[plugged].size()) {
                // 이 장치는 앞으로 안 씀 → 바로 뽑자
                to_unplug = plugged;
                break;
            }
            int next_use = device_future[plugged][idx];
            if (next_use > farthest) {
                farthest = next_use;
                to_unplug = plugged;
            }
        }

        concents.erase(to_unplug);
        concents.insert(cur_device);
        cnt++;
    }

    cout << cnt << '\n';
}
