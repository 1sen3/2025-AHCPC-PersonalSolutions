#include<bits/stdc++.h>
#define endl '\n'
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int t,a,b,c,d;
    cin >> t >> a >> b >> c >> d;
    double p = (double) a / b;
    double pc = 1 - (double) c / 100;
    double pd = 1 + (double) d / 100;
    vector<double> dp(t + 1);
    dp[0] = 1;
    for(int i = 1;i <= t;++i){
        dp[i] = dp[i - 1] * p * pc + dp[i - 1] * (1 - p) * pd;
    }
    cout << dp[t];
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