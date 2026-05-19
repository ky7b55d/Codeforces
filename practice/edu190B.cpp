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
    int ans=count(s.begin(),s.end(),'4');
    s.erase(remove(s.begin(), s.end(), '4'), s.end());

    while (true){
        string t;
        int add=0;
        for (int i=0;i<s.size();){
            if(i+1<s.size() && 
            ((s[i]=='1' && s[i+1]=='2') ||
             (s[i]=='3' && s[i+1]=='2'))){
                add++;
                i+=2;
            }
            else{
                t.push_back(s[i]);
                i++;
            }
        }
        if (add==0) break;
        ans+=add;
        s=t;
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