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

const int MOD = 998244353;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick() {}

    Fenwick(int n) {
        this->n = n;
        bit.assign(n+1,0);
    }

    void add(int i,int v) {
        for (;i<=n;i+=i&-i) {
            bit[i] += v;
            if (bit[i] >= MOD) bit[i] -= MOD;
        }
    }


    int query(int l,int r) {
        if (l > r) return 0;
        int res = sum(r) - sum(l-1);
        if (res < 0) res += MOD;
        return res;
    }

    int sum(int i) {
        int res = 0;
        for (;i>0;i-=i&-i) {
            res += bit[i];
            if (res >= MOD) res -= MOD;
        }
        return res;
    }
};

struct Fenwick2D {
    int n;
    vector<vector<int>> ys, bit;

    Fenwick2D() {}

    Fenwick2D(int n, vector<int>& tin) {
        this->n = n;
        ys.assign(n+1,{});
        bit.assign(n+1,{});

        for (int x=1;x<=n;x++) {
            for (int i=x;i<=n;i+=i&-i) {
                ys[i].push_back(tin[x]);
            }
        }

        for (int i=1;i<=n;i++) {
            sort(ys[i].begin(),ys[i].end());
            ys[i].erase(unique(ys[i].begin(),ys[i].end()),ys[i].end());
            bit[i].assign((int)ys[i].size()+1,0);
        }
    }

    void addOne(int idx,int pos,int val) {
        int p = lower_bound(ys[idx].begin(),ys[idx].end(),pos) - ys[idx].begin() + 1;
        for (;p<(int)bit[idx].size();p+=p&-p) {
            bit[idx][p] += val;
            if (bit[idx][p] >= MOD) bit[idx][p] -= MOD;
        }
    }



    int sumOne(int idx,int pos) {
        int p = upper_bound(ys[idx].begin(),ys[idx].end(),pos) - ys[idx].begin();
        int res = 0;
        for (;p>0;p-=p&-p) {
            res += bit[idx][p];
            if (res >= MOD) res -= MOD;
        }
        return res;
    }

    int pref(int x,int l,int r) {
        if (x <= 0) return 0;
        int res = 0;
        for (int i=x;i>0;i-=i&-i) {
            int cur = sumOne(i,r) - sumOne(i,l-1);
            if (cur < 0) cur += MOD;
            res += cur;
            if (res >= MOD) res -= MOD;
        }
        return res;
    }

    void add(int x,int pos,int val) {
        for (int i=x;i<=n;i+=i&-i) {
            addOne(i,pos,val);
        }
    }

    int query(int l,int r,int ql,int qr) {
        if (l > r || ql > qr) return 0;
        int res = pref(r,ql,qr) - pref(l-1,ql,qr);
        if (res < 0) res += MOD;
        return res;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s = 1;
    for (int i=1;i<=n;i++) {
        if ((int)g[i].size() == 1) s = max(s,i);
    }

    if (s == n) {
        cout << 1 << '\n';
        return;
    }

    vector<int> par(n+1,0), order;
    order.reserve(n);
    par[n] = -1;
    order.push_back(n);

    for (int i=0;i<(int)order.size();i++) {
        int v = order[i];
        for (int to : g[v]) {
            if (to == par[v]) continue;
            par[to] = v;
            order.push_back(to);
        }
    }

    vector<vector<int>> child(n+1);
    vector<int> tin(n+1), tout(n+1), mx(n+1), it(n+1,0);
    int timer = 0;

    stack<int> st;
    st.push(n);

    while (!st.empty()) {
        int v = st.top();
        if (!it[v]) tin[v] = ++timer;

        if (it[v] == (int)g[v].size()) {
            tout[v] = timer;
            st.pop();
            continue;
        }

        int to = g[v][it[v]++];
        if (to == par[v]) continue;
        st.push(to);
    }

    for (int i=n-1;i>=0;i--) {
        int v = order[i];
        mx[v] = v;
        for (int to : g[v]) {
            if (par[to] == v) {
                child[v].push_back(to);
                mx[v] = max(mx[v],mx[to]);
            }
        }
    }

    Fenwick all(n);
    Fenwick2D sub(n,tin);
    vector<int> dp(n+1,0);

    for (int y=1;y<n;y++) {
        int need = 1;
        for (int c : child[y]) need = max(need,mx[c]);

        int val = all.query(need,y-1);
        int bad = sub.query(need,y-1,tin[y],tout[y]);

        val -= bad;
        if (val < 0) val += MOD;

        if (y == s) {
            val++;
            if (val >= MOD) val -= MOD;
        }

        dp[y] = val;
        all.add(y,dp[y]);
        sub.add(y,tin[y],dp[y]);
    }

    vector<int> roots;
    for (int c : child[n]) roots.push_back(mx[c]);

    int ans = 0;

    for (int c : child[n]) {
        int need = 1;
        for (int x : roots) {
            if (x != mx[c]) need = max(need,x);
        }

        int cur = sub.query(need,n-1,tin[c],tout[c]);
        ans += cur;
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}