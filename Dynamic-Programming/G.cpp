// Book Shop 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 1e3, mxX = 1e5;
    int n, x;
    cin >> n >> x;
    vector<int> h(mxN, 0), s(mxN, 0);
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++) cin >> s[i];
    vector<int> dp(mxX+mxN, 0);
    for(int i=0; i<n; i++) {
      for(int j=x; j>=h[i]; j--) {
        dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
      }
    }
    cout << dp[x] << "\n";
    return 0;
}
