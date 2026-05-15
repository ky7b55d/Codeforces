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
    int n,q; cin >> n >> q;
    vector<int> a(n+3),b(n+3),best(n+3),sum(n+3);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    for (int i=n;i>=1;i--){
        best[i]=max({a[i],b[i],best[i+1]});
    }

    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+best[i];
    }

    for (int i=0;i<q;i++){
        int l,r;
        ll ans=0;
        cin >> l >> r;
        cout << sum[r]-sum[l-1];
        if (i!=q-1) cout << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}