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
const ll MOD=676767677;

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    ll ans=0;
    int last=-1;

    for(int i=0;i<n;i++)
        if(a[i]>1) {
            ans+=a[i];
            last=i;
        }
    if(last==-1) {
        cout << 1 << "\n";
        return;
    }

    bool extra=false;
    for(int i=last+1;i<n;i++)
        if(a[i]==1) extra=true;

    if(extra) ans++;

    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}