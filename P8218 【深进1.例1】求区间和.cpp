#include <iostream>
#define int long long
using namespace std;
int a[100001], sum[100001];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int q, w;
        cin >> q >> w;
        cout << sum[w] - sum[q - 1] << endl;
    }
    return 0;
}
