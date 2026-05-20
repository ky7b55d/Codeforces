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
    string s; cin >> s;
    
    int right=0;
    for (char c:s){
        if (c=='1'||c=='3') right++;
    }
    int left=0;
    int best=right;

    for (char c:s){
        if (c=='1'||c=='3') right--;
        if (c=='2') left++;
        best=max(best,left+right);
    }
    cout << s.size()-best << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}