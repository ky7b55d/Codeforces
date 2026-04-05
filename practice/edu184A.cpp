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
    int n,a; cin >> n >> a;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    int lower=lower_bound(arr.begin(),arr.end(),a)-arr.begin();
    int greater=arr.end()-upper_bound(arr.begin(),arr.end(),a);

    if (lower>=greater) cout << a-1 << "\n";
    else cout << a+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
