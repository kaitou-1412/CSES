// Increasing Subsequence 
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++) {
      int a;
      cin >> a;
      int p = lower_bound(v.begin(), v.end(), a) - v.begin();
      if(p<(int)v.size())
        v[p] = a;
      else
        v.push_back(a);
    }    
    cout << v.size() << "\n";
    return 0;
}
