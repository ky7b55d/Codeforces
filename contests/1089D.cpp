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
#include <chrono>
#include <random>

using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const uint64_t RND_SHIFT = rng();

uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

uint64_t hash_tree(int u, int p, const vector<vector<int>>& adj) {
    uint64_t h = 1;
    for (int v : adj[u]) {
        if (v != p) h += splitmix64(hash_tree(v, u, adj) ^ RND_SHIFT);
    }
    return h;
}

vector<int> get_centroids(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> sz(n, 1), c;
    auto dfs = [&](auto& self, int u, int p) -> void {
        bool ok = true;
        for (int v : adj[u]) {
            if (v != p) {
                self(self, v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) ok = false;
            }
        }
        if (n - sz[u] > n / 2) ok = false;
        if (ok) c.push_back(u);
    };
    dfs(dfs, 0, -1);
    return c;
}

vector<vector<int>> build(const string& s) {
    int n = s.length() / 2 + 1;
    vector<vector<int>> adj(n);
    int cnt = 0;
    vector<int> st = {0};
    for (char c : s) {
        if (c == '(') {
            cnt++;
            adj[st.back()].push_back(cnt);
            adj[cnt].push_back(st.back());
            st.push_back(cnt);
        } else {
            st.pop_back();
        }
    }
    return adj;
}

int strip_brackets(string& s) {
    int d = 0;
    while (s.length() >= 2) {
        int bal = 0;
        bool enclosed = true;
        for (int i = 0; i < s.length() - 1; ++i) {
            bal += (s[i] == '(' ? 1 : -1);
            if (bal == 0) {
                enclosed = false;
                break;
            }
        }
        if (enclosed) {
            s = s.substr(1, s.length() - 2);
            d++;
        } else {
            break;
        }
    }
    return d;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    int d1 = strip_brackets(s);
    int d2 = strip_brackets(t);
    if (d1 != d2) {
        cout << "NO\n";
        return;
    }
    if (s.empty()) {
        cout << "YES\n";
        return;
    }
    
    auto adj1 = build(s);
    auto adj2 = build(t);
    auto c1 = get_centroids(adj1);
    auto c2 = get_centroids(adj2);
    
    bool ok = false;
    for (int u : c1) {
        for (int v : c2) {
            if (hash_tree(u, -1, adj1) == hash_tree(v, -1, adj2)) {
                ok = true;
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}