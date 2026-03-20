#include <iostream>
#include <vector>
using namespace std;

struct BigInt {
    vector<int> d;

    BigInt(long long x = 0) {
        if (x == 0)
            d.push_back(0);
        else {
            while (x) {
                d.push_back(x % 10);
                x /= 10;
            }
        }
    }

    void normalize() {
        while (d.size() > 1 && d.back() == 0)
            d.pop_back();
    }

    BigInt &operator*=(int x) {
        int carry = 0;
        for (auto &v : d) {
            long long cur = (long long)v * x + carry;
            v = cur % 10;
            carry = cur / 10;
        }
        while (carry) {
            d.push_back(carry % 10);
            carry /= 10;
        }
        return *this;
    }

    BigInt operator*(int x) const {
        BigInt res = *this;
        res *= x;
        return res;
    }

    BigInt operator+(const BigInt &b) const {
        BigInt res;
        int carry = 0;
        size_t i = 0;
        while (i < d.size() || i < b.d.size() || carry) {
            int sum = carry;
            if (i < d.size())
                sum += d[i];
            if (i < b.d.size())
                sum += b.d[i];
            res.d.push_back(sum % 10);
            carry = sum / 10;
            ++i;
        }
        return res;
    }

    BigInt operator*(const BigInt &b) const {
        BigInt res;
        res.d.resize(d.size() + b.d.size(), 0);
        for (size_t i = 0; i < d.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < b.d.size(); ++j) {
                long long cur = res.d[i + j] + (long long)d[i] * b.d[j] + carry;
                res.d[i + j] = cur % 10;
                carry = cur / 10;
            }

            if (carry) {
                int pos = i + b.d.size();
                while (carry) {
                    if (pos < res.d.size()) {
                        long long cur = res.d[pos] + carry;
                        res.d[pos] = cur % 10;
                        carry = cur / 10;
                        ++pos;
                    } else {
                        res.d.push_back(carry % 10);
                        carry /= 10;
                    }
                }
            }
        }
        res.normalize();
        return res;
    }

    friend ostream &operator<<(ostream &os, const BigInt &bi) {
        if (bi.d.size() == 1) {
            os << bi.d[0];
            return os;
        }
        for (int i = bi.d.size() - 1; i >= 1; --i)
            os << bi.d[i];
        return os;
    }
};

BigInt P(int a, int b) {
    if (b < 0 || b > a)
        return BigInt(0);
    BigInt res(1);
    for (int i = 0; i < b; ++i)
        res *= (a - i);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    BigInt fact_n(1);
    for (int i = 2; i <= n; ++i)
        fact_n *= i;

    if (m == 0) {

        BigInt ans = fact_n;
        ans *= (n + 1);
        ans *= n;
        cout << ans << endl;
        return 0;
    }

    BigInt term1 = P(n + 3, m);
    term1 = term1 * n;

    BigInt term2 = P(n + 2, m - 1);
    term2 = term2 * (2 * m);

    BigInt sum = term1 + term2;
    BigInt ans = fact_n;
    ans *= (n + 1);
    ans = ans * sum;

    cout << ans << endl;
    return 0;
}