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

map<ll,ll> p;
ll findp(ll x){
    if (!p.count(x)) return x;
    return p[x]=findp(p[x]);
}

void paint(ll x){
    p[x]=findp(x+1);
}

void solve() {
    int n,m; cin >> n >> m;
    string s; cin >> s;
    p.clear();

    for (int i=0;i<m;i++){
        ll x; cin >> x;
        paint(x);
    }

    ll current=1;
    for (int i=0;i<n;i++){
        if (s[i]=='A'){
            current++;
            paint(current);
        }
        else{
            paint(findp(current+1));
            current=findp(current+1);
        }
    }

    cout << p.size() << "\n";
    for (auto it=p.begin();it!=p.end();it++){
        if (it!=p.begin()) cout << ' ';
        cout << it->first;
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