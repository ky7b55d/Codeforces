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
    int n,k; cin >> n >> k;
    string s,z; cin >> s >> z;

    ll ca = 0,cb = 0,cc = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='1') ca++;
        if (z[i]=='1') cb++;
        if (s[i]!=z[i]) cc++;
    }

    auto val = [&](ll x) {
        return x * (n-x);
    };

    ll N = 1LL << k;
    vector<ll> cnt(3);
    for (int r=0;r<3;r++) {
        cnt[r] = N / 3;
        if (r <= N % 3) cnt[r]++;
    }

    ll ans = 0;
    if (k % 2 == 0) {
        ans += cnt[0] * val(ca);
        ans += cnt[1] * val(cb);
        ans += cnt[2] * val(cc);
    } else {
        ans += cnt[0] * val(ca);
        ans += cnt[1] * val(cc);
        ans += cnt[2] * val(cb);
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