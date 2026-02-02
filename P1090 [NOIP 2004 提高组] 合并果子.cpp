#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> q;
long long n, x, now1, now2, ans;
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        q.push(x);
    }
    while (q.size() != 1) {
        now1 = q.top();
        q.pop();
        now2 = q.top();
        q.pop();
        q.push(now1 + now2);
        ans += (now1 + now2);
    }
    printf("%lld", ans);
    return 0;
}