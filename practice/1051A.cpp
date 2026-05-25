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

    vector<int> p(n+1), pos(n+1);
    for (int i=1;i<=n;i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    int l = 1, r = n;

    for (int x=1;x<=n;x++) {
        if (pos[x] == l) {
            l++;
        } else if (pos[x] == r) {
            r--;
        } else {
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