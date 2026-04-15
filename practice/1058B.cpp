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
    vector<ll> b(n+1);
    for (int i=1;i<=n;i++) cin >> b[i];

    vector<ll> a(n+1);
    int nextnum=1;

    for (int i=1;i<n+1;i++){
        ll gap=b[i]-b[i-1];
        ll lastpos=i-int(gap);

        if (lastpos==0){
            a[i]=nextnum;
            nextnum++;
        }
        else{
            a[i]=a[lastpos];
        }
    }

    for (int i=1;i<n+1;i++){
        cout << a[i] << (i==n? '\n':' ');
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