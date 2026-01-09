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
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  vector<vector<int>> dp(n+1, vector<int>(x+1,0));
  for(int i = 0;i<n;i++){
    dp[i][0] = 1;
  }

  for (int j = n-1; j >= 0; j--)
  {
    for (int i = 1; i <= x; i++)
    {
      int picking = 0;
      if(i - coins[j] >= 0)
      {
        picking = dp[j][i - coins[j]];
      }
      dp[j][i] = (dp[j+1][i] + picking) % MOD;
    }
  }

  cout << dp[0][x] << endl;
  return 0;
}

// time complexity

// states * avg transition time
// O(x) * O(n) = O(n*x)

// space compelxity 
// States = O(nx) very huge

