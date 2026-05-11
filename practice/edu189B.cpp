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

bool can_ab(string s){
    string compare1;
    for (int i=0;i<s.size();i++){
        if(i%2==0) compare1.push_back('a');
        else compare1.push_back('b');
    }
    vector<int> counter1(s.size()+2,0);
    for (int i=0;i<s.size();i++){
        if(s[i]!=compare1[i]) counter1[i]=1;
        else counter1[i]=0;
    }
    int l=-1,r=-1;
    for (int i=0;i<counter1.size();i++){
        if(counter1[i]==1){
            if(l==-1) l=i;
            r=i;
        }
    }
    if(l==-1) return true;
    for (int i=l;i<=r;i++){
        if(counter1[i]==0) return false;
    }
    return true;
}

bool can_ba(string s){
    string compare2;
    for (int i=0;i<s.size();i++){
        if(i%2==0) compare2.push_back('b');
        else compare2.push_back('a');
    }
    vector<int> counter2(s.size()+2,0);
    for (int i=0;i<s.size();i++){
        if(s[i]!=compare2[i]) counter2[i]=1;
        else counter2[i]=0;
    }
    int l=-1,r=-1;
    for (int i=0;i<counter2.size();i++){
        if(counter2[i]==1){
            if(l==-1) l=i;
            r=i;
        }
    }
    if(l==-1) return true;
    for (int i=l;i<=r;i++){
        if(counter2[i]==0) return false;
    }
    return true;
}


void solve() {
    string s; cin >> s;
    if(can_ab(s) || can_ba(s)) cout << "YES\n";
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