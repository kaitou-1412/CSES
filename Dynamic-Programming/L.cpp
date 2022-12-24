// Money Sums 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 100, mxX = 1e5;
    int n;
    cin >> n;
    vector<int> x(mxN+1, 0);
    for(int i=0; i<n; i++) cin >> x[i];
    vector<int> dp(mxX+1, 0);
    dp[0] = 1;
    for(int j=0; j<n; j++) {
      for(int i=mxX; i; i--) { // i>0
        if(x[j]<=i) {
          dp[i] |= dp[i-x[j]];
        }
      }
    }
    vector<int> ans;
    for(int i=1; i<=mxX; i++) {
      if(dp[i]) {
        ans.push_back(i);
      }
    }
    cout << ans.size() << "\n";
    for(int a: ans) {
      cout << a << " ";
    }
    cout << "\n";
    return 0;
}
