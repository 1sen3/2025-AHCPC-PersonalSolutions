#include<bits/stdc++.h>
#define endl '\n'
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 5;

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}
void solve() {
    int n;
    cin >> n;
    int a[N],dp[N];
    int ans = 1;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        dp[i] = 1;
        for(int j = 1;j < i;++j){
            if(gcd(a[i],a[j]) > 1){
                dp[i] = max(dp[i],dp[j] + 1);
            }
            ans = max(ans,dp[i]);
        }
    }
    cout << ans << endl;
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