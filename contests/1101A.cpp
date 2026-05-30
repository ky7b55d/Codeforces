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

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = n;

    for (int l = 0; l < n; ) {
        int r = l;
        while (r < n && a[r] == a[l]) r++;

        int left = l;
        int right = n - r;

        ans = min(ans, max(left, right));

        l = r;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}