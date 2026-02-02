#include <bits/stdc++.h>
using namespace std;
set<int> s;
int m, op, l;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m;
    for (int _ = 1; _ <= m; _++) {
        cin >> op >> l;
        if (op & 1) { // 进货操作
            if (!s.insert(l).second) {
                cout << "Already Exist\n";
            }
        } else { // 出货操作
            if (s.empty()) {
                cout << "Empty\n";
            } else {
                if (s.find(l) != s.end()) { // 有完全匹配的长度
                    cout << l << "\n";
                    s.erase(s.find(l));
                } else {
                    auto it = s.lower_bound(l); // 第一个大于等于l的位置

                    if (it == s.begin()) { // 所有木材都比l大
                        cout << *it << "\n";
                        s.erase(it);
                    } else if (it == s.end()) { // 所有木材都比l小
                        cout << *(--it) << "\n";
                        s.erase(it);
                    } else {               // 既有比l小的，也有比l大的
                        auto prev_it = it; // 指向比l大的木材
                        --prev_it;         // 指向比l小的木材

                        // 计算差值
                        int diff1 = l - *prev_it; // 与较小木材的差值
                        int diff2 = *it - l;      // 与较大木材的差值

                        // 比较差值，如果差值相等选择较短的（较小的）
                        if (diff1 < diff2 || (diff1 == diff2)) {
                            cout << *prev_it << "\n";
                            s.erase(prev_it);
                        } else {
                            cout << *it << "\n";
                            s.erase(it);
                        }
                    }
                }
            }
        }
    }
    return 0;
}