#include <cstring>
#include <iostream>

using namespace std;

// 存储数独的9x9网格
char board[9][9];
// 行、列、3x3子网格的标记数组
bool row[9][10], col[9][10], block[3][3][10];

// DFS回溯搜索
bool dfs(int pos) {
    // 如果已经处理完所有格子，返回true
    if (pos == 81)
        return true;

    // 计算当前格子的行列坐标
    int r = pos / 9;
    int c = pos % 9;

    // 如果当前格子已经有数字，则继续处理下一个格子
    if (board[r][c] != '.') {
        return dfs(pos + 1);
    }

    // 尝试在当前格子填入1-9
    for (int num = 1; num <= 9; num++) {
        // 检查是否满足数独规则
        if (!row[r][num] && !col[c][num] && !block[r / 3][c / 3][num]) {
            // 填入数字并更新标记
            board[r][c] = '0' + num;
            row[r][num] = col[c][num] = block[r / 3][c / 3][num] = true;

            // 递归处理下一个格子
            if (dfs(pos + 1)) {
                return true;
            }

            // 回溯：撤销选择
            board[r][c] = '.';
            row[r][num] = col[c][num] = block[r / 3][c / 3][num] = false;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (cin >> line) {
        if (line == "end")
            break;

        // 初始化标记数组
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));

        // 将输入字符串转换为9x9网格并初始化标记
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = line[i * 9 + j];
                board[i][j] = ch;

                // 如果当前位置有数字，更新标记
                if (ch != '.') {
                    int num = ch - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    block[i / 3][j / 3][num] = true;
                }
            }
        }

        // 使用DFS求解数独
        dfs(0);

        // 输出结果
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}
