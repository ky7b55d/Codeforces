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

int cache_p[2005], cache_h[2005];

int invoke(int sz, const vector<int>& indices) {
    cout << "? " << sz;
    for (int idx : indices) cout << " " << idx;
    cout << endl;
    int feedback;
    if (!(cin >> feedback)||feedback==-1) exit(0);
    return feedback;
}

int get_p(int len) {
    if (len <= 0) return 0;
    if (cache_p[len]!=-1) return cache_p[len];
    vector<int> q(len);
    for (int i=0;i<len;i++) q[i]=i+1;
    return cache_p[len] = invoke(len, q);
}

int get_h(int len, int anchor) {
    if (len<=0) return 1;
    if (cache_h[len]!=-1) return cache_h[len];
    vector<int> q(len + 1);
    for (int i=0;i<len;i++) q[i]=i+1;
    q[len] = anchor;
    return cache_h[len] = invoke(len+1, q);
}

int check_state(int m, int ref) {
    int std_val = get_p(m);
    int aug_val = get_h(m, ref);
    int gap = aug_val-std_val;
    if (gap==1) return 0;
    return (gap==-1) ? 1 : 2;
}

void solve() {
    int limit;
    if (!(cin >> limit)) return;
    int range = 2*limit+1;

    for (int i=0;i<=range;i++) {
        cache_p[i] = cache_h[i]=-1;
    }

    int pos_c = range, low = 1, high = range;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (get_p(mid)%2 != mid%2) {
            pos_c = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    int pos_a = 1;
    low = 1, high = pos_c - 1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (check_state(mid, pos_c) >= 1) {
            pos_a = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    int pos_b = pos_c - 1;
    low = pos_a + 1, high = pos_c - 1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (check_state(mid, pos_c) >= 2) {
            pos_b = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << "! " << pos_a << " " << pos_b << " " << pos_c << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    if (!(cin >> cases)) return 0;
    while (cases--) {
        solve();
    }
    return 0;
}