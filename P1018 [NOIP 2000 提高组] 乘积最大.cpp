#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;

namespace BIGINT {

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void fft(vector<complex<double>> &a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * M_PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(ang), sin(ang));

    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiplyPolynomials(const vector<int> &a, const vector<int> &b) {
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }

    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = round(fa[i].real());
    }
    return result;
}

class BigInteger {
  private:
    string num;
    bool negative;

    void removeLeadingZeros(string &s) const {
        if (s.empty())
            return;
        size_t start = 0;
        while (start < s.size() - 1 && s[start] == '0')
            start++;
        s = s.substr(start);
    }

    int compare(const string &a, const string &b) const {
        if (a.size() != b.size())
            return a.size() < b.size() ? -1 : 1;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return a[i] < b[i] ? -1 : 1;
        }
        return 0;
    }

    string addStrings(const string &a, const string &b) const {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string subStrings(const string &a, const string &b) const {
        string res;
        int i = a.size() - 1, j = b.size() - 1, borrow = 0;
        while (i >= 0) {
            int digit = a[i--] - '0' - borrow;
            if (j >= 0)
                digit -= b[j--] - '0';
            borrow = 0;
            if (digit < 0) {
                digit += 10;
                borrow = 1;
            }
            res.push_back(digit + '0');
        }
        reverse(res.begin(), res.end());
        removeLeadingZeros(res);
        return res;
    }

    string mulStringsFFT(const string &a, const string &b) const {
        if (a == "0" || b == "0")
            return "0";

        vector<int> poly1, poly2;
        for (int i = a.size() - 1; i >= 0; i--) {
            poly1.push_back(a[i] - '0');
        }
        for (int i = b.size() - 1; i >= 0; i--) {
            poly2.push_back(b[i] - '0');
        }

        vector<int> result = multiplyPolynomials(poly1, poly2);

        int carry = 0;
        for (int i = 0; i < result.size(); i++) {
            int val = result[i] + carry;
            carry = val / 10;
            result[i] = val % 10;
        }

        string res;
        bool leadingZero = true;
        for (int i = result.size() - 1; i >= 0; i--) {
            if (leadingZero && result[i] == 0)
                continue;
            leadingZero = false;
            res += to_string(result[i]);
        }

        return res.empty() ? "0" : res;
    }

    string mulStringsNaive(const string &a, const string &b) const {
        int m = a.size(), n = b.size();
        vector<int> res(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (a[i] - '0') * (b[j] - '0');
                int sum = mul + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string result;
        for (int digit : res) {
            if (!result.empty() || digit != 0) {
                result.push_back(digit + '0');
            }
        }
        return result.empty() ? "0" : result;
    }

    pair<string, string> divStrings(const string &a, const string &b) const {
        if (b == "0")
            throw invalid_argument("Division by zero");
        if (compare(a, b) < 0)
            return {"0", a};

        string quotient, remainder;
        size_t idx = 0;
        string temp = a.substr(0, b.size());
        if (compare(temp, b) < 0) {
            if (b.size() < a.size())
                temp += a[b.size()];
            idx = b.size() + 1;
        } else {
            idx = b.size();
        }

        while (idx <= a.size()) {
            int cnt = 0;
            while (compare(temp, b) >= 0) {
                temp = subStrings(temp, b);
                cnt++;
            }
            quotient.push_back(cnt + '0');

            if (idx < a.size()) {
                temp += a[idx];
            }
            idx++;

            removeLeadingZeros(temp);
            if (temp == "0")
                temp = "";
        }

        removeLeadingZeros(quotient);
        remainder = temp.empty() ? "0" : temp;
        return {quotient.empty() ? "0" : quotient, remainder};
    }

    string toBinary() const {
        if (num == "0")
            return "0";
        string binary, current = num;
        while (current != "0") {
            auto [q, r] = divStrings(current, "2");
            binary.push_back(r[0]);
            current = q;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }

    string fromBinary(const string &bin) const {
        string dec = "0", base = "1";
        for (int i = bin.size() - 1; i >= 0; i--) {
            if (bin[i] == '1') {
                dec = addStrings(dec, base);
            }

            base = mulStringsNaive(base, "2");
        }
        return dec;
    }

  public:
    BigInteger() : num("0"), negative(false) {}
    BigInteger(const string &s) {
        string input = s;
        negative = false;
        if (!s.empty() && s[0] == '-') {
            negative = true;
            input = s.substr(1);
        }
        if (input.empty() || !all_of(input.begin(), input.end(), ::isdigit)) {
            throw invalid_argument("Invalid number string");
        }
        removeLeadingZeros(input);
        num = input.empty() ? "0" : input;
        if (num == "0")
            negative = false;
    }
    BigInteger(long long x) : BigInteger(to_string(x)) {}

    string toString() const {
        return negative ? "-" + num : num;
    }

    BigInteger operator+(const BigInteger &other) const {
        if (negative != other.negative) {
            BigInteger absThis = *this;
            absThis.negative = false;
            BigInteger absOther = other;
            absOther.negative = false;
            return absThis - absOther;
        }

        BigInteger result;
        result.num = addStrings(num, other.num);
        result.negative = negative;
        return result;
    }

    BigInteger operator-(const BigInteger &other) const {
        if (negative != other.negative) {
            BigInteger absThis = *this;
            absThis.negative = false;
            BigInteger absOther = other;
            absOther.negative = false;
            BigInteger res = absThis + absOther;
            res.negative = negative;
            return res;
        }

        int cmp = compare(num, other.num);
        if (cmp == 0)
            return BigInteger("0");

        BigInteger result;
        if (cmp > 0) {
            result.num = subStrings(num, other.num);
            result.negative = negative;
        } else {
            result.num = subStrings(other.num, num);
            result.negative = !negative;
        }
        return result;
    }

    BigInteger operator*(const BigInteger &other) const {
        if (num == "0" || other.num == "0")
            return BigInteger("0");

        string res;
        if (num.size() < 50 || other.num.size() < 50) {
            res = mulStringsNaive(num, other.num);
        } else {
            res = mulStringsFFT(num, other.num);
        }

        BigInteger result(res);
        result.negative = negative ^ other.negative;
        return result;
    }

    BigInteger operator/(const BigInteger &other) const {
        auto [q, r] = divStrings(num, other.num);
        BigInteger result(q);
        result.negative = negative ^ other.negative;
        if (result.num != "0" && result.negative) {
            if (r != "0") {
                result = result - BigInteger("1");
            }
        }
        return result;
    }

    BigInteger operator%(const BigInteger &other) const {
        auto [q, r] = divStrings(num, other.num);
        if (r == "0")
            return BigInteger("0");
        if (!negative && !other.negative)
            return BigInteger(r);
        if (negative && !other.negative)
            return BigInteger(other - BigInteger(r));
        if (!negative && other.negative)
            return BigInteger(other + BigInteger(r));
        return BigInteger(r).negative ? other + BigInteger(r) : BigInteger(r);
    }

    string decimalDivision(const BigInteger &divisor, int precision = 20) const {
        if (divisor.num == "0")
            throw invalid_argument("Division by zero");

        string integerPart, remainder;
        if (compare(num, divisor.num) >= 0) {
            auto [q, r] = divStrings(num, divisor.num);
            integerPart = q;
            remainder = r;
        } else {
            integerPart = "0";
            remainder = num;
        }

        string decimal;
        for (int i = 0; i < precision; i++) {
            if (remainder == "0")
                break;
            remainder += "0";
            auto [q, r] = divStrings(remainder, divisor.num);
            decimal += q;
            remainder = r;
        }

        string sign = (negative ^ divisor.negative) ? "-" : "";
        return sign + integerPart + (decimal.empty() ? "" : "." + decimal);
    }

    BigInteger operator&(const BigInteger &other) const {
        if (negative || other.negative)
            throw invalid_argument("Bitwise operations only for non-negative integers");

        string bin1 = toBinary();
        string bin2 = other.toBinary();
        size_t len = max(bin1.size(), bin2.size());
        bin1 = string(len - bin1.size(), '0') + bin1;
        bin2 = string(len - bin2.size(), '0') + bin2;

        string resBin;
        for (size_t i = 0; i < len; i++) {
            resBin.push_back((bin1[i] == '1' && bin2[i] == '1') ? '1' : '0');
        }

        BigInteger result;
        result.num = fromBinary(resBin);
        return result;
    }

    BigInteger operator|(const BigInteger &other) const {
        if (negative || other.negative)
            throw invalid_argument("Bitwise operations only for non-negative integers");

        string bin1 = toBinary();
        string bin2 = other.toBinary();
        size_t len = max(bin1.size(), bin2.size());
        bin1 = string(len - bin1.size(), '0') + bin1;
        bin2 = string(len - bin2.size(), '0') + bin2;

        string resBin;
        for (size_t i = 0; i < len; i++) {
            resBin.push_back((bin1[i] == '1' || bin2[i] == '1') ? '1' : '0');
        }

        BigInteger result;
        result.num = fromBinary(resBin);
        return result;
    }

    BigInteger operator^(const BigInteger &other) const {
        if (negative || other.negative)
            throw invalid_argument("Bitwise operations only for non-negative integers");

        string bin1 = toBinary();
        string bin2 = other.toBinary();
        size_t len = max(bin1.size(), bin2.size());
        bin1 = string(len - bin1.size(), '0') + bin1;
        bin2 = string(len - bin2.size(), '0') + bin2;

        string resBin;
        for (size_t i = 0; i < len; i++) {
            resBin.push_back(bin1[i] != bin2[i] ? '1' : '0');
        }

        BigInteger result;
        result.num = fromBinary(resBin);
        return result;
    }

    BigInteger operator~() const {
        if (negative)
            throw invalid_argument("Bitwise operations only for non-negative integers");

        string bin = toBinary();
        for (char &c : bin) {
            c = (c == '1') ? '0' : '1';
        }

        BigInteger result;
        result.num = fromBinary(bin);
        return result;
    }

    BigInteger operator<<(int shift) const {
        if (negative)
            throw invalid_argument("Bitwise operations only for non-negative integers");
        if (shift < 0)
            throw invalid_argument("Negative shift");

        BigInteger result = *this;
        while (shift--) {
            result.num = mulStringsNaive(result.num, "2");
        }
        return result;
    }

    BigInteger operator>>(int shift) const {
        if (negative)
            throw invalid_argument("Bitwise operations only for non-negative integers");
        if (shift < 0)
            throw invalid_argument("Negative shift");

        BigInteger result = *this;
        while (shift--) {
            auto [q, r] = divStrings(result.num, "2");
            result.num = q;
        }
        return result;
    }

    BigInteger pow(const BigInteger &exponent) const {
        if (exponent.negative) {
            throw invalid_argument("Negative exponents not supported");
        }

        if (exponent == BigInteger(0)) {
            return BigInteger(1);
        }
        if (*this == BigInteger(0)) {
            return BigInteger(0);
        }

        BigInteger base = *this;
        BigInteger result(1);
        BigInteger exp = exponent;

        while (exp > BigInteger(0)) {
            if (exp % BigInteger(2) == BigInteger(1)) {
                result = result * base;
            }
            base = base * base;
            exp = exp / BigInteger(2);
        }

        return result;
    }

    BigInteger modPow(const BigInteger &exponent, const BigInteger &modulus) const {
        if (modulus == BigInteger(0)) {
            throw invalid_argument("Modulus cannot be zero");
        }
        if (exponent.negative) {
            throw invalid_argument("Negative exponents not supported");
        }

        if (exponent == BigInteger(0)) {
            return BigInteger(1) % modulus;
        }
        if (*this == BigInteger(0)) {
            return BigInteger(0);
        }

        BigInteger base = *this % modulus;
        BigInteger result(1);
        BigInteger exp = exponent;

        while (exp > BigInteger(0)) {
            if (exp % BigInteger(2) == BigInteger(1)) {
                result = (result * base) % modulus;
            }
            base = (base * base) % modulus;
            exp = exp / BigInteger(2);
        }

        return result;
    }

    BigInteger &operator++() {
        if (num == "0") {
            negative = false;
            num = "1";
        } else {
            num = addStrings(num, "1");
        }
        return *this;
    }
    BigInteger &operator--() {
        if (num == "0") {
            negative = true;
            num = "1";
        } else {
            num = subStrings(num, "1");
        }
        return *this;
    }
    BigInteger operator++(int) {
        BigInteger temp = *this;
        ++(*this);
        return temp;
    }
    BigInteger operator--(int) {
        BigInteger temp = *this;
        --(*this);
        return temp;
    }

    bool operator<(const BigInteger &other) const {
        if (negative != other.negative)
            return negative;
        if (negative)
            return compare(num, other.num) > 0;
        return compare(num, other.num) < 0;
    }

    bool operator>(const BigInteger &other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger &other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger &other) const {
        return !(*this < other);
    }

    bool operator==(const BigInteger &other) const {
        return negative == other.negative && num == other.num;
    }

    bool operator!=(const BigInteger &other) const {
        return !(*this == other);
    }
};

void testFFTOptimization() {

    string num1(1000, '9');
    string num2(1000, '9');

    BigInteger a(num1);
    BigInteger b(num2);

    cout << "Multiplying two 1000-digit numbers using FFT..." << endl;

    clock_t start = clock();
    BigInteger c = a * b;
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "FFT multiplication time: " << duration << " seconds" << endl;
}
} // namespace BIGINT
using namespace BIGINT;
string ns, ks;
const int N = 45;
int n, k;
BigInteger dp[N][N], b[N][N];
string s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            b[i][j] = b[i][j - 1] * BigInteger("10") + BigInteger(to_string(s[j] - '0'));
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = b[1][i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(k, i); j++) {
            for (int l = j; l < i; l++) {
                dp[i][j] = max(dp[i][j], dp[l][j - 1] * b[l + 1][i]);
            }
        }
    }
    cout << dp[n][k].toString() << "\n";
    return 0;
}
