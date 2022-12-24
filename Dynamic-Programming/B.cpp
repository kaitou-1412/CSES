// Minimizing Coins
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 100, mxX = 1e6;
    int n, x;
    cin >> n >> x;
    vector<int> coins(mxN, 0);
    for(int i=0; i<n; i++) cin >> coins[i];
    vector<lli> dp(2*mxX, 1e9);
    dp[0] = 0;
    for(int i=0; i<x; i++) {
      for(int j=0; j<n; j++) {
          //dp[i] = min(dp[i], dp[i - coins[j]] + 1);
          dp[i+coins[j]] = min(dp[i+coins[j]], dp[i] + 1);
      }
    }
    if(dp[x] == 1e9) cout << "-1" << "\n";
    else cout << dp[x] << "\n";
    return 0;
}
