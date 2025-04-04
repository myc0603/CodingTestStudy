#include <iostream>
using namespace std;

const int CAPACITY = 10000;
int q[CAPACITY], idx, sizes;

void push(int x) {
    int i = (idx + sizes) % CAPACITY;
    q[i] = x;
    sizes++;
}

int pop() {
    if (sizes == 0) return -1;
    int i = idx;
    idx = (idx + 1) % CAPACITY;
    sizes--;
    return q[i];
}

int front() {
    if (sizes == 0) return -1;
    return q[idx];
}

int back() {
    if (sizes == 0) return -1;
    return q[(idx + sizes - 1) % CAPACITY];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string ans;
    while (n--) {
        string command; cin >> command;
        if (command == "push") {
            int x; cin >> x;
            push(x);
        } else if (command == "pop") {
            ans += to_string(pop()) + '\n';
        } else if (command == "size") {
            ans += to_string(sizes) + '\n';
        } else if (command == "empty") {
            ans += to_string(!sizes) + '\n';
        } else if (command == "front") {
            ans += to_string(front()) + '\n';
        } else if (command == "back") {
            ans += to_string(back()) + '\n';
        }        
    }
    cout << ans;
}