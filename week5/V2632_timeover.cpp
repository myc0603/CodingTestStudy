#include <iostream>
using namespace std;

int sum, n, m, a[1005], b[1005];

int main() {
    cin >> sum >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    int cnt = 0;
    for (int l1 = 0; l1 < n; l1++) {
        int temp1 = 0;
        for (int r1 = l1; temp1 == 0 || r1 != l1; r1 = (r1 + 1) % n) {
            temp1 += a[r1];
            if (temp1 > sum) break;
            if (temp1 == sum) {
                cnt++;
                break;
            }
            // 이제 b에서 남은 양을 채우면 됨
            for (int l2 = 0; l2 < m; l2++) {
                int temp2 = 0;
                for (int r2 = l2; temp2 == 0 || r2 != l2; r2 = (r2 + 1) % m) {
                    temp2 += b[r2];
                    if (temp1 + temp2 > sum) break;
                    if (temp1 + temp2 == sum) {
                        cnt++;
                        break;
                    } 
                }
            }
        }
    }
    cout << cnt;
}