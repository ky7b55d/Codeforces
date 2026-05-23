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

struct Seg {
    int n;
    vector<int> z,o,lz;

    Seg(vector<int>& v) {
        n = (int)v.size() - 1;
        z.assign(4*n+5,0);
        o.assign(4*n+5,0);
        lz.assign(4*n+5,0);
        build(1,1,n,v);
    }

    void build(int p,int l,int r,vector<int>& v) {
        if (l == r) {
            if (v[l] == 0) z[p] = 1;
            else if (v[l] == 1) o[p] = 1;
            return;
        }
        int m = (l+r)/2;
        build(p*2,l,m,v);
        build(p*2+1,m+1,r,v);
        pull(p);
    }



    void apply(int p) {
        swap(z[p],o[p]);
        lz[p] ^= 1;
    }

    void pull(int p) {
        z[p] = z[p*2] + z[p*2+1];
        o[p] = o[p*2] + o[p*2+1];
    }

    void push(int p) {
        if (!lz[p]) return;
        apply(p*2);
        apply(p*2+1);
        lz[p] = 0;
    }

    
    void erase(int p,int l,int r,int x) {
        if (l == r) {
            z[p] = o[p] = 0;
            lz[p] = 0;
            return;
        }
        push(p);
        int m = (l+r)/2;
        if (x <= m) erase(p*2,l,m,x);
        else erase(p*2+1,m+1,r,x);
        pull(p);
    }

    void flip(int p,int l,int r,int ql,int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(p);
            return;
        }
        push(p);
        int m = (l+r)/2;
        flip(p*2,l,m,ql,qr);
        flip(p*2+1,m+1,r,ql,qr);
        pull(p);
    }

    int findzero(int p,int l,int r) {
        if (z[p] == 0) return -1;
        if (l == r) return l;
        push(p);
        int m = (l+r)/2;
        if (z[p*2]) return findzero(p*2,l,m);
        return findzero(p*2+1,m+1,r);
    }


    void erase(int x) {
        erase(1,1,n,x);
    }

    int findzero() {
        return findzero(1,1,n);
    }

    void flip(int l,int r) {
        if (l <= r) flip(1,1,n,l,r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];

    ll pref = 0, best = 0;
    int r = -1;

    for (int i=1;i<=n;i++) {
        if (a[i] > 0) {
            ll gain = pref - 2*a[i];
            if (gain > best) {
                best = gain;
                r = i;
            }
        } else {
            pref += -2*a[i];
        }
    }

    if (r == -1) {
        cout << 0 << '\n' << '\n';
        return;
    }

    vector<int> p(r+2,0), need(r+1,-1), v(r+1,-1);
    for (int i=1;i<r;i++) p[i] = a[i] < 0;
    p[r] = 1;

    int cnt = 0;
    for (int i=1;i<=r;i++) {
        if (p[i] != p[i+1]) {
            need[i] = a[i] < 0;
            v[i] = need[i];
            cnt++;
        }
    }

    Seg seg(v);
    vector<int> ans;

    while ((int)ans.size() < cnt) {
        int x = seg.findzero();
        ans.push_back(x);
        seg.erase(x);
        seg.flip(1,x-1);
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}