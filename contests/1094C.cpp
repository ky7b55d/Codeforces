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
    int n;cin>>n;

    vector<ll> a(n),c(n);

    for(int i=0;i<n;i++)
        cin >> a[i],c[i]=a[i];

    sort(c.begin(),c.end());
    ll mid =c[n/2];

    vector<int> low(n+1),high(n+1);

    for(int i=0;i<n;i++)
        low[i+1] = low[i]+(a[i]<mid),
        high[i+1] = high[i]+(a[i]>mid);

    vector<int> dp(n+1,-1000000000);
    dp[0]=0;

    for(int r=1;r<=n;r++)
        for(int l=r-1;l>=0;l-=2) {
            if(dp[l]<0) continue;
            int len=r-l;
            int need= len/2;
            int lowCnt =low[r]-low[l];
            int highCnt =high[r]-high[l];

            if(lowCnt <= need && highCnt <= need)
                dp[r]=max(dp[r], dp[l]+1);
        }

    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}