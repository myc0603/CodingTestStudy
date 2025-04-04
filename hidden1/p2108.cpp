#include <iostream>
#include <algorithm>
using namespace std;

int a[500000], cnt[8001]; // 0 -> 4000, -4000 -> 0 4000 -> 8000

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    int sum = 0; // int 범위 안
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        cnt[4000+a[i]]++;
    }

    // 산술평균 -1.8 -> -2
    bool minus = sum < 0;
    int avg = sum * 10 / n;
    avg = minus ? -avg : avg;
    if (avg % 10 >= 5) avg += 10;
    avg /= 10;
    avg = minus ? -avg : avg;
    cout << avg << '\n';
    
    // 중앙값
    sort(a, a + n);
    cout << a[n/2] << '\n';

    // 최빈값
    int mx = *max_element(cnt, cnt + 8001);
    int mode = -1;
    for (int i = 0; i < 8001; i++) {
        if (mx == cnt[i]) {
            if (mode != -1) { // 고친 부분
                mode = i;
                break;
            }
            mode = i;
        }
    }
    mode -= 4000;
    cout << mode << '\n';

    // 범위
    cout << *max_element(a, a + n) - *min_element(a, a + n) << '\n';
}