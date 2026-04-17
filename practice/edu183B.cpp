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

    if (k==n){
        cout << string(n,'-') << "\n";
        return;
    }
    
    int c0=0,c1=0,c2=0;
    for (char x:s){
        if (x=='0') c0++;
        else if (x=='1') c1++;
        else c2++;
    }

    string ans;
    for (int i=1;i<=n;i++){
        if (i<=c0 || i>n-c1) ans.push_back('-');
        else if (i>=c0+c2+1 && i<=n-c1-c2) ans.push_back('+');
        else ans.push_back('?');
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