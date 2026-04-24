#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv); // 必须最开始调用

    // 读取标准答案的胜负方和数值
    string j_side = ans.readToken();
    double j_val = ans.readDouble();

    // 读取选手输出的胜负方和数值
    string p_side = ouf.readToken();
    double p_val = ouf.readDouble();

    // 判胜负方必须一致
    if (p_side != j_side) {
        quitf(_wa, "Expected side %s, found %s", j_side.c_str(), p_side.c_str());
    }

    // 使用 testlib 内置的浮点数比较（绝对/相对误差 1e-6）
    if (!doubleCompare(j_val, p_val, 1e-6)) {
        quitf(_wa, "Expected %.7f, found %.7f, error = %.7f",
              j_val, p_val, doubleDelta(j_val, p_val));
    }

    // 不允许有多余内容
    ouf.skipBlanks();
    if (!ouf.seekEof()) {
        quitf(_wa, "Extra output after correct answer");
    }

    quitf(_ok, "correct");
}