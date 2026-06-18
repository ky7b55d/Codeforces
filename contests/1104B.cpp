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
    int n;cin >> n;
    vector<ll> a(n),b(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];

    vector<int> L(n);
    for (int i=0;i<n;i++) {
        L[i] = lower_bound(b.begin(),b.end(),a[i])-b.begin();
        if (L[i]==n) {
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> used(n,0),p;
    for (int j=0;j<n;j++) {
        int best = -1;
        for (int i=0;i<n;i++) {
            if (!used[i]&&L[i]<=j) {
                best = i;
                break;
            }
        }

        if (best==-1) {
            cout << -1 << '\n';
            return;
        }
        
        used[best] = 1;
        p.push_back(best);
    }

    ll ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (p[i]>p[j]) ans++;
        }
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