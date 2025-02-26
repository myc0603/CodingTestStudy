#include <bits/stdc++.h>
using namespace std;

class Person {
    public:
        int x;
        int y;
        int r;

};
double distance(int x, int y) {
    return sqrt(x*x+y*y);
}
int possiblePosNum(int r1, int r2, double dis) {
    int rplus = r1 + r2;
    int rminus = abs(r1-r2);
    printf("dis: %lf, r1: %d, r2: %d\n", dis, r1, r2);
    if (dis == 0 && rminus == 0) return -1;
    if (dis > rplus) return 0;
    if (dis == (double) rplus) return 1;
    if (rminus < dis && dis < rplus) return 2;
    if (dis == (double) rminus) return 1;
    if (dis < rminus) return 0;
}
int main() {
    int T; 
    cin >> T;
    Person jo, baek;

    for (int i = 0; i < T; i++) {
        cin >> jo.x >> jo.y >> jo.r;
        cin >> baek.x >> baek.y >> baek.r;
        printf("%d %d %d %d %d %d", jo.x, jo.y, jo.r, baek.x, baek.y, baek.r);
        double dis = distance(jo.x-baek.x, jo.y-baek.y);
        
        cout << possiblePosNum(jo.r, baek.r, dis) << '\n';
    }

    return 0;
}