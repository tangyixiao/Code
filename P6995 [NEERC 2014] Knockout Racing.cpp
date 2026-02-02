#include <bits/stdc++.h>
using namespace std;
int l[1005], r[1005];
int main() {
    int n, m, x, y, t, dis, pos, tpos, cnt;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> t;
        cnt = 0;
        for (int j = 0; j < n; j++) {
            dis = r[j] - l[j];
            tpos = t % (2 * dis);
            if (tpos > dis)
                pos = 2 * dis - tpos;
            else
                pos = tpos;
            pos += l[j];
            if (pos >= x && pos <= y)
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
