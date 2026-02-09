#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;
struct node {
    int l, r;
} q[N];
int n, x, y, cina, cinb;
vector<int> a, b;
bool cmp(node A, node B) { return A.l * A.r < B.l * B.r; }
namespace High {
void gjc(int x) {
    vector<int> te;
    int temp = 0;
    for (int i = 0; i < a.size(); i++) {
        temp += (a[i] * x);
        te.push_back(temp % 10);
        temp /= 10;
    }
    while (temp > 0) {
        te.push_back(temp % 10);
        temp /= 10;
    }
    a = te;
}
void gjch(int x) {
    vector<int> te;
    int r = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        r = r * 10 + a[i];
        te.push_back(r / x);
        r %= x;
    }
    reverse(te.begin(), te.end());
    while (!te.empty() && te.back() == 0) {
        te.pop_back();
    }
    if (te.size() > b.size())
        b = te;
    if (!te.empty() && te.size() == b.size()) {
        for (int i = te.size() - 1; i >= 0; i--) {
            if (te[i] > b[i]) {
                b = te;
                break;
            } else if (te[i] == b[i])
                continue;
            else if (te[i] < b[i])
                break;
        }
    }
}
} // namespace High
using namespace High;
signed main() {
    scanf("%lld", &n);
    scanf("%lld %lld", &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &cina, &cinb);
        q[i].l = cina;
        q[i].r = cinb;
    }
    sort(q + 1, q + 1 + n, cmp);
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    for (int i = 1; i <= n; i++) {
        gjch(q[i].r);
        gjc(q[i].l);
    }
    if (!b.empty()) {
        for (int i = b.size() - 1; i >= 0; i--) {
            printf("%lld", b[i]);
        }
    } else {
        printf("0");
    }
    return 0;
}