#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Step {
    int a, b;
    char op;
    int res;
};

void printStep(const Step &s) {
    int a = s.a, b = s.b;
    char op = s.op;
    if (op == '+' || op == '*') {
        if (a < b)
            swap(a, b);
    }
    cout << a << op << b << '=' << s.res << endl;
}

bool dfs(vector<int> nums, vector<Step> &steps) {
    if (nums.size() == 1) {
        return nums[0] == 24;
    }
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = nums[i], b = nums[j];
            // 加法
            int res = a + b;
            vector<int> next_nums;
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j)
                    next_nums.push_back(nums[k]);
            }
            next_nums.push_back(res);
            steps.push_back({a, b, '+', res});
            if (dfs(next_nums, steps))
                return true;
            steps.pop_back();

            // 减法 a-b
            if (a > b) {
                res = a - b;
                next_nums.clear();
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        next_nums.push_back(nums[k]);
                }
                next_nums.push_back(res);
                steps.push_back({a, b, '-', res});
                if (dfs(next_nums, steps))
                    return true;
                steps.pop_back();
            }
            // 减法 b-a
            if (b > a) {
                res = b - a;
                next_nums.clear();
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        next_nums.push_back(nums[k]);
                }
                next_nums.push_back(res);
                steps.push_back({b, a, '-', res});
                if (dfs(next_nums, steps))
                    return true;
                steps.pop_back();
            }

            // 乘法
            res = a * b;
            next_nums.clear();
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j)
                    next_nums.push_back(nums[k]);
            }
            next_nums.push_back(res);
            steps.push_back({a, b, '*', res});
            if (dfs(next_nums, steps))
                return true;
            steps.pop_back();

            // 除法 a/b
            if (b != 0 && a % b == 0) {
                res = a / b;
                next_nums.clear();
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        next_nums.push_back(nums[k]);
                }
                next_nums.push_back(res);
                steps.push_back({a, b, '/', res});
                if (dfs(next_nums, steps))
                    return true;
                steps.pop_back();
            }
            // 除法 b/a
            if (a != 0 && b % a == 0) {
                res = b / a;
                next_nums.clear();
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        next_nums.push_back(nums[k]);
                }
                next_nums.push_back(res);
                steps.push_back({b, a, '/', res});
                if (dfs(next_nums, steps))
                    return true;
                steps.pop_back();
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums(4);
    for (int i = 0; i < 4; ++i) {
        cin >> nums[i];
    }
    vector<Step> steps;
    if (dfs(nums, steps)) {
        for (const auto &step : steps) {
            printStep(step);
        }
    } else {
        cout << "No answer!" << endl;
    }
    return 0;
}