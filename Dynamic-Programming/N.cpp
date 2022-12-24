// Two Sets II 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 500, M = 1e9+7;
    int n;
    cin >> n;
    lli ans;
    if(n%4!=0 && (n+1)%4!=0) ans = 0;
    else {
      vector<lli> dp(mxN*(mxN+1)/2, 0);
      lli s = n*(n+1)/4;
      dp[0] = 1;
      for(int i=1; i<=n; i++) {
        for(int j=i*(i+1)/2; j>=i; j--) {
          dp[j] = (dp[j] + dp[j-i])%M;
        }
      }
      ans = dp[s]*((M+1)/2)%M;
    }
    cout << ans << "\n";
    return 0;
}
