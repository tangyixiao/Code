#include <bits/stdc++.h>
using namespace std;

const int N = 105;
struct node {
    string id;
    int age, t;
} a[N];
int n;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].id >> a[i].age, a[i].t = i;
    }
    sort(a + 1, a + n + 1, [](node x, node y) {
        if ((x.age >= 60) != (y.age >= 60)) {
            return x.age >= 60;
        }
        if (x.age >= 60 && x.age != y.age) {
            return x.age > y.age;
        }
        return x.t < y.t;
    });
    for (int i = 1; i <= n; i++) {
        cout << a[i].id << "\n";
    }
    return 0;
}
