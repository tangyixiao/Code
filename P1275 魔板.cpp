#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));
        vector<vector<int>> B(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> B[i][j];

        // 提取B的列并排序
        vector<string> colsB(m);
        for (int j = 0; j < m; ++j) {
            string col = "";
            for (int i = 0; i < n; ++i)
                col += char('0' + B[i][j]);
            colsB[j] = col;
        }
        sort(colsB.begin(), colsB.end());

        bool found = false;
        // 枚举B的每一列，假设A的第一列与其匹配
        for (int k = 0; k < m; ++k) {
            // 计算行翻转向量r
            vector<int> r(n);
            for (int i = 0; i < n; ++i)
                r[i] = A[i][0] ^ B[i][k];

            // 将A的所有列应用翻转r
            vector<string> transformed(m);
            for (int j = 0; j < m; ++j) {
                string col = "";
                for (int i = 0; i < n; ++i)
                    col += char('0' + (A[i][j] ^ r[i]));
                transformed[j] = col;
            }
            sort(transformed.begin(), transformed.end());
t
            // 比较是否与B的列集合相同
            if (transformed == colsB) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}