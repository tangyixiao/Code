// C++ 14编译

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll tl, tr, ans;

priority_queue<ll> fl;
priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<void, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>> fr;

int main() {
    scanf("%d%d", &n, &m), fl.emplace(-1e18), fr.emplace(1e18);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), tl -= m, tr += m;
        if (x < fl.top() + tl) {
            ans += fl.top() + tl - x, fr.emplace(fl.top() + tl - tr);
            fl.pop(), fl.emplace(x - tl), fl.emplace(x - tl);
        } else if (x > fr.top() + tr) {
            ans -= fr.top() + tr - x, fl.emplace(fr.top() + tr - tl);
            fr.pop(), fr.emplace(x - tr), fr.emplace(x - tr);
        } else
            fl.emplace(x - tl), fr.emplace(x - tr);
    }
    printf("%lld", ans);
}

/*
// 逆天代码 https://www.luogu.com.cn/discuss/1241264
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll tl, tr, ans;

priority_queue<ll> fl;
priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<priority_queue<void,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>,
greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>, vector<ll>, greater<ll>>,
vector<ll>, greater<ll>>, vector<ll>, greater<ll>> fr;

int main() {
    scanf("%d%d", &n, &m), fl.emplace(-1e18), fr.emplace(1e18);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), tl -= m, tr += m;
        if (x < fl.top() + tl) {
            ans += fl.top() + tl - x, fr.emplace(fl.top() + tl - tr);
            fl.pop(), fl.emplace(x - tl), fl.emplace(x - tl);
        } else if (x > fr.top() + tr) {
            ans -= fr.top() + tr - x, fl.emplace(fr.top() + tr - tl);
            fr.pop(), fr.emplace(x - tr), fr.emplace(x - tr);
        } else
            fl.emplace(x - tl), fr.emplace(x - tr);
    }
    printf("%lld", ans);
}

*/