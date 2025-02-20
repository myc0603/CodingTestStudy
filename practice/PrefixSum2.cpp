#include <bits/stdc++.h>
using namespace std;

void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {

    // initiate
    int n = 10;
    int a[n+1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // make psum of arr a
    // psum[j]의 의미: 처음부터 j개까지의 합. 인덱스로는 0 ~ j-1, [0,j)
    int psum[n+1] = {}; // 모두 0으로 초기화
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + a[i];
    }

    // 구간합
    // 배열 a의 연속되는 k개의 요소의 합을 나타내는 배열
    // 첫번째 요소: psum[k] (- psum[0])
    // 마지막 요소: psum[n] - psum[n-k]
    // subSum[j]의 의미: 배열 a의 j번째 인덱스부터 k개의 합
    int k = 4;
    int subSum1[n-k+1] = {};
    for (int i = 0; i <= n-k; i++) {
        subSum1[i] = psum[k+i] - psum[k];
    }
    int subSum2[n-k+1] = {};
    for (int i = k; i <= n; i++) {
        subSum2[k-i] = psum[i] - psum[i-k];
    }
    printArr(a, n+1);
    printArr(psum, n+1);
    printArr(subSum1, n-k+1);
    printArr(subSum2, n-k+1);
}