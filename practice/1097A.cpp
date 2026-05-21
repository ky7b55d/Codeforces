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
    vector<ll> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    int ans=0;
    for (int i=n-2;i>=0;i--){
        a[i]=max(a[i],a[i]+a[i+1]);
        if (a[i]>0) ans++;
    }
    if (a[n-1]>0) cout << ans+1 << "\n";
    else cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}