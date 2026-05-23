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
    for (int i=0;i<n;i++) cin >> a[i];

    vector<int> ans;
    int flip = 0;

    for (int i=n-1;i>=0;i--) {
        ll cur = flip ? -a[i] : a[i];
        if (cur > 0) {
            ans.push_back(i+1);
            flip ^= 1;
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}