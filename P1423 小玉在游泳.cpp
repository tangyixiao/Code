#include <bits/stdc++.h>
using namespace std;
double x;
int main() {
    cin >> x;
    cout << ceil(log(1 - x / 100) / log(0.98));
    return 0;
}
