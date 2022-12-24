// Counting Towers 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 1e6, M = 1e9+7;
    // dp[i][0] -> ways to add 2*i squares such that last 2 squares are united
    // dp[i][1] -> ways to add 2*i squares such that last 2 squares are not united
    vector<vector<lli>> dp(mxN+1, vector<lli>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=1; i<mxN; i++) {
      dp[i+1][0] += 2*dp[i][0];
      dp[i+1][0] += dp[i][1];
      dp[i+1][1] += dp[i][0];
      dp[i+1][1] += 4*dp[i][1];
      dp[i+1][0] %= M;
      dp[i+1][1] %= M;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n; 
        lli ans = (dp[n][0] + dp[n][1]) % M; 
        cout << ans << "\n";
    }
    return 0;
}
