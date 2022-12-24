// Grid Paths
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 1000, M = 1e9+7;
    int n;
    cin >> n;
    vector<vector<char>> a(mxN, vector<char> (mxN, ' '));
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        cin >> a[i][j]; 
      }
    }
    vector<vector<int>> dp(mxN, vector<int> (mxN, 0));
    dp[0][0] = 1;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(a[i][j] == '*') {
          dp[i][j] = 0;        
        } else {
          if (i) {
            dp[i][j] += dp[i-1][j] % M; 
          }
          if (j) {
            dp[i][j] += dp[i][j-1] % M;
          }
          dp[i][j] %= M;
        }
      }
    }
    cout << dp[n-1][n-1] << "\n";
    return 0;
}
