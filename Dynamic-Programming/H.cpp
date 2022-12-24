// Array Description 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 1e5, mxM = 100, M = 1e9+7;
    int n, m;
    cin >> n >> m;
    vector<int> x(mxN, 0);
    vector<vector<lli>> dp(mxN, vector<lli>(mxM, 0));
    for(int i=0; i<n; i++) {
      cin >> x[i]; 
      --x[i];
    }
    for(int i=0; i<n; i++) { 
      if(i) {
        for(int j=0; j<m; j++) {
          dp[i][j] = dp[i-1][j];
          if(j) dp[i][j] += dp[i-1][j-1];
          if(j<m-1) dp[i][j] += dp[i-1][j+1];
          dp[i][j] %= M;
        }
      } else {
        for(int j=0; j<m; j++) {
          dp[0][j] = 1;
        }
      }
      if(~x[i]) {
        for(int j=0; j<m; j++) {
          if(j^x[i]) {
            dp[i][j] = 0;
          }
        }
      }
    }
    lli ans = 0;
    for(int j=0; j<m; j++) {
      ans += dp[n-1][j];
    }
    ans %= M;
    cout << ans << "\n";
    return 0;
}
