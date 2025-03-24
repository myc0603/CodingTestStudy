#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, h, a, b, ret = INF, visited[34][34];
bool check(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(visited[j][start])start++;
            else if(visited[j][start - 1])start--;
        }
        if(start != i) return false;
    }
    return true;
}
void go(int sx, int sy, int cnt){ 
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        cout << "is valid~!!\n";
        ret = min(ret, cnt); return;
    }

    int depth = cnt;
    string indent = "\n";
    while (depth--) indent += "   ";

    for(int j = 1; j < n; j++){
        // int i = j == sx ? sy : 1;
        int i = 1;
        for(; i <= h; i++){
            if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) {
                cout << indent << "count: " << cnt << ", i,j: " << i << ',' << j << " -> cannot add" << '\n';
                continue;
            }
            visited[i][j] = 1;
            cout << indent << "count: " << cnt << ", i,j: " << i << ',' << j << " -> add!!" << '\n';

            go(j, i, cnt + 1);
            visited[i][j] = 0;
            
            while(!visited[i][j] && !visited[i][j-1] && !visited[i][j+1]) i++;
            // i--;
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        cin >> a >> b; visited[a][b] = 1;
    }
    go(1, 1, 0);
    cout << ((ret == INF) ? -1 : ret) << "\n";
	return 0;
}
