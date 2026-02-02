#include <bits/stdc++.h>
using namespace std;
struct node {
    int d, w;
};
stack<node> s;
int n, ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1, d, w; i <= n; i++) {
        cin >> d >> w;
        while (!s.empty() && s.top().w >= w) {
            ans += (s.top().w != w);
            s.pop();
        }
        s.push({d, w});
    }
    cout << ans + s.size();
    return 0;
}