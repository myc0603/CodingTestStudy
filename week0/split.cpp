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
    result.push_back(input.substr(start)); // 마지막 꺼 추가
    return result;
}

void printVec(const vector<string> &v) {
    cout << "size of vector: " << v.size() << "\n[";
    for (auto s: v) {
        cout << s << '|';
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

    string s1 = "a,b,c,d,e"; // -> e가 안나옴옴
    printVec(split(s1, ","));

    string s2 = "aa bb cc dd "; // 빈 문자열이 추가됨
    printVec(split(s2, " "));

    string s3 = "qq, wer, poiasf, asdf;123, 00,aldsfj, asldfk aaa, z"; // -> 마지막 z가 안나옴옴
    printVec(split(s3, ", "));
}