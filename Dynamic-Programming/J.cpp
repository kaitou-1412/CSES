// Edit Distance 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 5000, mxM = 5000;
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(mxN+1, vector<int>(mxM+1, 0));
    for(int i=1; i<=mxN; i++) dp[i][0] = i;
    for(int j=1; j<=mxM; j++) dp[0][j] = j;
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        if(a[i-1] == b[j-1]) {
          dp[i][j] = dp[i-1][j-1];
        } else {
          dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
      }
    } 
    cout << dp[n][m] << "\n";
    return 0;
}
