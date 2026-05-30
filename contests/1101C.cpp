#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;

void solve() {
    int n, x, s; cin >> n >> x >> s;
    string u; cin >> u;
    
    vector<int> dp(x+1, -1);
    dp[0] = 0;
    
    for (char c:u) {
        vector<int> next_dp = dp;
        for (int j = 0; j <= x; ++j) {
            if (dp[j] == -1) continue;
            
            if (c=='I' || c=='A') {
                if (j < x) {
                    next_dp[j + 1] = max(next_dp[j+1], dp[j]+1);
                }
            }
            
            if (c=='E' || c=='A') {
                if (dp[j] < j*s) {
                    next_dp[j] = max(next_dp[j], dp[j]+1);
                }
            }
        }
        dp = next_dp;
    }
    
    int ans = 0;
    for (int j=0;j<=x;j++) {
        ans = max(ans,dp[j]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}