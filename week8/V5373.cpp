#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

int n;
char cube[6][3][3], color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
unordered_map<char, int> face_map;
vector<char *> v;
vector<vector<char *>> rotatingVector = {
    {
        &cube[3][0][2], &cube[3][0][1], &cube[3][0][0],
        &cube[5][0][2], &cube[5][0][1], &cube[5][0][0],
        &cube[2][0][2], &cube[2][0][1], &cube[2][0][0],
        &cube[4][0][2], &cube[4][0][1], &cube[4][0][0]
    }, {
        &cube[2][2][0], &cube[2][2][1], &cube[2][2][2],
        &cube[5][2][0], &cube[5][2][1], &cube[5][2][2],
        &cube[3][2][0], &cube[3][2][1], &cube[3][2][2],
        &cube[4][2][0], &cube[4][2][1], &cube[4][2][2]
    }, {
        &cube[0][2][0], &cube[0][2][1], &cube[0][2][2],
        &cube[5][0][0], &cube[5][1][0], &cube[5][2][0],
        &cube[1][0][2], &cube[1][0][1], &cube[1][0][0],
        &cube[4][2][2], &cube[4][1][2], &cube[4][0][2]
    }, {
        &cube[0][0][2], &cube[0][0][1], &cube[0][0][0],
        &cube[4][0][0], &cube[4][1][0], &cube[4][2][0],
        &cube[1][2][0], &cube[1][2][1], &cube[1][2][2],
        &cube[5][2][2], &cube[5][1][2], &cube[5][0][2]
    }, {
        &cube[0][0][0], &cube[0][1][0], &cube[0][2][0],
        &cube[2][0][0], &cube[2][1][0], &cube[2][2][0],
        &cube[1][0][0], &cube[1][1][0], &cube[1][2][0],
        &cube[3][2][2], &cube[3][1][2], &cube[3][0][2]
    }, {
        &cube[0][2][2], &cube[0][1][2], &cube[0][0][2],
        &cube[3][0][0], &cube[3][1][0], &cube[3][2][0],
        &cube[1][2][2], &cube[1][1][2], &cube[1][0][2],
        &cube[2][2][2], &cube[2][1][2], &cube[2][0][2]
    }
};

void initMap() {
    face_map.insert( {'U', 0} );
    face_map.insert( {'D', 1} );
    face_map.insert( {'F', 2} );
    face_map.insert( {'B', 3} );
    face_map.insert( {'L', 4} );
    face_map.insert( {'R', 5} );
}

void initCube() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cube[i][j][k] = color[i];
            }
        }
    }
}

void doRotate(char dir) {
    vector<char> rv;
    for (auto ptr : v) rv.push_back(*ptr);
    rotate(rv.begin(), rv.begin() + rv.size() * (dir == '+' ? 3 : 1) / 4, rv.end());
    for (int i = 0; i < v.size(); ++i) *v[i] = rv[i];
}

void rotate(int face, char dir) {
    auto cit = &cube[face][0][0];
    v = {
        cit, cit + 1, cit + 2, cit + 5, cit + 8, cit + 7, cit + 6, cit + 3
    };
    doRotate(dir);

    v = rotatingVector[face];
    doRotate(dir);
}
void printCube(int print_cnt);
void test1();
void test2();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    initMap();
    int t; cin >> t;
    while (t--) {
        initCube();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            char face, dir;
            cin >> face >> dir;
            int faceIdx = face_map[face];
            rotate(faceIdx, dir);
        }
        printCube(1);
    }
}

void printCube(int print_cnt) {
    for (int k = 0; k < print_cnt; ++k) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << cube[k][i][j];
            }
            cout << '\n';
        }
    }
}
void test1() {
    char c = 'a';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cube[0][i][j] = c++;
        }
    }

    cout << "before rotate\n";
    printCube(1);

    rotate(0, '+');
    cout << "after rotate\n";
    printCube(1);
}
void test2() {
    initMap();

    initCube();
    cout << "before rotate\n";
    printCube(6);
    
    rotate(face_map['U'], '+');
    cout << "after rotate U\n";
    printCube(6);

    initCube();
    rotate(face_map['D'], '+');
    cout << "after rotate D\n";
    printCube(6);
    
    initCube();
    rotate(face_map['F'], '+');
    cout << "after rotate F\n";
    printCube(6);
    
    initCube();
    rotate(face_map['B'], '+');
    cout << "after rotate B\n";
    printCube(6);
    
    initCube();
    rotate(face_map['L'], '+');
    cout << "after rotate L\n";
    printCube(6);
    
    initCube();
    rotate(face_map['R'], '+');
    cout << "after rotate R\n";
    printCube(6);
}