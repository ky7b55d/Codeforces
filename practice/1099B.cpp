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

    vector<int> down;
    ll need = 1;

    for (int i=0;i+1<n;i++) {
        if (a[i] > a[i+1]) {
            down.push_back(i);
            need = max(need,a[i]-a[i+1]);
        }
    }

    if (down.empty()) {
        cout << "YES\n";
        return;
    }

    for (int i=0;i+1<(int)down.size();i++) {
        int l = down[i] + 1;
        int r = down[i+1] - 1;

        ll best = 0;
        for (int j=l;j<=r;j++) {
            best = max(best,a[j+1]-a[j]);
        }

        if (best < need) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}