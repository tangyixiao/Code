#include <bits/stdc++.h>
using namespace std;
int a, cnt = 1;
int main() {
    cin >> a;
    for (; a != 1; a /= 2, cnt++)
        ;
    cout << cnt;
    return 0;
}