#include <bits/stdc++.h>
#define ll long long
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
const double pi = 2.0 * acos(0.0);
// ok
using namespace std;
/// Code starts from here
int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  vector<int> dp(x + 1, 1e9);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    cin >> coins[i];
  }

  for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
      if(i - coins[j] >= 0){
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  if(dp[x] == 1e9) cout << -1 << endl;
  else cout << dp[x] << endl;
  
  return 0;
}