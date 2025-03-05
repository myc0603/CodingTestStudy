#include <bits/stdc++.h>
using namespace std;

int n, a[10][10], flowers[10][10];
int dy[] = {0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 1, -1};

void printFlowers() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << flowers[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool canPlant(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (flowers[ny][nx] == 1) {
            return false;
        }
    }
    return true;
}

void plant(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        flowers[ny][nx] = 1;
    }
}

void pullOut(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        flowers[ny][nx] = 0;
    }
}


int calculate() {
    // cout << "\ncall calculate(), print flowers\n";
    // printFlowers();

    int price = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flowers[i][j] == 1) price += a[i][j];
        }
    }
    // cout << "price: " << price << '\n';
    return price;
}

int calculateV2(int y, int x) {
    int tot = 0;
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        tot += a[ny][nx];
    }
    return tot;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 200 * 15;

    int canPlantCnt = (n-2) * (n-2);
    for (int i = 0; i < canPlantCnt; i++) {
        // i에 꽃심기
        int y1 = i / (n-2) + 1; int x1 = i % (n-2) + 1;
        // cout << "position of first flower: " << y1 << ',' << x1 << '\n';
        plant(y1, x1);

        for (int j = i + 1; j < canPlantCnt; j++) {
            // j에 꽃심기
            int y2 = j / (n-2) + 1; int x2 = j % (n-2) + 1;
            if (!canPlant(y2, x2)) continue;
            // cout << "position of second flower: " << y2 << ',' << x2 << '\n';
            plant(y2, x2);

            for (int k = j + 1; k < canPlantCnt; k++) {
                int y3 = k / (n-2) + 1; int x3 = k % (n-2) + 1;
                if (!canPlant(y3, x3)) continue;
                // cout << "position of third flower: " << y3 << ',' << x3 << '\n';
                plant(y3, x3);

                // 총 비용 계산
                ans = min(calculate(), ans);

                //v2 -> more fast
                // int totPrice = calculateV2(y1, x1) + calculateV2(y2, x2) + calculateV2(y3, x3);
                // ans = min(totPrice, ans);

                pullOut(y3, x3);
            }

            // j에 꽃 심은거 뽑기
            pullOut(y2, x2);
        }

        // i에 꽃 심은거 뽑기
        pullOut(y1, x1);
    }

    cout << ans << '\n';
}