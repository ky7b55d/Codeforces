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
#include <climits>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> p(n);
    vector<int> ys;

    for (int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        p[i]={x,y};
        ys.push_back(y);
    }

    sort(p.begin(),p.end());

    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());

    vector<int> mn,mx;

    for (int i=0;i<n;) {
        int x=p[i].first;
        int low=INT_MAX,high=INT_MIN;

        while (i<n && p[i].first==x) {
            low=min(low,p[i].second);
            high=max(high,p[i].second);
            i++;
        }

        mn.push_back(low);
        mx.push_back(high);
    }

    int m=mn.size();

    if (m<2) {
        cout << 0 << "\n";
        return;
    }

    vector<int> prefMn(m),prefMx(m),sufMn(m),sufMx(m);

    for (int i=0;i<m;i++) {
        if (i==0) {
            prefMn[i]=mn[i];
            prefMx[i]=mx[i];
        } else {
            prefMn[i]=min(prefMn[i-1],mn[i]);
            prefMx[i]=max(prefMx[i-1],mx[i]);
        }
    }

    for (int i=m-1;i>=0;i--) {
        if (i==m-1) {
            sufMn[i]=mn[i];
            sufMx[i]=mx[i];
        } else {
            sufMn[i]=min(sufMn[i+1],mn[i]);
            sufMx[i]=max(sufMx[i+1],mx[i]);
        }
    }

    auto get_id = [&](int y) {
        return lower_bound(ys.begin(),ys.end(),y)-ys.begin();
    };

    ll ans=0;

    for (int cut=0;cut<m-1;cut++) {
        int minL=prefMn[cut];
        int maxL=prefMx[cut];

        int minR=sufMn[cut+1];
        int maxR=sufMx[cut+1];

        int A=max(minL,minR);
        int B=min(maxL,maxR);

        if (A<B) {
            ans += get_id(B)-get_id(A);
        }
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