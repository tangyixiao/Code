#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    cin >> n;
    int x=1;
    for(int i=1;i<=n-1;i++){
        x++;
        x*=2;
    }
    cout<<x;
    return 0;
}