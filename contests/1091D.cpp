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
    int n, k;
    if(!(cin >> n >> k)) return;
    vector<int> bits(n + 2, 0);
    for(int i=1;i<=n;i++) cin >> bits[i];
    vector<int> anchors(k);
    for(int i=0;i<k;i++) cin >> anchors[i];

    int target = bits[anchors[0]];
    vector<int> needs_flip(n + 2, 0);
    for(int i=1;i<=n;i++) {
        if(bits[i] != target) needs_flip[i] = 1;
    }

    vector<int> nodes;
    for(int i=1;i<=n+1;i++) {
        if(needs_flip[i]!=needs_flip[i-1]) {
            nodes.push_back(i);
        }
    }

    if(nodes.empty()) {
        cout << "0\n"; return;
    }

    vector<int> group_size(k + 1, 0);
    for(int v:nodes) {
        int g_idx = lower_bound(anchors.begin(),anchors.end(),v)-anchors.begin();
        group_size[g_idx]++;
    }

    int total_nodes = nodes.size();
    int max_density = 0;
    for(int count : group_size) {
        max_density=max(max_density,count);
    }

    int ans = max((total_nodes + 1) / 2, max_density);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while (T--) solve();
    return 0;
}