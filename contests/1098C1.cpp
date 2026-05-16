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
#include <climits>

using namespace std;
using ll = long long;

void solve() {
    ll a; int n;
    cin >> a >> n;
    int lo, hi;
    cin >> lo >> hi;

    string sa = to_string(a);
    int L = (int)sa.size();
    ll ans = LLONG_MAX;

    auto upd = [&](ll b) { ans = min(ans, abs(a - b)); };
    auto build = [](const string& s) -> ll {
        ll r = 0;
        for (char c : s) r = r * 10 + (c - '0');
        return r;
    };

    if (L > 1) {
        ll b = 0;
        for (int i = 0; i < L-1; i++) b = b*10 + hi;
        upd(b);
    }
    {
        string res(L+1, '0' + lo);
        if (lo == 0) res[0] = '0' + hi;
        upd(build(res));
    }

    // largest b <= a, same length
    {
        string res(L, '0');
        bool ok = true;
        vector<int> bt;
        for (int i = 0; i < L; i++) {
            int ai = sa[i] - '0';
            int pick;
            if (hi <= ai) pick = hi;
            else if (lo <= ai) pick = lo;
            else {
                ok = false;
                for (int k = (int)bt.size()-1; k >= 0; k--) {
                    int pos = bt[k];
                    if (pos == 0 && lo == 0 && L > 1) continue;
                    res[pos] = '0' + lo;
                    for (int j = pos+1; j < L; j++) res[j] = '0' + hi;
                    ok = true;
                    break;
                }
                break;
            }
            res[i] = '0' + pick;
            if (pick == hi) {
                if (hi < ai) { for (int j = i+1; j < L; j++) res[j] = '0' + hi; break; }
                else bt.push_back(i);
            } else {
                if (lo < ai) { for (int j = i+1; j < L; j++) res[j] = '0' + hi; break; }
            }
        }
        if (ok && (L == 1 || res[0] != '0')) upd(build(res));
    }

    // smallest b >= a, same length
    {
        string res(L, '0');
        bool ok = true;
        vector<int> bt;
        for (int i = 0; i < L; i++) {
            int ai = sa[i] - '0';
            bool force = (i == 0 && lo == 0 && L > 1);
            int pick = -1;
            if (!force && lo >= ai) pick = lo;
            else if (hi >= ai) pick = hi;
            if (pick == -1) {
                ok = false;
                for (int k = (int)bt.size()-1; k >= 0; k--) {
                    int pos = bt[k];
                    res[pos] = '0' + hi;
                    for (int j = pos+1; j < L; j++) res[j] = '0' + lo;
                    ok = true;
                    break;
                }
                break;
            }
            res[i] = '0' + pick;
            if (pick > ai) { for (int j = i+1; j < L; j++) res[j] = '0' + lo; break; }
            if (pick == lo && !force) bt.push_back(i);
        }
        if (ok && (L == 1 || res[0] != '0')) upd(build(res));
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