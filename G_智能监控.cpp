#include<bits/stdc++.h>
#define endl '\n'
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 5;
vector<int> children[N];
int color[N];

void operate1(int x){
    if(color[x] == 0) color[x] = 1;
    else{
        for(int c : children[x]){
            operate1(c);
        }
    }
}
void operate2(int x){
    color[x] = 0;
    for(int c : children[x]){
        operate2(c);
    }
}
void operate3(int x){
    cout << (color[x] ? "black" : "white") << '\n';
}
void solve() {
    int n,q;
    cin >> n >> q;
    for(int i = 2;i <= n;++i){
        int p;
        cin >> p;
        children[p].push_back(i);
    }
    while(q--){
        int opt,x;
        cin >> opt >> x;
        if(opt == 1){
            operate1(x);
        } else if(opt == 2){
            operate2(x);
        } else if(opt == 3){
            operate3(x);
        }
    }
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