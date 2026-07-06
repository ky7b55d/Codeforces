#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int k;
    cin >> k;
    
    int max_c = 0;
    int count_ge_2 = 0;
    
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        max_c = max(max_c, c);
        if (c >= 2) {
            count_ge_2++;
        }
    }
    
 
    if (max_c >= 3 || count_ge_2 >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}