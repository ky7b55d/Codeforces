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
    ll n,m; cin >> n >> m;
    vector<ll> a(m);
    for (int i=0;i<m;i++) cin >> a[i];
    vector<ll> newa;
    newa=a;
    sort(newa.begin(),newa.end());

    if (a[0]==1 && a[1]==1){
        cout << 1 << "\n";
    }
    else if (newa!=a) cout << 1 << "\n";
    else cout << (n-a[m-1]+1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}