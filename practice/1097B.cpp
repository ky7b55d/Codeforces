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

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    int M = *max_element(a.begin(),a.end());

    if (count(a.begin(),a.end(),0)==0){
        cout << 1LL*M*n << "\n";
        return;
    }

    vector<int> exist(n+2,0);

    for (int x:a){
        if (x<=n+1) exist[x]=1;
    }

    int miss=0;
    while (miss<=n+1 && exist[miss]) miss++;

    ll mexSum=0;

    if (miss==M+1){
        for (int x=0;x<M;x++){
            mexSum += x;
        }

        mexSum += 1LL*(n-M)*(M+1);
    }
    else{
        for (int x=0;x<miss;x++){
            mexSum += x;
        }

        mexSum += 1LL*(n-miss)*miss;
    }

    cout << 1LL*M*n + mexSum << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}