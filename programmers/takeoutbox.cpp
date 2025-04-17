#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int total_height = (n + w - 1) / w;
    bool total_right = total_height & 1;
    int total_pos = (n - 1) % w + 1;

    int find_height = (num + w - 1) / w;
    bool find_right = find_height & 1;
    int find_pos = (num - 1) % w + 1;
    
    int answer = total_height - find_height;
    if (total_right == find_right && total_pos >= find_pos) answer++;
    else if (total_right != find_right && total_pos + find_pos > w) answer++;
    return answer;
}