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
    int n,l,r; cin >> n >> l >> r;

    vector<int> p(n+1), a(n+1);
    p[0]=0;
    for (int i=1;i<=n;i++){
        if (i==r) {p[i]=l-1;}
        else {p[i]=i;}
    }

    for (int i=1; i<=n;i++){
        a[i]=p[i]^p[i-1];
    }

    for (int i=1;i<=n;i++){
        cout << a[i] << " \n"[i==n];
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