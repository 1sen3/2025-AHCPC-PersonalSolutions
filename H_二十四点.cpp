#include<bits/stdc++.h>
#define endl '\n'
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

double a[110];
bool flag;

void dfs(int size){
    if(size == 1){
        if(a[0] == 24) flag = 1;
        return;
    }
    for(int i = 0;i < size;++i){
        for(int j = 0;j < size;++j){
            if(i == j) continue;
            int x = a[i],y = a[j];
            a[j] = a[size - 1];
            a[i] = x + y;
            dfs(size - 1);
            a[i] = x - y;
            dfs(size - 1);
            a[i] = y - x;
            dfs(size - 1);
            a[i] = x * y;
            dfs(size - 1);
            a[i] = x;
            a[j] = y;
        }
    }
}

void solve() {
    flag = 0;
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    dfs(4);
    if (flag) {
        YES;
    } else {
        NO;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}