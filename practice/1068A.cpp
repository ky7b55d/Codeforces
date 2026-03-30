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

    string t=s;
    for (int i=0; i<n; i++){
        if (s[i]='1'){
            for (int j=i;j<=min(n-1,i+k);j++){
                t[j]='2';
            }
        }
    }

    int ans=0;
    for (char c : t){
        if (c=='0') ans++;
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