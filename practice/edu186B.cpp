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

bool ok(int a, int b, int n){
        int white=0, black=0;
        for (int i=0;i<n;i++){
            if (i%2==0) white+=(1<<i);
            else black+=(1<<i);
        }
        return (white<=a && black<=b) || (white<=b && black<=a);
}

void solve() {
    int a,b; cin >> a >> b;
    int ans=0;
    for (int n=1; n<=30; n++){
        if (ok(a,b,n)) ans=n;
        else break;
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