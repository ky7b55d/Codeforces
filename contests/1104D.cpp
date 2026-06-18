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
    int n;string s;cin >> n >> s;

    vector<ll> cnt(3,0);
    cnt[0] = 1;

    int cur = 0;
    ll ans = 0;

    for (int i=0;i<n;i++) {
        if (s[i]=='0') cur = (cur+1)%3;
        else cur = (cur+2)%3;

        ans += i+1-cnt[cur];
        cnt[cur]++;
    }

    ll bad = 0;
    int len = 1;

    for (int i=1;i<=n;i++) {
        if (i<n&&s[i]!=s[i-1]) {
            len++;
        } else {
            ll a = (len+1)/2;
            ll b = len/2;
            bad += a*(a+1)/2+b*(b+1)/2-len;
            len = 1;
        }
    }

    cout << ans-bad << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}