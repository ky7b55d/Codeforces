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
    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<pair<ll,int>> v;
    ll s=0;

    for(int i=0;i<n;i++) {
        v.push_back({s,i});
        s+=a[i];
    }
    sort(v.begin(),v.end());

    vector<int> ans(n);
    for(int i=0;i<n;i++)
        ans[v[i].second]=n-i;
    for(int i=0;i<n;i++) {
        if(i) cout << " ";
        cout << ans[i];
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