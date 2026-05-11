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

bool can(string s,char first,char second){
    string compare;
    for (int i=0;i<s.size();i++){
        if(i%2==0) compare.push_back(first);
        else compare.push_back(second);
    }
    vector<int> counter(s.size(),0);
    for (int i=0;i<s.size();i++){
        if(s[i]!=compare[i]) counter[i]=1;
        else counter[i]=0;
    }
    int l=-1,r=-1;
    for (int i=0;i<counter.size();i++){
        if(counter[i]==1){
            if(l==-1) l=i;
            r=i;
        }
    }
    if(l==-1) return true;
    for (int i=l;i<=r;i++){
        if(counter[i]==0) return false;
    }
    return true;
}

void solve() {
    string s; cin >> s;
    if(can(s,'a','b') || can(s,'b','a')) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}