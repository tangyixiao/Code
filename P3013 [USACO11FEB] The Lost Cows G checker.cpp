#include "testlib.h"
using namespace std;
int Sign[201][201], istt[5000001], pst[201], len;
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int N = inf.readInt();
    int M = inf.readInt();
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            Sign[i][j] = inf.readInt();
        }
    }
    while (!ouf.seekEof()) {
        int x = ouf.readInt();
        if (len == 5000000) {
            quitf(_pe, "The number of instructions is too large!");
        }
        if (x < 1 || x > M) {
            quitf(_pe, "The instruction %d is invalid!", len + 1);
        }
        istt[++len] = x;
    }
    for (int i = 1; i <= N; i++) {
        pst[i] = i;
    }
    for (int k = 1; k <= len; k++) {
        for (int i = 1; i <= N; i++) {
            pst[i] = Sign[istt[k]][pst[i]];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (pst[i] != 1) {
            quitf(_wa, "The cow %d is not in the barn at the end!", i);
        }
    }
    quitf(_ok, "The answer is correct.");
    return 0;
}
