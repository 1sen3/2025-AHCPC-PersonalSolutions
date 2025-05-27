#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    int total = n;
    for (int i = 0;i < n;++i) {
        dp[i][0] = dp[i][1] = 1; 
        for (int j = i - 1;j >= 0;--j) {
            if (a[j] > a[i]) {
                dp[i][0] = (dp[i][0] + dp[j][1]) % mod;
            } else if (a[j] < a[i]) {
                dp[i][1] = (dp[i][1] + dp[j][0]) % mod;
            }
        }
        total = (total + dp[i][0] - 1) % mod;
        total = (total + dp[i][1] - 1) % mod;
    }

    cout << total << endl;
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