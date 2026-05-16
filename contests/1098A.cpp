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

    int c0=0,c1=0,c2=0;

    for (int i=0;i<n;i++) {
        int x; cin >> x;
        if (x==0) c0++;
        else if (x==1) c1++;
        else c2++;
    }

    int ans=c0;

    int pairs=min(c1,c2);
    ans+=pairs;
    c1-=pairs;
    c2-=pairs;

    ans+=c1/3;
    ans+=c2/3;

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