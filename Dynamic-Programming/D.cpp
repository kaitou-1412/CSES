// Coin Combinations II
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 100, mxX = 1e6, M = 1e9+7;
    int n, x;
    cin >> n >> x;
    vector<int> coins(mxN, 0);
    for(int i=0; i<n; i++) cin >> coins[i];
    vector<lli> ways(2*mxX, 0);
    ways[0] = 1;
    for(int j=0; j<n; j++) {
      for(int i=0; i<=x; i++) {
          ways[i+coins[j]] = (ways[i+coins[j]] + ways[i]) % M;
      }
    }
    cout << ways[x] << "\n";

    return 0;
}
