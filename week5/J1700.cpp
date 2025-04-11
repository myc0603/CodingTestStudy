#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int n, k, using_order[105], cnt;
unordered_set<int> concents;
queue<int> orders[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int device; cin >> device;
        using_order[i] = device;
        orders[device].push(i);
    }
    for (int device = 1; device <= k; device++) orders[device].push(k);

    for (int i = 0; i < k; i++) {

        int using_device = using_order[i];
        orders[using_device].pop();
        if (concents.find(using_device) != concents.end()) continue;

        if (concents.size() >= n) {

            // 가장 늦게 사용되는 device pull
            priority_queue<pair<int, int>> pq;
            for (int device : concents) {
                pq.push({orders[device].front(), device});
            }
            int pulled_device = pq.top().second;
            concents.erase(pulled_device);

            cnt++;

            // cout << "  pulled device: " << pulled_device << '\n';
        }

        // plug in
        concents.insert(using_device);

        // cout << "  plug in device: " << using_device << '\n';
        // cout << "concents: ";
        // for (int device : concents) cout << device << ' '; cout << '\n';
    }
    cout << cnt;
}