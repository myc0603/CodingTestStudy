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

vector<string> split1(const string& input, string delimiter);

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

    string s1 = "a,b,c,d,e"; // -> e가 안나옴
    printVec(split(s1, ","));
    printVec(split1(s1, ","));

    string s2 = "aa bb cc dd "; // 빈 문자열이 추가됨
    printVec(split(s2, " "));
    printVec(split1(s2, " "));

    string s3 = "qq, wer, poiasf, asdf;123, 00,aldsfj, asldfk aaa, z"; // -> 마지막 z가 안나옴
    printVec(split(s2, " "));
    printVec(split1(s3, ", "));

    // simple case
    string s4 = "asdf lkj;";
    int index = s4.find(" ");
    cout << "index: " << index << '\n';
    string sub1 = s4.substr(0, index);
    string sub2 = s4.substr(index + 1);
    // substr의 parameter가 하나면 뭐가 default가 되는거지? -> 크기가 default(remainder)가 되고 파라미터는 시작 위치 인덱스가 되는듯
    cout << sub1 << '\n' << sub2 << '\n';

}

vector<string> split1(const string& input, string delimiter) {
    vector<string> result;
    int start = 0;                      // position after the delimiter
    auto end = input.find(delimiter);   // position of the delimiter
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start)); // index: [start, end) -> size: end - start
        start = end + delimiter.size();
        end = input.find(delimiter, start); // 다음 delimiter는 start부터 다시 찾아보면 됨
    }
    // 마지막 string은 delimiter가 마지막에 없어서 추가가 안됨
    result.push_back(input.substr(start));
    return result;
}