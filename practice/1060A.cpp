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
    int n,k; cin >> n >> k;
    string s; cin >> s;

    int count=0;
    int idx=-1e9;
    for (int i=0;i<n;i++){
        if (s[i]=='1'){
            if (i-idx >= k) count++;
            idx=i;
        }
    }

    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}