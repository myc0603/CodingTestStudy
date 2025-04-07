#include <iostream>
using namespace std;

bool paper[101][101];
int area;

int main() {
    int n; cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (!paper[y+i][x+j]) area++;
                paper[y+i][x+j] = 1;
            }
        }
    }

    cout << area;
}