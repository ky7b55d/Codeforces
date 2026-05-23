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
    vector<ll> a(n), b(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];

    ll ans = 0;
    ll best = 0;

    for (int i=0;i<n;i++) {
        ans += max(a[i], b[i]);
        best = max(best, min(a[i], b[i]));
    }

    cout << ans + best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}