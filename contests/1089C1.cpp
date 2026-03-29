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
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
    }

    vector<ll> g(n - 1);
    for (int i=0;i+1<n;i++) {
        g[i] = gcd(a[i], a[i + 1]);
    }

    int ans=0;
    for (int i=0;i<n;i++) {
        ll need;
        if (i==0) {
            need = g[0];
        } else if (i==(n-1)) {
            need = g[n - 2];
        } else {
            ll x= g[i - 1], y = g[i];
            need= x / gcd(x, y) * y;
        }
        if (need < a[i]) ans++;
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