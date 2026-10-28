#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, top;
long long ms;
double cs;
long long sm[N];
double sc[N];
char op[5];

signed main() {
    cin >> ms >> cs;
    cin >> n;
    cout << fixed << setprecision(5);
    for (int i = 1; i <= n; i++) {
        cin >> op;
        if (op[0] == 'P') {
            long long v;
            double c;
            cin >> v >> c;
            top++;
            sm[top] = ms;
            sc[top] = cs;
            double nm = ms * cs + (double)v * c;
            ms = ms + v;
            cs = nm / ms;
        } else {
            if (top > 0) {
                ms = sm[top];
                cs = sc[top];
                top--;
            }
        }
        cout << ms << " " << cs << "\n";
    }
    return 0;
}
