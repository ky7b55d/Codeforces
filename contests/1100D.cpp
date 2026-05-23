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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int low = 1, high = 2 * n, ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int n2 = 0, b0 = 0;
        bool in_zero = false;
        
        for (int i = 0; i < n; i++) {
            int c = (a[i] >= mid) + (b[i] >= mid);
            if (c == 2) {
                n2++;
                in_zero = false;
            } else if (c == 0) {
                if (!in_zero) {
                    b0++;
                    in_zero = true;
                }
            }
        }
        
        if (n2 > b0) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
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