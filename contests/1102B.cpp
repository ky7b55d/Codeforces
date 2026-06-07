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
    ll n; cin >> n;

    if (n == 10) {
        cout << -1 << "\n";
        return;
    }

    ll r = n%12;
    ll a;

    if (r<=9) a=r;
    else if (r==10) a=22;
    else a=11;

    cout << a << " " << n - a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}