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
    string s; cin >> s;
    vector<ll> query(q);
    for (int i=0;i<q;i++) cin >> query[i];

    bool hasB = false;
    for(char c : s) if(c == 'B') hasB = true;

    for(int i=0;i<q;i++) {
        ll a = query[i];
        if(!hasB) {
            cout << a << "\n";
        }
        else{
        ll ans = 0;
        int cur = 0;
        while(a > 0) {
            if(s[cur] == 'A') a--;
            else a /= 2;
            ans++;
            cur = (cur + 1) % n;
        }
        cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while (T--) solve();
    return 0;
}