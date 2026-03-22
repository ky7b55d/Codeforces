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
    string s; cin >> s;

    for (int mask=0;mask<(1<<n);mask++){
        string p="", x="";
        vector<int> idx;
        for (int i=0;i<n;i++){
            if (mask>>i&1){ p+=s[i]; idx.push_back(i+1); }
            else x+=s[i];
        }
        bool ndec=true;
        for (int i=1;i<(int)p.size();i++)
            if (p[i]<p[i-1]){ ndec=false; break; }
        string rx=x; reverse(rx.begin(),rx.end());
        if (ndec && x==rx){
            cout<<idx.size()<<"\n";
            for (int v:idx) cout<<v<<" ";
            cout<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}