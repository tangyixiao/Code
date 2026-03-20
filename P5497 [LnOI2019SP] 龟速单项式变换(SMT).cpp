#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << "NO" << endl;
    } else if (n >= m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}