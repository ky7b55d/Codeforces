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
    vector<ll> h(n);
    for (int i=0;i<n;i++) cin >> h[i];

    int idx = max_element(h.begin(),h.end()) - h.begin();

    vector<int> v(n);
    vector<ll> H(n - 1);

    for (int i=0;i<n;i++) v[i] = (idx + 1 + i) % n;
    for (int i=0;i<n-1;i++) H[i] = h[v[i]];

    vector<ll> L(n),R(n);
    stack<pair<ll,ll>> st;

    ll cur = 0;
    for (int i=0;i<n-1;i++) {
        ll cnt = 1;
        while (!st.empty() && st.top().first <= H[i]) {
            cnt += st.top().second;
            cur -= st.top().first * st.top().second;
            st.pop();
        }
        st.push({H[i],cnt});
        cur += H[i] * cnt;
        L[i + 1] = cur;
    }

    while (!st.empty()) st.pop();

    cur = 0;
    for (int i=n-2;i>=0;i--) {
        ll cnt = 1;
        while (!st.empty() && st.top().first <= H[i]) {
            cnt += st.top().second;
            cur -= st.top().first*st.top().second;
            st.pop();
        }
        st.push({H[i],cnt});
        cur += H[i] * cnt;
        R[i] = cur;
    }

    vector<ll> ans(n);
    for (int i=0;i<n;i++) ans[v[i]] = L[i] + R[i];


    
    for (int i=0;i<n;i++) cout << ans[i] << " ";
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