#include<bits/stdc++.h>
#define endl '\n'
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 65;
int n;
int mp[N][N][N],vis[N][N][N],score[N][N][N];
int dt[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

struct site{
    int x,y,z;
};
void init(){
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            int tmp;
            cin >> tmp;
            for(int k = 1;k <= n;++k){
                mp[i][j][k] = tmp & 1;
                tmp >>= 1;
            }
        }
    }
}
bool check(int x,int y,int z){
    if(x < 1 || x > n || y < 1 || y > n || z < 1 || z > n) return true;
    else return false;
}
void bfs(){
    vis[1][1][1] = 1;
    queue<site> q;
    q.push({1,1,1});
    while(!q.empty()){
        int x = q.front().x,y = q.front().y,z = q.front().z;
        q.pop();
        for(int i = 0;i < 6;++i){
            int tx = x + dt[i][0],ty = y + dt[i][1],tz = z + dt[i][2];
            if(tx == n && ty == n && tz == n){
                score[n][n][n] = score[x][y][z] + n * n * n;
                return;
            }
            if(check(tx,ty,tz)) continue;
            if(!mp[tx][ty][tz] && !vis[tx][ty][tz]) {
                q.push({tx,ty,tz});
                vis[tx][ty][tz] = 1;
                score[tx][ty][tz] = score[x][y][z] - 1;
            }
        }
    }
}
void solve() {
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
    memset(score,0,sizeof(score));
    cin >> n;
    init();
    bfs();
    if(score[n][n][n] == 0) cout << "IMPOSSIBLE" << endl;
    else cout << score[n][n][n] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}