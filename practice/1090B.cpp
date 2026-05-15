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
    vector<int> arr(7);
    for (int i=0;i<7;i++) cin >> arr[i];
    
    int ans=-1e9;
    for (int i=0;i<7;i++){
        int cur_sum=0;
        for (int j=0;j<7;j++){
            if(j==i) cur_sum+=arr[j];
            else cur_sum-=arr[j];
        }
        ans=max(ans,cur_sum);
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