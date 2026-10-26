#include <bits/stdc++.h>
using namespace std;

int n, x, s, cnt;
set<int> st;

signed main() {
    cin >> n;
    x = n;
    for (; st.count(x) == 0;) {
        st.insert(x);
        s = 0;
        for (; x > 0;) {
            s += (x % 10) * (x % 10);
            x /= 10;
        }
        x = s;
    }
    cout << st.size() << "\n";
    return 0;
}
