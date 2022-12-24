// Dice Combinations
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    const int mxN = 1e6, M = 1e9+7;
    int n;
    cin >> n;
    vector<lli> ways(mxN+1, 0);
    ways[0] = 1;
    for(int i=0; i<=n; i++) {
      for(int j=1; j<=6; j++) {
        // ways[i] = (ways[i] + ways[i-j])%M;
        ways[i+j] = (ways[i+j] + ways[i])%M;
      }
    }
    cout << ways[n] << "\n";
    return 0;
}
