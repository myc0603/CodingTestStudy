#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    int start = 0;
    int end = input.find(delimiter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end-start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

void printVec(vector<string> v) {
    for (auto s: v) {
        cout << s << '\n';
    }
}

int main() {
    string s1 = "asdf,qwer,llkj";
    string s2 = " 123 asd ddd ";
    //s2 : 마지막에 start = end+1에서 end가 마지막 글자를 가리켜서 string::npos가 됨
    // 그래서 end도 string::npos가 되어서 while문 탈출하고
    // 마지막에 result에 push_back 될 때 input.substr(start)가 substr(string::npos)가 되어서 아무것도 추가가 안되는건가..?
    // If @a __pos is beyond the end of the string, out_of_range is thrown.
    vector<string> result1 = split(s1, ",");
    printVec(result1);
    cout << "=============";
    vector<string> result2 = split(s2, " ");
    printVec(result2);
    cout << '|' << s2.substr(string::npos) << '|';
    
    return 0;
}