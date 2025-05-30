#include <iostream>
using namespace std;

int n, ph[100002], minPh = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> ph[i];

    // minPh = 1e9 + 1로 하면 두 용액의 합의 절댓값이 초기 minPh값을 넘어갈 수도 있음
    // 넘어가게 되려면 둘 다 매우 큰 양수이거나 매우 작은 음수
    // 첫 sum 값으로 minPh가 업데이트 돼야 하는데 그러지 않게 되는 경우가 첫 sum의 절댓값이 
    // 1e9 + 1보다 커야되고 이 때 양 끝값이 무조건 양수이거나 음수여야 되고 이 경우가
    // 아래의 얼리리턴 패턴으로 빼놓은 경우랑 일치함
    
    // if (ph[0] >= 0) {
    //     cout << ph[0] << ' ' << ph[1] << '\n';
    //     return 0;
    // }
    // if (ph[n-1] <= 0) {
    //     cout << ph[n-2] << ' ' << ph[n-1] << '\n';
    //     return 0;
    // }

    int ansl = 0, ansr = n - 1;
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = ph[l] + ph[r];
        if (abs(sum) < minPh) {
            minPh = abs(sum);
            ansl = l;
            ansr = r;
        }
        if (sum > 0) --r;
        else if (sum < 0) ++l;
        else break;
    }
    cout << ph[ansl] << ' ' << ph[ansr] << '\n';
}