#include <bits/stdc++.h>
using namespace std;

void printMat(bool a[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

// before 처음에는 -1같은거 넣으면 됨
void funcV1(bool a[][10], int n, int vertex, int before) {
    for (int j = 0; j < n; j++) {
        // before는 무시
        if (j == before) continue;
        if (a[vertex][j]) {
            // do something
            cout << vertex << ',' << j << '\n';
            funcV1(a, n, j, vertex);
        }
    }
}

// 방문한 vertex들을 모두 before에 저장
void funcV2(bool a[][10], int n, int vertex, vector<int> before) {
    for (int j = 0; j < n; j++) {
        // before는 무시
        if (find(before.begin(), before.end(), j) == before.end()) continue;
        if (a[vertex][j]) {
            // do something
            cout << vertex << ',' << j << '\n';
            funcV1(a, n, j, vertex);
        }
    }
}

int main() {
    bool a[10][10] = {{}};
    printMat(a, 10);
    cout << "==============\n";
    a[1][2] = 1;
    a[2][1] = 1;
    a[1][3] = 1;
    a[3][1] = 1;
    a[3][4] = 1;
    a[4][3] = 1;
    printMat(a, 10);
    cout << "==============\n";

    for (int i = 0; i < 10; i++) {
        cout << "initial vertex: " << i << '\n';
        funcV1(a, 10, i, -1);
    }
}