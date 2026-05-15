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
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    if(n==1){
        cout << 1 << "\n";
    }
    else{
        for (int i=0;i<n;i++){
            cout << 2;
            if (i!=n) cout << ' ';
        }
        cout << "\n";
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