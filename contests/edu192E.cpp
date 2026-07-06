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

inline int get_len(ll x) {
    if (x == 0) return 1;
    return 64 - __builtin_clzll(x);
}

void solve() {
    ll l, r;
    int n;
    cin >> l >> r >> n;

    vector<pair<ll, ll>> active;
    vector<ll> base_nodes;
    
    ll curr = l;
    while (curr <= r) {
        int k = 0;
        while (k < 30 && (curr & (1LL << k)) == 0 && curr + (1LL << (k + 1)) - 1 <= r) {
            k++;
        }
        base_nodes.push_back(curr);
        for (int j = 0; j < k; j++) {
            active.push_back({curr, curr | (1LL << j)});
        }
        curr += (1LL << k);
    }

    for (size_t i = 0; i < base_nodes.size(); ++i) {
        for (size_t j = i + 1; j < base_nodes.size(); ++j) {
            active.push_back({base_nodes[i], base_nodes[j]});
        }
    }

    string ans = "";
    ans.reserve(n);

    for (int i = 0; i < n; ++i) {
        vector<pair<ll, ll>> zero_pairs;
        for (const auto& p : active) {
            ll x = p.first;
            ll y = p.second;
            
            int Lx = get_len(x);
            int Ly = get_len(y);
            
            int bit_x = (x >> (Lx - 1 - (i % Lx))) & 1;
            int bit_y = (y >> (Ly - 1 - (i % Ly))) & 1;
            
            if ((bit_x & bit_y) == 0) {
                zero_pairs.push_back(p);
            }
        }
        
        if (!zero_pairs.empty()) {
            ans += '0';
            active = move(zero_pairs);
        } else {
            ans += '1';
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