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

int n;
vector<int> a;
vector<array<int, 3>> moves;

bool dfs(int l, int r, int from, int to, int aux) {
    if (l > r) return true;

    int len = r - l + 1;
    if (a[r] > len - 1) return false;

    int prefLen = len - 1 - a[r];
    int prefL = l;
    int prefR = l + prefLen - 1;
    int sufL = prefR + 1;
    int sufR = r - 1;

    if (!dfs(prefL, prefR, from, aux, to)) return false;
    moves.push_back({r, from, to});
    if (!dfs(sufL, sufR, from, to, aux)) return false;
    if (!dfs(prefL, prefR, aux, to, from)) return false;

    return true;
}

void solve() {
    cin >> n;

    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    moves.clear();

    bool ok = dfs(1, n, 1, 3, 2);

    if (!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << moves.size() << '\n';
    for (auto [id, from, to] : moves) {
        cout << id << ' ' << from << ' ' << to << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}