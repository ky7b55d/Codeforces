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
    int n;cin >> n;
    string a,b;cin >> a >> b;

    int zhil=0,brak=0;
    bool fine=true;

    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            if(a[i]=='(') zhil+=2;
            else zhil-=2;
            if(zhil<0) fine=false;
            if(zhil==0){
                if(brak%2) fine=false;
                brak=0;
            }
        }
        else{
            if(zhil==0) fine=false;
            brak++;
        }
    }
    if(zhil!=0||brak%2) fine=false;

    cout << (fine?"YES":"NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}