#include <bits/stdc++.h>
using namespace std;

// 조합 순열 split() 연습
// 1-A, B

void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

// 순열 대상인 a의 순서를 바꾸면서 순열을 돈다.
void makePermutation(int* a, int n, int r, int depth) {
    if (depth == r) {
        // do something
        printArr(a, n);
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(a[i], a[depth]);
        makePermutation(a, n, r, depth+1);
        swap(a[i], a[depth]);
    }
}

void printVec(vector<int> v) {
    for (auto num : v) {
        cout << num << ' ';
    }
    cout << '\n';
}

void combiV1(int* from, vector<int> result, int n, int r, int start) {
    // initial start = -1
    if (result.size() == r) {
        // do something
        printVec(result);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        result.push_back(from[i]);
        combiV1(from, result, n, r, i);
        result.pop_back();
    }
}

void combiV2(int* from, vector<int> result, int n, int r, int start) {
    // initial start = 0
    if (result.size() == r) {
        // do something
        printVec(result);
        return;
    }

    for (int i = start; i < n; i++) {
        result.push_back(from[i]);
        combiV2(from, result, n, r, i + 1);
        result.pop_back();
    }
}

vector<vector<int>> combis();

int main() {
    int n = 4;
    int r1 = 4;
    int a[] = {1, 2, 3, 4};

    // makePermutation(a, n, r1, 0);

    int r2 = 2;
    vector<int> result;
    combiV1(a, result, n, r2, -1);

    cout << "=============\n";

    result.clear();
    combiV2(a, result, n, r2, 0);

    return 0;
}