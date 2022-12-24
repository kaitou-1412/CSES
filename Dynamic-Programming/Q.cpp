// Elevator Rides 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

bool anyLeft(vector<lli> mark, int n) {
  for(int i=0; i<n; i++) {
    if(mark[i] == 0) {
      return true;
    }
  }
  return false;
}

int main()
{
    fastio;
    const int mxN = 20;
    int n, x;
    cin >> n >> x;
    vector<lli> w(mxN, 0);
    for(int i=0; i<n; i++) cin >> w[i];
    int limit = 1 << n;
    vector<array<lli, 2>> dp(limit, array<lli, 2>({0, 0})); // {number of elevators, weight of the last elevator}    
    dp[0] = {1, 0};
    for(int mask=1; mask<limit; mask++) {
      array<lli, 2> bestResult = {INT_MAX, INT_MAX};
      for(int i=0; i<n; i++) {
        if(((1<<i) & mask) == 0) continue;
        auto res = dp[(1<<i)^mask];
        if(res[1] + w[i] <= x) {
          res[1] += w[i];
        } else {
          res[0]++;
          res[1] = w[i];
        }
        bestResult = min(bestResult, res);
      }
      dp[mask] = bestResult;
    }
    cout << dp[limit-1][0] << "\n";
    return 0;
}
