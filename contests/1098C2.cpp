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
    vector<int> d(n);
    for (int& x : d) cin >> x;

    const ll INF = 4000000000000000000LL;

    string sa = to_string(a);
    int L = (int)sa.size();
    ll ans = INF;

    auto upd = [&](ll b) {
        if (b < 0) return;
        ll diff = a > b ? a - b : b - a;
        ans = min(ans,diff);
    };

    auto toNum = [&](const string& s) -> ll {
        ll r = 0;
        for (char c : s) {
            int x = c - '0';
            if (r > (INF - x) / 10) return INF;
            r = r * 10 + x;
        }
        return r;
    };

    auto largest = [&](int len) -> ll {
        if (len <= 0) return -1;
        if (len == 1) return d.back();

        int first = -1;
        for (int i = n-1; i >= 0; i--) {
            if (d[i] > 0) {
                first = d[i];
                break;
            }
        }

        if (first < 0) return -1;

        string res(len, '0' + d.back());
        res[0] = '0' + first;
        return toNum(res);
    };

    auto smallest = [&](int len) -> ll {
        if (len <= 0) return -1;
        if (len == 1) return d[0];

        int first = -1;
        for (int i = 0; i < n; i++) {
            if (d[i] > 0) {
                first = d[i];
                break;
            }
        }

        if (first < 0) return -1;

        string res(len, '0' + d[0]);
        res[0] = '0' + first;
        return toNum(res);
    };

    auto greedyLE = [&]() -> ll {
        string res(L, '0');
        vector<pair<int,int>> tight;
        bool done = false;

        for (int i = 0; i < L && !done; i++) {
            int ai = sa[i] - '0';
            bool nlz = (i == 0 && L > 1);

            int best = -1;
            for (int j = n-1; j >= 0; j--) {
                if (nlz && d[j] == 0) continue;
                if (d[j] <= ai) {
                    best = j;
                    break;
                }
            }

            if (best < 0) {
                bool found = false;

                for (int k = (int)tight.size()-1; k >= 0 && !found; k--) {
                    int pos = tight[k].first;
                    int dj = tight[k].second;
                    bool nlz2 = (pos == 0 && L > 1);

                    for (int idx = dj-1; idx >= 0 && !found; idx--) {
                        if (nlz2 && d[idx] == 0) continue;

                        res[pos] = '0' + d[idx];
                        for (int p = pos+1; p < L; p++) {
                            res[p] = '0' + d.back();
                        }

                        found = true;
                        done = true;
                    }
                }

                if (!found) return -1;
            } else {
                res[i] = '0' + d[best];

                if (d[best] < ai) {
                    for (int p = i+1; p < L; p++) {
                        res[p] = '0' + d.back();
                    }
                    done = true;
                } else {
                    tight.push_back({i,best});
                }
            }
        }

        return toNum(res);
    };

    auto greedyGE = [&]() -> ll {
        string res(L, '0');
        vector<pair<int,int>> tight;
        bool done = false;

        for (int i = 0; i < L && !done; i++) {
            int ai = sa[i] - '0';
            bool nlz = (i == 0 && L > 1);

            int best = -1;
            for (int j = 0; j < n; j++) {
                if (nlz && d[j] == 0) continue;
                if (d[j] >= ai) {
                    best = j;
                    break;
                }
            }

            if (best < 0) {
                bool found = false;

                for (int k = (int)tight.size()-1; k >= 0 && !found; k--) {
                    int pos = tight[k].first;
                    int dj = tight[k].second;

                    for (int idx = dj+1; idx < n && !found; idx++) {
                        res[pos] = '0' + d[idx];
                        for (int p = pos+1; p < L; p++) {
                            res[p] = '0' + d[0];
                        }

                        found = true;
                        done = true;
                    }
                }

                if (!found) return -1;
            } else {
                res[i] = '0' + d[best];

                if (d[best] > ai) {
                    for (int p = i+1; p < L; p++) {
                        res[p] = '0' + d[0];
                    }
                    done = true;
                } else {
                    tight.push_back({i,best});
                }
            }
        }

        return toNum(res);
    };

    if (d[0] == 0) upd(0);

    if (L > 1) upd(largest(L-1));
    upd(smallest(L+1));
    upd(greedyLE());
    upd(greedyGE());

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