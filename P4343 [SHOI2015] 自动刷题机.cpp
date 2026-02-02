#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int l, k;
vector<ll> logs;

// 计算给定n时能切多少题
ll countAC(ll n) {
    ll lines = 0, cnt = 0;
    for (int i = 0; i < l; i++) {
        lines += logs[i];
        if (lines < 0)
            lines = 0;
        if (lines >= n) {
            cnt++;
            lines = 0; // 提交后重置
        }
    }
    return cnt;
}

int main() {
    cin >> l >> k;
    logs.resize(l);
    for (int i = 0; i < l; i++) {
        cin >> logs[i];
    }

    // 寻找最小n
    ll left = 1, right = 1e18; // 右边界设一个很大的数
    ll minN = -1, maxN = -1;

    // 二分最小n
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll cnt = countAC(mid);

        if (cnt > k) {
            left = mid + 1; // n太小，切题数太多
        } else if (cnt < k) {
            right = mid - 1; // n太大，切题数太少
        } else {
            minN = mid;      // 找到满足条件的n
            right = mid - 1; // 继续向左找更小的n
        }
    }

    // 二分最大n
    left = 1, right = 1e18;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll cnt = countAC(mid);

        if (cnt > k) {
            left = mid + 1; // n太小，切题数太多
        } else if (cnt < k) {
            right = mid - 1; // n太大，切题数太少
        } else {
            maxN = mid;     // 找到满足条件的n
            left = mid + 1; // 继续向右找更大的n
        }
    }

    if (minN == -1 || maxN == -1) {
        cout << -1 << endl;
    } else {
        cout << minN << " " << maxN << endl;
    }

    return 0;
}