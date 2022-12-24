// Rectangle Cutting 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxA = 500, mxB = 500;
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(mxA+1, vector<int>(mxB+1, 1e9));
    for(int i=1; i<=mxA; i++) dp[i][i] = 0;
    for(int i=1; i<=a; i++) {
      for(int j=1; j<=b; j++) {
        for(int cut=1; cut<i; cut++) 
          dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i-cut][j] + 1);
        for(int cut=1; cut<j; cut++) 
          dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j-cut] + 1);
      }
    } 
    cout << dp[a][b] << "\n";
    return 0;
}
