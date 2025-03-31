#include <bits/stdc++.h>
using namespace std;

deque<int> split(string arr) {
    deque<int> result;
    if (arr.empty()) return result;

    int start = 0;
    int end = arr.find(",");
    while (end != string::npos) {
        string temp = arr.substr(start, end - start);
        result.push_back(atoi(temp.c_str()));
        start = end + 1;
        end = arr.find(",", start);
    }
    string temp = arr.substr(start);
    result.push_back(atoi(temp.c_str()));

    return result;
}

deque<int> split2(string arr) {
    deque<int> result;
    if (arr.empty()) return result;

    int num = 0;
    for (char c : arr) {
        if (c == ',') {
            result.push_back(num);
            num = 0;
            continue;
        }
        num = 10 * num + (c - '0');
    }
    result.push_back(num);

    return result;
}

string stringOf(deque<int> d, bool front) {
    string result = "[";
    int n = d.size();
    
    for (int i = 0; i < n; i++) {
        int num;
        if (front) {
            num = d.front();
            d.pop_front();
        } else {
            num = d.back();
            d.pop_back();
        }
        result += to_string(num);
        if (i != n-1) {
            result += ',';
        }
    }
    result += ']';

    return result;
}

int main() {
    int t; cin >> t;

    string ans;
    while (t--) {
        string command; cin >> command;
        int n; cin >> n;
        string arrString; cin >> arrString;

        // deque<int> deq = split(arrString.substr(1, arrString.size() - 2));
        deque<int> deq = split2(arrString.substr(1, arrString.size() - 2));

        string temp;
        bool front = true;
        bool error = false;
        for (char c : command) {
            if (c == 'R') front ^= 1;
            else if (c == 'D') {
                if (deq.empty()) {
                    error = true;
                    break;
                }
                if (front) deq.pop_front();
                else deq.pop_back();
            }
        }
        temp = error ? "error" : stringOf(deq, front);
        ans += temp + '\n';
    }
    cout << ans;
}