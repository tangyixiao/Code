#include <bits/stdc++.h>
using namespace std;
bool Isprime(int x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
        if (Isprime(i))
            sum++;
    cout << sum << endl;
    return 0;
}
