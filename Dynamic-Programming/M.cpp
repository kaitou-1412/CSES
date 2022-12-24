// Removal Game 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 5e3;
    int n;
    cin >> n;
    vector<int> x(mxN, 0);
    for(int i=0; i<n; i++) cin >> x[i];
    vector<vector<array<lli, 2>>> dp(mxN, vector<array<lli, 2>>(mxN, {0, 0}));
    for(int i=n-1; ~i; i--) { // i>=0
      for(int j=i; j<n; j++) {
        array<lli, 2> p;
        if(i == j) {
          p = {x[i], 0};
        } else {
          if(dp[i+1][j][1] + x[i] > dp[i][j-1][1] + x[j]) {
            p = {dp[i+1][j][1] + x[i], dp[i+1][j][0]};
          } else {
            p = {dp[i][j-1][1] + x[j], dp[i][j-1][0]};
          }
        }
        dp[i][j] = p;
      }
    }
    cout << dp[0][n-1][0] << "\n";
    return 0;
}
