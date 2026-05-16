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
    ll n,x1,x2,k;
    cin >> n >> x1 >> x2 >> k;

    if (n<=3) {
        cout << 1 << "\n";
        return;
    }

    ll diff=abs(x1-x2);
    ll d=min(diff,n-diff);

    cout << d+k << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}