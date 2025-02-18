#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;    
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        cout << "m: " << m << '\n';
        map<string, int> wearMap;
        for (int j = 0; j < m; j++) {
            cout << "j: " << j << '\n';
            string wear;
            cin >> m;
            getline(cin, wear);
            wear = split(wear, " ")[1];
            wearMap[wear]++;
        }

        cout << "==========\n";
        for (auto it = wearMap.begin(); it != wearMap.end(); it++) {
            cout << it->first << " : " << it->second << '\n';
        }
        cout << "asdfkjl" << '\n';
    }
}