#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, c, w;
    cin >> n >> k >> c >> w;

    vector<int> type(n + 1), x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> type[i] >> x[i];
    }

    double k1 = 1.0 - k / 100.0;
    double c1 = 1.0 + c / 100.0;

    vector<double> f(n + 2, 0.0);
    for (int i = n; i >= 1; --i) {
        double skip = f[i + 1];
        double do_it = 0.0;
        if (type[i] == 1) {
            do_it = x[i] + k1 * f[i + 1];
        } else {
            do_it = -x[i] + c1 * f[i + 1];
        }
        f[i] = max(skip, do_it);
    }

    double ans = w * f[1];
    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}