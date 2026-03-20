#include <iostream>
using namespace std;

int main() {
    int type, n, m, p;
    cin >> type >> n >> m >> p;

    long long ans = 1;
    int start = n - 2 * m + 2;
    int end = n - m + 1;

    for (int i = start; i <= end; ++i) {
        ans = ans * i % p;
    }

    cout << ans << endl;
    return 0;
}