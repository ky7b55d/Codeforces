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
    int n;cin >> n;

    vector<int> a(n+1),b(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];

    vector<int> cid(n+1),pos(n+1);
    vector<bool> vis(n+1);
    vector<vector<int>> cyc;

    int m = 0;

    for (int i=1;i<=n;i++) {
        if (vis[i]) continue;

        vector<int> cur;
        int x = i;

        while (!vis[x]) {
            vis[x] = true;
            cid[x] = m;
            pos[x] = cur.size();
            cur.push_back(x);
            x = a[x];
        }

        cyc.push_back(cur);
        m++;
    }

    vector<int> to(m,-1),shift(m,-1);
    vector<bool> used(m);

    bool ok = true;

    for (int i=1;i<=n&&ok;i++) {
        if (b[i]==-1) continue;

        int u = cid[i];
        int v = cid[b[i]];

        if (cyc[u].size()!=cyc[v].size()) {
            ok = false;
            break;
        }

        int len = cyc[u].size();
        int s = (pos[b[i]]-pos[i]+len)%len;

        if (to[u]!=-1) {
            if (to[u]!=v||shift[u]!=s) {
                ok = false;
                break;
            }
        } else {
            if (used[v]) {
                ok = false;
                break;
            }

            to[u] = v;
            shift[u] = s;
            used[v] = true;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    map<int,int> src,tgt;

    for (int i=0;i<m;i++) {
        if (to[i]==-1) src[cyc[i].size()]++;
        if (!used[i]) tgt[cyc[i].size()]++;
    }

    for (auto [len,cnt] : src) {
        if (tgt[len]!=cnt) {
            cout << "NO\n";
            return;
        }
    }

    for (int u=0;u<m;u++) {
        if (to[u]==-1) continue;

        int v = to[u];
        int len = cyc[u].size();

        for (int i=0;i<len;i++) {
            b[cyc[u][i]] = cyc[v][(i+shift[u])%len];
        }
    }

    map<int,set<int>> avail;

    for (int i=0;i<m;i++) {
        if (used[i]) continue;

        int len = cyc[i].size();

        for (int x : cyc[i]) {
            avail[len].insert(x);
        }
    }

    for (int i=1;i<=n;i++) {
        if (b[i]!=-1) continue;

        int u = cid[i];
        int len = cyc[u].size();

        int x = *avail[len].begin();
        int v = cid[x];

        int s = (pos[x]-pos[i]+len)%len;

        for (int y : cyc[v]) {
            avail[len].erase(y);
        }

        for (int j=0;j<len;j++) {
            b[cyc[u][j]] = cyc[v][(j+s)%len];
        }
    }

    cout << "YES\n";
    for (int i=1;i<=n;i++) {
        cout << b[i] << " \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}