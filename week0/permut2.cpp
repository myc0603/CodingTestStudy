#include <bits/stdc++.h>
using namespace std;

int a[] = {1, 2, 3, 4};
int n = 4, r = 2, cnt = 0;
void print(int r);
void makePermutation(int n, int r, int depth);
vector<vector<int>> makePermutations(int n, int r, int depth) {
    
}
int main() {
    makePermutation(n, r, 0);
    return 0;
}
void print(int r) {
    cout << ++cnt << ": ";
    for (int i = 0; i < r; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
void makePermutation(int n, int r, int depth) {
    if (r == depth) {
        print(r);
        return;
    }
    for (int i = depth; i < n; i++) {
        printf("swap(a[%d], a[%d]) before makePermutation(%d, %d, %d)\n", i, depth, n, r, depth + 1);
        swap(a[i], a[depth]);
        makePermutation(n, r, depth + 1);
        printf("swap(a[%d], a[%d]) after makePermutation(%d, %d, %d)\n", i, depth, n, r, depth + 1);
        swap(a[i], a[depth]);
        cout << '\n';
    }
    return;
}