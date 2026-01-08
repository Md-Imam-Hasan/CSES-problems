#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // Base case: 1 way to get sum 0 (use no dice)
    
    for (int i = 1; i <= n; i++) {
        // Try all dice faces 1 to 6
        for (int face = 1; face <= 6; face++) {
            if (i - face >= 0) {
                dp[i] = (dp[i] + dp[i - face]) % MOD;
            }
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}