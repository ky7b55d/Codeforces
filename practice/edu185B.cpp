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
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    ll sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
    }

    ll count=0;
    for (int i=0;i<n;i++){
        if (arr[i]>0) count++;
    }

    ll ans=min(count,sum-n+1);
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