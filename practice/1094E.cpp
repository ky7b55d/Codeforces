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
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    int ans=0,mask=0;

    for (int b=30;b>=0;b--){
        mask |= (1<<b);
        int want=ans|(1<<b);
        
        unordered_set<int> s;
        for (int x:a) s.insert(x & mask);

        bool ok=false;
        for (int x:a){
            int p = x & mask;
            if (s.count(p^want)){
                ok=true;
                break;
            }
        }
        if (ok) ans=want;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}