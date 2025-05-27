#include<bits/stdc++.h>
#define endl '\n'
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    string a,b;
    cin >> n >> a >> b;
    int cnt = 0;
    for(int i = 0;i < n;++i){
        cnt++;
        if(i == 0) continue;
        if(a[i] == '.' && a[i - 1] == '/' && a[i + 1] == '\\') {
            cnt--;
            if(cnt == 8){
                cout << 'W';
            } 
            else if(cnt == 4) cout << 'V';
            cnt = 0;
        }
    }
    if(cnt == 8) cout << 'W';
    else if(cnt == 4) cout << 'V';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}