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
    for (int i=0;i<n;i++) cin >> arr[i];

    vector<int> newarr;
    for (int i=0;i<n;i++){
        if (count(newarr.begin(),newarr.end(),arr[i])==0){
            newarr.push_back(arr[i]);
        }
    }
    int counts=newarr.size();

    if (count(newarr.begin(),newarr.end(),counts)!=0){
        cout << counts << "\n";
    }
    else{
        sort(newarr.begin(),newarr.end());
        cout << *upper_bound(newarr.begin(),newarr.end(),counts) << '\n';
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