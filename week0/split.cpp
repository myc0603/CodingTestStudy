#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos) {
        string substring = input.substr(start, end-start);
        start = end + delimiter.size();
        end = input.find(delimiter, end + delimiter.size());
        result.push_back(substring);
    }
    return result;
}

void printVec(const vector<string> &v) {
    cout << "size of vector: " << v.size() << "\n[";
    for (auto s: v) {
        cout << s << ' ';
    }
    cout << "\b]\n";
}

int main() {
    vector<string> vec;
    vec.push_back("asdf");
    vec.push_back("qwe");
    vec.push_back("123");
    vec.push_back("zxc");

    printVec(vec);

    string s1 = "a,b,c,d,e";
    printVec(split(s1, ","));

    string s2 = "aa bb cc dd ";
    printVec(split(s2, " "));
}