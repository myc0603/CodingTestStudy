#include <bits/stdc++.h>
using namespace std;

// 조합 순열 split() 연습

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

// make recursive combination func have return value as a vector<int>.
/**
 * 재귀호출되면서 vector to가 새로만들어지면 안되지 파라미터로 계속 전달해야됨
 * return할 필요가 없음
 */
// vector<int> combiV3() {}

/**
 * 재귀호출은 각 호출에서 하나의 변수를 사용하기 위해서는 그 변수를 파라미터로 넘길 수 밖에 없고
 * 함수 안에서 변수를 선언해서 초기화하면 각 호출되는 함수가 서로 공유하지 못한다.
*/
// vector<vector<int>> combis(int* from, vector<int> to, int n, int r, int idx) {
//     if (to.size() == r) {

//     }
// }

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