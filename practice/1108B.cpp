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
    
    if(n==1) cout << 1 << "\n";return;
    if(n==2) cout << -1 << "\n";return;

    vector<ll> a={1,2,3};
    ll sum=6;

    while (a.size()<n){
        a.push_back(sum);
        sum*=2;
    }

    for (int i=0;i<n;i++){
        cout << a[i] << "\n"[i==n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}