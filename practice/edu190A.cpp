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
    ll n,a,b; cin >> n >> a >> b;
    if(3*a<b) cout << a*n << "\n";
    else if(n%3==0) cout << n/3*b << "\n";
    else if(n%3==1){
        if (a<=b) cout << n/3*b+a << "\n";
        else cout << n/3*b+b << "\n";
    }
    else if(n%3==2){
        if (2*a<=b) cout << n/3*b+2*a << "\n";
        else cout << n/3*b+b << "\n";
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