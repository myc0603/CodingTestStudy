#include <iostream>
#include <unordered_map>
using namespace std;

int sum, n, m, a[1005], b[1005], tot_a, tot_b, cnt;
unordered_map<int, int> map1, map2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> sum >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot_a += a[i];
    }
    if (tot_a == sum) cnt++;
    else if (tot_a < sum) map1[tot_a]++;

    for (int j = 0; j < m; j++) {
        cin >> b[j];
        tot_b += b[j];
    }
    if (tot_b == sum) cnt++;
    else if (tot_b < sum) map2[tot_b]++;

    for (int l = 0; l < n; l++) {
        int temp = 0;
        for (int r = l; temp == 0 || r != (l - 1 + n) % n; r = (r + 1) % n) {
            temp += a[r];
            if (temp > sum) break;
            if (temp == sum) {
                cnt++;
                break;
            }
            map1[temp]++;
        }
    }

    for (int l = 0; l < m; l++) {
        int temp = 0;
        for (int r = l; temp == 0 || r != (l - 1 + m) % m; r = (r + 1) % m) {
            temp += b[r];
            if (temp > sum) break;
            if (temp == sum) {
                cnt++;
                break;
            }
            map2[temp]++;
        }
    }

    for (auto p1 : map1) {
        int temp = p1.first;
        if (map2.find(sum - temp) != map2.end()) { // 이걸 확인하는게 더 빠른 듯?
            cnt += p1.second * map2[sum-temp];
        }
    }
    
    cout << cnt;
}