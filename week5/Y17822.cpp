#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// a[i]: 1-based index
// a[i][j]: 0-based index
int n, m, t, a[54][54];

double get_avg() {
    double sum = 0;
    double cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
            if (a[i][j]) cnt += 1;
        }
    }

    return sum / cnt;
}

// x의 배수인 원판을 d방향으로 k칸 회전
void rotate(int x, int d, int k) {
    
    int *temp = new int[3 * m];
    for (int i = x; i <= n; i += x) { // x의 배수인 원판
        memcpy(temp, a[i], m * sizeof(int));
        memcpy(temp + m, a[i], m * sizeof(int));
        memcpy(temp + 2 * m, a[i], m * sizeof(int));
        
        auto start = temp + m;
        start += d ? k : -k;
        memcpy(a[i], start, m * sizeof(int));
    }
    delete[] temp;
}

void post_process() {
    // 지워야 될 수의 index를 저장했다가 나중에 한 번에 지워야됨
    // 하나의 숫자가 여러 숫자랑 인접할 수 있기 때문

    vector<pair<int, int>> tobe_erase; // set으로 하는게 나으려나? 중복제거 때문에?

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            if (a[i][j] == a[i][(j + 1) % m]) {
                tobe_erase.push_back( {i, j} );
                tobe_erase.push_back( {i, (j + 1) % m} );
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++)  {
            if (a[i][j] == 0) continue;
            if (a[i][j] == a[i+1][j]) {
                tobe_erase.push_back( {i, j} );
                tobe_erase.push_back( {i + 1, j} );
            }
        }
    }

    if (tobe_erase.empty()) {
        double avg = get_avg();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > avg) a[i][j]--;
                else if (0 < a[i][j] && a[i][j] < avg) a[i][j]++;
            }
        }
        return;
    }

    for (auto p : tobe_erase) {
        a[p.first][p.second] = 0;
    }
}

int main() {
    // n: 원판 수, m: 원판에 적힌 숫자 개수, t: 회전 수
    // n, m: 2 ~ 50, t: 1 ~ 50
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (t--) {
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);
        post_process();
    }

    // 원판에 적힌 모든 수의 합 출력
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            ans += a[i][j];
        }
    }
    cout << ans;
}