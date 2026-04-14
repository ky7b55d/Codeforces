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
    ll p_pieces, q_pieces; cin >> p_pieces >> q_pieces;

    ll total_edge_count = p_pieces + 2*q_pieces;
    ll composite_target = 2*total_edge_count + 1;
    bool is_possible = false;

    for (ll factor_candidate=3;factor_candidate*factor_candidate<=composite_target;++factor_candidate) {
        if (composite_target%factor_candidate==0) {
            ll side_a = factor_candidate;
            ll side_b = composite_target/factor_candidate;

            if (side_b-side_a<=2*p_pieces) {
                ll rows = (side_a - 1)/2;
                ll cols = (side_b - 1)/2;
                cout << rows << " " << cols << "\n";
                is_possible = true;
                break;
            }
        }
    }

    if (!is_possible) {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}