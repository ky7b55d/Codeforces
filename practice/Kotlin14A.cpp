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
    int k; cin >> k;
    int a1,a2,b1,b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    if(a1+a2-b1-b2>k){
        cout << "NO\n";
    }
    else if(a1+a2-b1-b2==k && a1>b1 && a2>b2){
        cout << "NO\n";
    }
    else cout << "YES\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}