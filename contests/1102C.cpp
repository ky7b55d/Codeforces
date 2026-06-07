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
    int n; cin >> n;
    vector<ll> h(n);
    for (int i=0;i<n;i++) cin >> h[i];

    vector<ll> ans(n);
    for (int l=0;l<n;l++) {
        vector<ll> cw(n),ccw(n);

        ll mx = 0;
        for (int step=1;step<n;step++) {
            int e = (l + step - 1) % n;
            int v = (l + step) % n;
            mx = max(mx,h[e]);
            cw[v] = mx;
        }

        mx = 0;
        for (int step=1;step<n;step++) {
            int v = (l - step + n) % n;
            mx = max(mx, h[v]);
            ccw[v] = mx;
        }

        ll sum = 0;
        for (int j=0;j<n;j++) {
            if (j==l) continue;
            sum += min(cw[j],ccw[j]);
        }
        ans[l] = sum;
    }
    for (int i=0;i<n;i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}