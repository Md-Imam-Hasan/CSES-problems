#include <bits/stdc++.h>
#define ll long long
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
const double pi = 2.0 * acos(0.0);
const int MOD = 1e9 + 7;
// ok
using namespace std;
/// Code starts from here
int main()
{
  int n, x, y;
  cin >> n >> x;
  vector<int> coins(n);
  vector<int> dp(x + 1, 0);
  dp[0] = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
    if(coins[i]<=x) dp[coins[i]] = 1;
  }

  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i - coins[j] >= 0)
      {
        dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
      }
    }
  }

  cout << dp[x] << endl;
  return 0;
}

// time complexity

// states * avg transition time
// O(x) * O(n) = O(n*x)

// space compelxity 
// States = O(x)

