// Projects 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(3, 0));
    for(int i=0; i<n; i++) cin >> p[i][1] >> p[i][0] >> p[i][2];
    lli ans = 0;
    sort(p.begin(), p.end());
    set<array<lli, 2>> dp;
    dp.insert({0, 0}); // end, price
    lli last_dp = 0;
    for(int i=0; i<n; i++) {
      auto it = dp.lower_bound({p[i][1]}); // check for project with end <= start (a[i][1])
      --it;
      last_dp = max(last_dp, (*it)[1]+p[i][2]);
      dp.insert({p[i][0], last_dp});
    } 
    ans = last_dp;
    cout << ans << "\n";
    return 0;
}
