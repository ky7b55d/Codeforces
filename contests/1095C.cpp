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

bool ok(int k,multiset<int> s) {
    for(int need=k-1;need>=0;need--) {
        auto it=s.find(need);
        if(it!=s.end()) {
            s.erase(it);continue;
        }
        it=s.lower_bound(2*need+1);
        if(it==s.end()) return false;
        s.erase(it);
    }
    return true;
}

void solve() {
    int n; cin >> n;

    multiset<int> s;

    for(int i=0;i<n;i++) {
        int x;cin >> x;
        s.insert(x);
    }

    int left=0,right=n;
    while(left<right) {
        int mid=(left+right+1)/2;
        if(ok(mid,s))left=mid;
        else right=mid-1;
    }

    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--)solve();
    return 0;
}