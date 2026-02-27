#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || j == 1 || j == n){
                cout << "+";
            }
            else{
                cout << "-";
            }
        }
        cout << "\n";
    }
    return 0;
}