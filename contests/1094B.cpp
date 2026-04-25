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
    int n, m;
    cin >> n >> m;

    vector<ll> odd,even;
    ll total = 0;

    for (int i=1;i<=n;i++) {
        ll x; cin >> x;
        total+=x;
        if (i%2 == 1) odd.push_back(x);
        else even.push_back(x);
    }

    int opOdd = 0,opEven = 0;
    for (int i=0;i<m;i++) {
        int x; cin >> x;
        if (x%2 == 1) opOdd++;
        else opEven++;
    }

    sort(odd.rbegin(),odd.rend());
    sort(even.rbegin(),even.rend());

    auto best =[&](vector<ll>&v,int k) {
        if (k==0) return 0LL;

        ll cur=0;
        ll res=-(1LL<<60);

        for (int i=0;i<(int)v.size()&&i<k;i++) {
            cur+=v[i];
            res=max(res,cur);
        }
        return res;
    };

    ll marked = best(odd,opOdd)+best(even,opEven);

    cout << total-marked << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}