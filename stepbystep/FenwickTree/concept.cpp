#include <iostream>
#include <vector>
using namespace std;

// a, tree : 1-based index
int n = 10, a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> tree;

void init() {
    for (int i = 1; i <= n; ++i) update(i, a[i]);
}

void update(int i, int val) {
    while (i <= n) {
        tree[i] += val;
        i += i & -i;
    }
}

int sum(int i) {
    int result = 0;
    while (i > 0) {
        result += tree[i];
        i -= i & -i;
    }
    return result;
}

int query(int left, int right) {
    return sum(right) - sum(left - 1);
}

int main() {
    tree.resize(n + 1);
    init();
}