#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(long long n) {
    if (n < 2)
        return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    long long N;
    cin >> N;
    if (N == 1) {
        cout << "N" << endl;
        return 0;
    }
    long long s = sqrt(N);
    if (s * s != N) {
        cout << "Y" << endl;
    } else {
        if (is_prime(s)) {
            cout << "N" << endl;
        } else {
            cout << "Y" << endl;
        }
    }
    return 0;
}