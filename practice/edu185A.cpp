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

    if (n==1) cout << 1 << "\n";
    else if (n==2) cout << 9 << "\n";
    else if (n==3) cout << 29 << "\n";
    else if (n==4) cout << 56 << "\n";
    else{
        int ans=5*(n*n-n-1);
        cout << ans << "\n";
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