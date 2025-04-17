#include <iostream>
#include <unordered_map>
using namespace std;

int sum, n, m, a[1005], b[1005], tot_a, tot_b, cnt;
unordered_map<int, int> map1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> sum >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot_a += a[i];
    }
    if (tot_a == sum) cnt++;

    for (int j = 0; j < m; j++) {
        cin >> b[j];
        tot_b += b[j];
    }
    if (tot_b == sum) cnt++;

    for (int l = 0; l < n; l++) {
        int temp = 0;
        for (int r = l; temp == 0 || r != l - 1 + n; r++) {
            temp += a[r % n];
            if (temp > sum) break;
            if (temp == sum) {
                cnt++;
                break;
            }
            map1[temp]++;
        }
    }
    if (tot_a < sum) map1[tot_a]++;

    for (int l = 0; l < m; l++) {
        int temp = 0;
        for (int r = l; temp == 0 || r != l - 1 + m; r++) {
            temp += b[r % m];
            if (temp > sum) break;
            if (temp == sum) {
                cnt++;
                break;
            }
            cnt += map1[sum-temp];
        }
    }
    if (tot_b < sum) cnt += map1[sum-tot_b];
    
    cout << cnt;
}