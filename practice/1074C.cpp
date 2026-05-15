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
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    int ans=1,cur=1;
    for (int i=0;i<a.size();i++){
        if(a[i]==a[i-1]+1) cur++;
        else cur=1;
        ans=max(ans,cur);
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