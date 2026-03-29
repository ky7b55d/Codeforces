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
    vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    int ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cur++;
        if (pos[i] < i) cur--;
        ans = max(ans, cur);
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