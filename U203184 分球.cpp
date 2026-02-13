#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BigInt {
    vector<int> digits;

    BigInt() {}
    BigInt(const string &s) {
        for (int i = s.size() - 1; i >= 0; --i)
            digits.push_back(s[i] - '0');
    }
    BigInt(int x) {
        if (x == 0)
            digits.push_back(0);
        else {
            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }
        }
    }

    BigInt operator+(const BigInt &other) const {
        BigInt res;
        int carry = 0;
        int i = 0;
        while (i < digits.size() || i < other.digits.size() || carry) {
            int sum = carry;
            if (i < digits.size())
                sum += digits[i];
            if (i < other.digits.size())
                sum += other.digits[i];
            res.digits.push_back(sum % 10);
            carry = sum / 10;
            ++i;
        }
        return res;
    }

    BigInt operator*(int x) const {
        BigInt res;
        if (x == 0) {
            res.digits.push_back(0);
            return res;
        }
        int carry = 0;
        for (int i = 0; i < digits.size() || carry; ++i) {
            long long val = carry;
            if (i < digits.size())
                val += (long long)digits[i] * x;
            res.digits.push_back(val % 10);
            carry = val / 10;
        }
        return res;
    }

    void print() const {
        for (int i = digits.size() - 1; i >= 0; --i)
            cout << digits[i];
    }
};

const int MAX = 100;
BigInt S[101][101];

int main() {

    S[0][0] = BigInt(1);
    for (int i = 1; i <= MAX; ++i) {
        for (int j = 1; j <= i; ++j) {

            S[i][j] = S[i - 1][j - 1] + (S[i - 1][j] * j);
        }
    }

    int n, m;
    while (cin >> n >> m) {
        if (n < m) {
            cout << "0\n";
        } else {
            S[n][m].print();
            cout << '\n';
        }
    }
    return 0;
}