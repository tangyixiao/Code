#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

/*
    排序算法合集

    1. Bubble        冒泡排序
    2. Selection     选择排序
    3. Insertion     插入排序
    4. Shell         希尔排序
    5. Merge         归并排序
    6. Quick         快速排序
    7. Heap          堆排序
    8. Counting      计数排序
    9. Bucket        桶排序
    10.Radix         基数排序
    11.STL           STL 常用排序
    12.Discretize    离散化

    默认数组下标均为 [1,n]
*/

namespace Bubble {

// 冒泡排序
// 时间复杂度：
// 最坏 O(n^2)
// 最好 O(n)
// 空间复杂度 O(1)
// 稳定排序

void sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        bool f = 0;

        // 每轮把当前最大值移动到后面
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                f = 1;
            }
        }

        // 没发生交换，说明已经有序
        if (!f)
            break;
    }
}

} // namespace Bubble

namespace Selection {

// 选择排序
// 时间复杂度 O(n^2)
// 空间复杂度 O(1)
// 不稳定排序

void sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int p = i;

        // 找出 [i,n] 中最小元素
        for (int j = i + 1; j <= n; j++)
            if (a[j] < a[p])
                p = j;

        swap(a[i], a[p]);
    }
}

} // namespace Selection

namespace Insertion {

// 插入排序
// 最坏 O(n^2)
// 最好 O(n)
// 空间复杂度 O(1)
// 稳定排序
// 对基本有序数组效率较高

void sort(int a[], int n) {
    for (int i = 2; i <= n; i++) {
        int x = a[i];
        int j = i - 1;

        // 将大于 x 的元素向右移动
        while (j && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }

        // 插入 x
        a[j + 1] = x;
    }
}

} // namespace Insertion

namespace Shell {

// 希尔排序
// 插入排序的改进
// 不稳定排序
// 复杂度与步长选择有关

void sort(int a[], int n) {

    // 枚举步长
    for (int d = n / 2; d; d /= 2) {

        // 对每个间隔为 d 的序列进行插入排序
        for (int i = d + 1; i <= n; i++) {
            int x = a[i];
            int j = i - d;

            while (j > 0 && a[j] > x) {
                a[j + d] = a[j];
                j -= d;
            }

            a[j + d] = x;
        }
    }
}

} // namespace Shell

namespace Merge {

// 归并排序
// 时间复杂度严格 O(n log n)
// 空间复杂度 O(n)
// 稳定排序
// OI 中非常重要，可扩展求逆序对

int b[N];

void msort(int a[], int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) >> 1;

    // 分治
    msort(a, l, mid);
    msort(a, mid + 1, r);

    int i = l;
    int j = mid + 1;
    int k = l;

    // 合并两个有序区间
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    // 剩余元素
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];

    // 写回原数组
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

void sort(int a[], int n) {
    msort(a, 1, n);
}

} // namespace Merge

namespace Quick {

// 快速排序
// 平均 O(n log n)
// 最坏 O(n^2)
// 不稳定排序
// 实际比赛普通排序直接使用 std::sort

void qsort(int a[], int l, int r) {
    if (l >= r)
        return;

    int i = l;
    int j = r;

    // 取中间元素作为基准
    int x = a[(l + r) >> 1];

    while (i <= j) {

        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    // 分治处理两部分
    if (l < j)
        qsort(a, l, j);
    if (i < r)
        qsort(a, i, r);
}

void sort(int a[], int n) {
    qsort(a, 1, n);
}

} // namespace Quick

namespace Heap {

// 堆排序
// 时间复杂度严格 O(n log n)
// 空间复杂度 O(1)
// 不稳定排序

// 向下调整大根堆
void down(int a[], int p, int n) {

    while (p * 2 <= n) {
        int q = p * 2;

        // 找两个儿子中较大的一个
        if (q < n && a[q] < a[q + 1])
            q++;

        // 已经符合大根堆性质
        if (a[p] >= a[q])
            break;

        swap(a[p], a[q]);

        p = q;
    }
}

void sort(int a[], int n) {

    // 建立大根堆
    // 从最后一个非叶节点开始
    for (int i = n / 2; i; i--)
        down(a, i, n);

    // 每次将最大值移动到数组末尾
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);

        // 剩余 [1,i-1] 重新调整
        down(a, 1, i - 1);
    }
}

} // namespace Heap

namespace Counting {

// 计数排序
// 适用于值域较小的非负整数
//
// 时间复杂度 O(n+V)
// 空间复杂度 O(V)
//
// V 为值域大小

const int V = 1e6 + 5;

int cnt[V];

void sort(int a[], int n) {

    int mx = 0;

    // 清空计数数组
    memset(cnt, 0, sizeof cnt);

    // 统计出现次数
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    int p = 0;

    // 根据出现次数重建数组
    for (int x = 0; x <= mx; x++) {
        while (cnt[x]) {
            a[++p] = x;
            cnt[x]--;
        }
    }
}

} // namespace Counting

namespace Bucket {

// 桶排序示例
//
// 将数按照数值范围放入不同桶中，
// 然后分别对桶内部排序。
//
// 这里假设：
// 0 <= a[i] < 10000000
// 每个桶负责长度 100 的值域

const int S = 100;
const int B = 100005;

vector<int> bucket[B];

void sort(int a[], int n) {

    int mx = 0;

    for (int i = 1; i <= n; i++) {
        int id = a[i] / S;

        bucket[id].push_back(a[i]);

        mx = max(mx, id);
    }

    int p = 0;

    // 从小到大处理每个桶
    for (int i = 0; i <= mx; i++) {

        // 桶内仍然需要排序
        std::sort(bucket[i].begin(), bucket[i].end());

        for (int x : bucket[i])
            a[++p] = x;

        // 清空，方便再次使用
        bucket[i].clear();
    }
}

} // namespace Bucket

namespace Radix {

// 基数排序
//
// 这里处理 unsigned int
// 每次处理 16 bit
//
// unsigned int 共 32 bit
// 因此只需要两轮
//
// 时间复杂度近似 O(n)
// 空间复杂度 O(n+B)
// 稳定排序

const int B = 1 << 16;

unsigned int b[N];
int cnt[B];

// 对某 16 位进行一次稳定计数排序
void work(unsigned int a[], unsigned int b[], int n, int shift) {

    memset(cnt, 0, sizeof cnt);

    // 统计当前 16 位
    for (int i = 1; i <= n; i++)
        cnt[(a[i] >> shift) & 65535]++;

    // 前缀和
    for (int i = 1; i < B; i++)
        cnt[i] += cnt[i - 1];

    // 倒序保证稳定性
    for (int i = n; i; i--) {
        int x = (a[i] >> shift) & 65535;
        b[cnt[x]--] = a[i];
    }
}

void sort(unsigned int a[], int n) {

    // 低 16 位
    work(a, b, n, 0);

    // 高 16 位
    work(b, a, n, 16);
}

} // namespace Radix

namespace STL {

// C++ STL 中常用的排序相关算法

void normal_sort(int a[], int n) {

    // 普通排序
    // O(n log n)
    std::sort(a + 1, a + n + 1);
}

void stable_sort(int a[], int n) {

    // 稳定排序
    std::stable_sort(a + 1, a + n + 1);
}

int kth(int a[], int n, int k) {

    // nth_element
    //
    // 找第 k 小
    // 平均 O(n)
    //
    // 执行后：
    // a[k] 是第 k 小
    // 但整个数组不保证有序

    nth_element(a + 1, a + k, a + n + 1);

    return a[k];
}

void first_k(int a[], int n, int k) {

    // 将最小的 k 个元素放到前面
    // 并保证这 k 个元素已经排序

    partial_sort(a + 1, a + k + 1, a + n + 1);
}

} // namespace STL

namespace StructSort {

// 结构体多关键字排序示例
//
// 例如 NOIP 2009 分数线划定：
//
// 第一关键字：成绩从高到低
// 第二关键字：编号从小到大

struct Node {
    int id;
    int score;
};

bool cmp(Node a, Node b) {

    if (a.score != b.score)
        return a.score > b.score;

    return a.id < b.id;
}

void sort(Node a[], int n) {
    std::sort(a + 1, a + n + 1, cmp);
}

} // namespace StructSort

namespace Discretize {

// 离散化
//
// 例如：
//
// 1000000000 5 100 5
//
// 离散化为：
//
// 3 1 2 1
//
// 保留原来的大小关系

int b[N];

// 返回离散化后的值域大小
int work(int a[], int n) {

    // 复制原数组
    for (int i = 1; i <= n; i++)
        b[i] = a[i];

    // 排序
    std::sort(b + 1, b + n + 1);

    // 去重
    int m = unique(b + 1, b + n + 1) - b - 1;

    // 将原数组转换成排名
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    }

    return m;
}

} // namespace Discretize

namespace Inversion {

// 归并排序求逆序对
//
// 逆序对：
// i < j 且 a[i] > a[j]
//
// 时间复杂度 O(n log n)

int b[N];

long long solve(int a[], int l, int r) {

    if (l >= r)
        return 0;

    int mid = (l + r) >> 1;

    long long ans = 0;

    ans += solve(a, l, mid);
    ans += solve(a, mid + 1, r);

    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= r) {

        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {

            b[k++] = a[j++];

            // a[i...mid] 全部大于当前 a[j]
            ans += mid - i + 1;
        }
    }

    while (i <= mid)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];

    for (int i = l; i <= r; i++)
        a[i] = b[i];

    return ans;
}

long long work(int a[], int n) {
    return solve(a, 1, n);
}

} // namespace Inversion

int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    /*
        ==============================
        选择一种排序方式进行测试
        ==============================

        Bubble::sort(a,n);

        Selection::sort(a,n);

        Insertion::sort(a,n);

        Shell::sort(a,n);

        Merge::sort(a,n);

        Quick::sort(a,n);

        Heap::sort(a,n);

        Counting::sort(a,n);

        Bucket::sort(a,n);

        STL::normal_sort(a,n);


        如果使用 unsigned int 基数排序：

        static unsigned int b[N];

        for(int i=1;i<=n;i++)
            b[i]=a[i];

        Radix::sort(b,n);


        求第 k 小：

        int x=STL::kth(a,n,k);


        离散化：

        int m=Discretize::work(a,n);


        求逆序对：

        long long ans=Inversion::work(a,n);
    */

    // P1177 默认直接使用 STL sort
    STL::normal_sort(a, n);

    for (int i = 1; i <= n; i++) {
        if (i > 1)
            cout << " ";
        cout << a[i];
    }

    cout << "\n";

    return 0;
}