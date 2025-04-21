#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> runningTimes;

long long canRideCountIn(long long minTime) {
    long long rideSum = m;
    for (int i = 1; i <= m; i++) {
        rideSum += minTime / runningTimes[i];
    }
    return rideSum;
}

// 1-based index
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    runningTimes.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> runningTimes[i];
    }

    // left + 1 < right ver.
    long long left = -1LL;
    long long right = 1LL << 40;
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (canRideCountIn(mid) >= n) right = mid;
        else left = mid;
    }
    long long rideTime = right;
    
    // left <= right ver.
    // long long left = 0LL;
    // long long right = 1LL << 40;
    // long long time = 0;
    // while (left <= right) {
    //     long long mid = (left + right) / 2;
    //     if (canRideCountIn(mid) >= n) {
    //         time = mid;
    //         right = mid - 1;
    //     } else left = mid + 1;
    // }
    // long long rideTime = time;

    long long beforeRideCount = rideTime ? canRideCountIn(rideTime - 1) : 0;
    // long long beforeRideCount = canRideCountIn(rideTime - 1); // rideTime can be zero
    long long toBeRideCount = n - beforeRideCount;
    for (int i = 1; i <= m; i++) {
        if (rideTime % runningTimes[i] == 0) {
            toBeRideCount--;
            if (toBeRideCount == 0) {
                cout << i;
                return 0;
            }
        }
    }
}