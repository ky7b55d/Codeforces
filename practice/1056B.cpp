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

char dir(pair<int,int> a,pair<int,int> b){
        int x1=a.first, y1=a.second;
        int x2=b.first, y2=b.second;
        if (x2==x1+1) return 'D';
        if (x2==x1-1) return 'U';
        if (y2==y1+1) return 'R';
        return 'L';
}

void solve() {
    int n,k; cin >> n >> k;

    int total=n*n;
    int bad=total-k;
    if (bad==1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    vector<string> ans(n,string(n,'D'));
    if (bad==0){
        for (auto &row:ans) cout << row << "\n";
        return;
    }

    vector<pair<int,int>> cells;
    for (int i=0;i<n;i++){
        if (i%2==0){
            for (int j=0;j<n;j++){
                cells.push_back({i,j});
            }
        }
        else{
            for (int j=n-1;j>=0;j--){
                cells.push_back({i,j});
            }
        }
    }

    for (int i=0;i+1<bad;i++){
        auto a=cells[i];
        auto b=cells[i+1];
        ans[a.first][a.second]=dir(a,b);
    }
    auto last=cells[bad-1];
    auto prev=cells[bad-2];
    ans[last.first][last.second]=dir(last,prev);
    
    for (auto &row:ans){
        cout << row << "\n";
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