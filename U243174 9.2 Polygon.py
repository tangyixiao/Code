#import sys
#sys.set_int_max_str_digits(4000000)
def C(n, m):
    if m < 0 or m > n:
        return 0
    m = min(m, n - m)
    s = 1
    for i in range(1, m + 1):
        s = s * (n - i + 1) // i
    return s
n, k, p = map(int, input().split())
if k < 1 or k > n - 2:
    print(0)
else:
    ans = C(n + k - 2, k - 1) * C(n - 3, k - 1) // k
    print(ans % p)