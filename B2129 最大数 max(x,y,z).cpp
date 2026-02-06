#include <bits/stdc++.h>
using namespace std;
double x, y, z;
int main() {
    cin >> x >> y >> z;
    double res = (max(max(x, y), z)) / ((max(x + y, max(y, z))) * (max(x, max(y, y + z))));
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}