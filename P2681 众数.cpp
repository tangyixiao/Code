#include <iostream>
#include <unordered_map>
using namespace std;

const int MAXN = 1005;
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    while (m--) {
        int flag, x, y;
        cin >> flag >> x >> y;
        if (flag == 0) {
            // 查询区间 [x, y] 的众数
            unordered_map<int, int> freq;
            int mode = a[x];  // 初始化为第一个元素
            int max_cnt = 0;
            for (int i = x; i <= y; ++i) {
                int num = a[i];
                int cnt = ++freq[num];
                if (cnt > max_cnt || (cnt == max_cnt && num < mode)) {
                    max_cnt = cnt;
                    mode = num;
                }
            }
            cout << mode << '\n';
        } else {
            // 修改 a[x] = y
            a[x] = y;
        }
    }
    
    return 0;
}