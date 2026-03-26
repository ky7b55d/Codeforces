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
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int firstOne;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            firstOne = i;
            break;
        }
    }

    string t = s.substr(firstOne) + s.substr(0, firstOne);

    int ans = 0, cur = 0;
    for (char c : t) {
        if (c == '0') {
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 0;
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