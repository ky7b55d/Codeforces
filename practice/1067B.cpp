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
    
    vector<int> cnt(2*n+1);
    for (int i=0;i<2*n;i++){
        int x; cin >> x;
        cnt[x]++;
    }

    int odd=0,even=0;
    for (int x=1;x<=2*n;x++){
        if (cnt[x]==0) continue;
        if (cnt[x]%2==1) odd++;
        else even++;
    }
    
    int ans;
    if (odd>0) {ans=odd+2*even;}
    else{
        int take=even;
        if (take%2 != n%2) take-=1;
        ans = 2*take;
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