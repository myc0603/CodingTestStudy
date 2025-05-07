// https://www.acmicpc.net/source/1363883 참고
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c, w[15], bag[12];

// 각 호출에서 주어진 보석을 정해진 가방에 넣는다. -> X
// bool possible(int tot, int bagIdx, int jewelIdx) {
//     if (jewelIdx == tot) return true;

//     if (bag[bagIdx] + w[jewelIdx] <= c) {
//         bag[bagIdx] += w[jewelIdx];
//         return possible(tot, bagIdx, jewelIdx + 1);
//     }
//     if (bagIdx + 1 < m) {
//         return possible(tot, bagIdx + 1, jewelIdx);
//     }
//     return false;
// }

// 주어진 보석을 모든 가방에 넣어본다.
bool possible(int tot, int idx) {
    if (idx == tot) return true;

    for (int i = 0; i < m; ++i) {
        if (bag[i] + w[idx] <= c) {
            bag[i] += w[idx];
            // 바로 return possible(.., ..)를 안하는 이유는 ?
            // 안 되면 다른 가방에다가 넣어봐야지
            if (possible(tot, idx + 1)) return true;
            bag[i] -= w[idx];
        }
        if (bag[i] == 0) break; // 가지치기
    }
    return false; // 어떤 가방에 넣어도 안되는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> w[i];
    sort(w, w + n);

    // bs로 하면 더 빠르게 가능
    for (int i = n; i >= 0; --i) {
        // 왜 안해도 되는거지? possible이 false가 나와야 다시 시도하는데 possible()안에서 다 원복함
        // fill(bag, bag + m, 0);
        if (possible(i, 0)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}