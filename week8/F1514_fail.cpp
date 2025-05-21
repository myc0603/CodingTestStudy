#include <iostream>
#include <queue>
using namespace std;

struct RotateInfo {
    int start, end, count;
    RotateInfo() {}
    RotateInfo(int s, int e, int c) : start(s), end(e), count(c) {}

    bool operator<(const RotateInfo &info) {
        if (end - start == info.end - info.start) return count < info.count;
        return (end - start) < (info.end - info.start);
    }
};

int n;
string from, to;

RotateInfo rotate(const RotateInfo &info) {
    for (int i = info.start; i <= info.end; ++i) {
        from[i] += info.count;
        if (from[i] < '0') from[i] += 10;
        if (from[i] > '9') from[i] -= 10;
    }

    //
    for (int i = info.start; i <= info.end; ++i) {
        
    }
}

int calDiff(int diff) {
    if (diff > 5) return diff - 10;
    if (diff <= -5) return diff + 10;
}

int main() {
    cin >> n >> from >> to;

    priority_queue<RotateInfo> pq;
    for (int i = 0; i < n;) {
        int diff = calDiff(to[i] - from[i]);
        if (diff == 0) {
            ++i; continue;
        }
        int nextDiff = calDiff(to[i+1] - from[i+1]);
        int nenextDiff = calDiff(to[i+2] - from[i+2]);
        if (diff == nenextDiff) {
            pq.push( {i, i + 2, max(-3, min(3, diff))} );
            i += 3;
        } else if (diff * nextDiff > 0 && diff * nenextDiff > 0) {
            pq.push( {i, i + 2, max(-3, min(3, diff))} );
            i += 3;
        } else if (diff * nextDiff > 0) {
            pq.push( {i, i + 1, max(-3, min(3, diff))} );
            i += 2;
        } else if (diff) {
            pq.push( {i, i, max(-3, min(3, diff))} );
            ++i;
        }
    }

    int cnt = 0;
    while (from != to) {
        auto info = pq.top();
        pq.pop();
        rotate(info);
        // pq에 추가
    }
    cout << cnt;
}