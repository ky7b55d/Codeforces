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
    vector<ll> b(n);
    for (int i=0;i<n;i++) cin >> b[i];

    sort(b.rbegin(), b.rend());
    if (n == 2) {
        cout << b[0] << " " << b[1] << "\n";
        return;
    }

    bool ok = true;
    for (int i = 0; i + 2 < n; i++) {
        if (b[i] % b[i + 1] != b[i + 2]) {
            ok = false;
            break;
        }
    }
    if (ok) cout << b[0] << " " << b[1] << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}