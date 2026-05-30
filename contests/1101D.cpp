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
    int n, x, s; cin >> n >> x >> s;
    string u; cin >> u;

    ll tables=0,seat=0,flex=0,ans=0; 

    for (char c : u) {
        if (c == 'I') {
            if (tables < x) {
                tables++;
                seat+=(s - 1);
                ans++;
            }
        } 
        else if (c == 'E') {
            if (seat > 0) {
                seat--;
                ans++;
            } 
            else if (flex > 0 && tables < x) {
                flex--;
                tables++;
                seat+=(s - 1);
                ans++;
            }
        } 
        else {
            if (seat > 0) {
                seat--;
                flex++;
                ans++;
            } 
            else if (tables < x) {
                tables++;
                seat += s - 1;
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}