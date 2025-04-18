#include <iostream>
#include <vector>
using namespace std;

int binary_search_v1(const vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (target == arr[mid]) return mid;
        if (target < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    
    return -1;
}

int binary_search_v2(const vector<int> &arr, int target) {
    // arr[left] < target -> 처음에 arr[0] < target인지 확인
    // arr[right] >= target
    int left = -1;
    int right = arr.size();

    while (left + 1 < right) {
        int mid = (left + right) / 2;
        
        if (target == arr[mid]) return mid;
        if (arr[mid] < target) left = mid;
        else right = mid;
    }

    if (arr[right] == target) return right;
    return -1;
}

// ㄴ다시 해보자
int binary_search_v3(const vector<int> &arr, int target) {
    
}

// target을 찾는게 아니라 target보다 크거나 같은 인덱스 중 가장 작은 값을 찾는 것
int LowerBound(const vector<int> &arr, int target) {
    int left = -1;
    int right = arr.size();
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= target) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
}