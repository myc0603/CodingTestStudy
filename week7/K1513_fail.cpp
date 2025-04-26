#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, c;
vector<long long> dp[51][51];
vector<pair<int, int>> arcades;

void printVector(const vector<long long> &v) {
    for (long long x : v) cout << x << ' ';
    cout << '\n';
}

vector<long long> addVector(const vector<long long> &v1, const vector<long long> &v2) {
    if (v1.empty()) return v2;
    if (v2.empty()) return v1;
    size_t size = v1.size(); // v1, v2 size 같아야 함.
    vector<long long> result(size);
    for (size_t i = 0; i < size; i++) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

// 오락실 인덱스도 뒤에 오는걸 확인해야됨
vector<long long> dfs(int y, int x, vector<int> visitedArcades) {
    int cnt = 0;

    // 현재 위치가 오락실이면 cnt 1 증가
    for (int i = 0; i < c; i++) {
        if (arcades[i].first == y && arcades[i].second == x) {
            cnt++;
            
            cout << "current position is arcade y: " << y << ',' << x << '\n';
            cout << "visited arcades: ";
            for (int arcade : visitedArcades) cout << arcade << ' ';
            cout << '\n';

            if (visitedArcades.empty() || visitedArcades.back() < i) {
                if (visitedArcades.size()) {
                    cout << "before arcade idx: " << visitedArcades.back() << ", current arcade idx: " << i << '\n';
                }
                visitedArcades.push_back(i);
                cout << "visitedArcade push_back(i), i: " << i << '\n';
            }
            else return vector<long long>(c + 1);
            break; // 없어도 괜찮아야 함.
        }
    }

    vector<long long> &result = dp[y][x];
    if (result.size()) return result;

    // 기저 사례 추가
    if (y == n && x == m) {
        result.resize(c + 1);
        result[cnt] = 1;
        return result;
    }

    vector<long long> v1, v2;
    if (y < n) v1 = dfs(y + 1, x, visitedArcades);
    if (x < m) v2 = dfs(y, x + 1, visitedArcades);
    result = addVector(v1, v2);
    if (cnt == 1) {
        for (int i = c; i >= 1; i--) {
            result[i] = result[i-1];
        }
        result[0] = 0;
    }
    return result;
}

int main() {
    cin >> n >> m >> c;
    for (int i = 0; i < c; i++) {
        int y, x;
        cin >> y >> x;
        arcades.push_back( {y, x} );
    }

    vector<long long> result = dfs(1, 1, vector<int>());
    for (long long cnt : result) cout << cnt << ' ';


    cout << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << i << "," << j << " : ";
            printVector(dp[i][j]);
        }
    }
}