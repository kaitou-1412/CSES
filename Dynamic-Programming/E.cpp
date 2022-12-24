// Removing Digits
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

vector<int> get_vector(int n) {
    vector<int> res;
    while(n!=0) {
      res.push_back(n%10);
      n = n/10;
    }
    return res;
}

int main()
{
    fastio;
    const int mxN = 1e6;
    int n;
    cin >> n;
    vector<int> dp(mxN, 1e9);
    dp[0] = 0; 
    for(int i=0; i<=n; i++) {
        vector<int> nums = get_vector(i);
        for(int& num: nums) {
          if(num <= i) {
            dp[i] = min(dp[i], dp[i - num]+1);
          }
        }
    }    
    cout << dp[n] << "\n";
    return 0;
}
