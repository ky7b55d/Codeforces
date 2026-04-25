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
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    vector<ll> b;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    ll mid = b[n / 2];

    vector<int> small(n + 1), big(n + 1);

    for (int i = 1; i <= n; i++) {
        small[i] = small[i - 1] + (a[i] < mid);
        big[i] = big[i - 1] + (a[i] > mid);
    }

    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int len = i - j;

            if (len % 2 == 0) continue;
            if (dp[j] < 0) continue;

            int lcnt = small[i] - small[j];
            int gcnt = big[i] - big[j];

            if (lcnt <= len / 2 && gcnt <= len / 2) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}