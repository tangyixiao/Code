#include <bits/stdc++.h>
// #define DEBUG
#define Judge
using namespace std;
namespace IO {
inline void Init_IO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return;
}
} // namespace IO
using namespace IO;
namespace FILE_IO {
const string Insuffix = ".in";
const string Outsuffix = ".out";
const string Anssuffix = ".ans";
inline void Judge_File(string File_Name) {
    freopen((File_Name + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + Outsuffix).c_str(), "w", stdout);
    return;
}
inline void Local_File(string File_Name, int File_Idx) {
    freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout);
    return;
}
} // namespace FILE_IO
using namespace FILE_IO;
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() {
    Start_Time = clock();
    return;
}
inline void End_Time_Count() {
    End_Time = clock();
    return;
}
inline double Time_Count() {
    double Time = (double)(End_Time - Start_Time) / CLOCKS_PER_SEC;
    return Time;
}
inline void Print_Time_Count(string Programe_Name) {
    cerr << fixed << setprecision(4) << "\n" << Programe_Name << " Time: " << Time_Count() << "s\n";
    return;
}
} // namespace TIME
using namespace TIME;
const int N = 1e3 + 5, inf = 1e2;
int C, T, n, k, p[N], d[N], tmp[N], sump, sumd, l, r, mid, ans;
inline bool pd() {
    for (int i = 1; i <= k; i++) {
        if (tmp[i] != d[i]) {
            return false;
        }
    }
    return true;
}
inline void dfs(int st) {
    if (st >= ans) {
        return;
    }
    /*

    if (pd()) {
        ans = min(st, ans);
        return;
    }
    */
#ifdef DEBUG
    cerr << "dfs\n";
#endif
    /*

        for (int i = 1, id = 1; i <= n; i++) {
            if (tmp[id] < i) {
                id++;
            }
            if (tmp[id] != i) {
                tmp[id - 1]++;
                tmp[id]--;
                dfs(st + 1);
            }
        }
    */
    return;
}
bool check() {
    for (int i = 1; i <= n; i++) {
        tmp[i] = p[i];
    }
    ans = inf;
#ifdef DEBUG
    cerr << "check\n";
#endif
    dfs(1);
    return ans <= mid;
}
inline void solve(int id) {
    sump = sumd = 0;
    l = 0, r = inf;
    cin >> n >> k;
#ifdef DEBUG
    cerr << "Here\n";
#endif
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
        sump += p[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> d[i];
        sumd += d[i];
    }

#ifdef DEBUG
    cerr << "Here\n";
#endif
    if (abs(sump - sumd) < abs((p[k] - p[1]) - (d[k] - d[1]))) {
        cout << "impoBGible\n";
        return;
    }

#ifdef DEBUG
    cerr << "Here\n";
#endif
    for (; l < r;) {
        mid = (l + r) >> 1;
        if (check()) {
            r = mid;
        } else {
            l = mid + 1;
        }
#ifdef DEBUG
        cerr << "Here\n";
#endif
    }

#ifdef DEBUG
    cerr << "Here\n";
#endif
    cout << (r == inf ? "impoBGible" : to_string(r)) << "\n";
    return;
}
signed main() {
    Init_IO();
#ifdef Judge
    Judge_File("piranhas");
#else
    // Local_File("piranhas", 1);
#endif
    cin >> C >> T;

    for (int id = 1; id <= T; id++) {
#ifdef DEBUG
        cerr << "Here" << id << "\n";
#endif
        solve(id);
    }
    return 0;
}
/*

Feb
绍兴一中求真模拟赛
竞赛时间：2026 年02 月07 日   (08:30-11:30)
提交源程序须加后缀
对于Pascal  语言 ball.pas scan.pas piranhas.pas equation.pas
对于C          语言 ball.c scan.c piranhas.c equation.c
对于C++      语言 ball.cpp scan.cpp piranhas.cpp equation.cpp
注意：
·在 Windows 下测评，所有编译命令均不打开任何优化开关，以评测机默认配置为准，C++14。
·严禁使用各种方式进行交流，包括但不限于飞鸽传书、共享文件夹等局域网通讯、文件分享工具。
·对题目有疑问请找出题人。
·出题人比较菜，请静悄悄AK，评测后再惊艳所有人。
题目名称 乒乓球 三维扫描 食人鱼 奇怪的等式
目录 ball scan piranhas equation
可执行文件名 ball scan piranhas equation
输入文件名 ball.in scan.in piranhas.in equation.in
输出文件名 ball.out scan.out piranhas.out equation.out
每个测试点时限 1s 1s 2s 1s
空间限制 512MiB 512MiB 512MiB 512MiB
测试点数目 10 10 20 20
每个测试点分值 10 10 5 5
结果比较方式 全文比较 全文比较 全文比较 全文比较
题目类型 传统型 传统型 传统型 传统型
Feb
乒乓球 （ball）
【题目描述】
华华通过以下方式进行分析，首先将比赛每个球的胜负列成一张表，然后分别计算在11 分制和21
分制下，双方的比赛结果（截至记录末尾）。 比如现在有这么一份记录，（其中W 表示华华获得一分，L
表示华华的对手获得一分）： WWWWWWWWWWWWWWWWWWWWWWLW 在 11 分制下，此时比赛的结果是华华第一局 11 比 0
获胜，第二局 11 比 0 获胜，正在进行第三局，当前比分 1 比 1。而在 21
分制下，此时比赛结果是华华第一局21 比0 获胜，正在进行第二局，比分 2
比1。如果一局比赛刚开始，则此时比分为0 比0。 你的程序就是要对于一系列比赛信息的输入（WL
形式），输出正确的结果。 【输入文件】ball.in 每个输入文件包含若干行字符串si，字符串由大写的W、L 和E
组成，也许中间有若干个空格。其中 E 表示比赛信息结束，程序应该忽略 E 之后的所有内容，E
后面可能有干扰文字。 【输出文件】ball.out
输出由两部分组成，每部分有若干行，每一行对应一局比赛的比分（按比赛信息输入顺序）。其中第一部分是11
分制下的结果，第二部分是21 分制下的结果，两部分之间由一个空行分隔。 【样例输入】
WWWWWWWWWWWWWWWWWWWW WWLWE
【样例输出】 11:0 11:0 1:1  21:0 2:1

【数据范围】
对于100%的数据，length(si)<=20，∑𝑠𝑖 ≤105。

Feb
三维扫描 （scan）
【题目描述】
工业和医学上经常要用到一种诊断技术——核磁共振成像（Magnetic Resonance
Imagers）。利用该技术可以对三维物体(例如大脑)进行扫描。扫描的结果用一个三维的数组来保存，数组的每一个元素表示空间的一个像素。数组的元素是0~255
的整数，表示该像素的灰度。例如0 表示该像素是黑色的，255 表示该像素是白色的。
被扫描的物体往往是由若干个部件组合而成的。例如临床医学要对病变的器官进行检查，而器官是由一些不同的组织构成的。在实际问题中，同一个部件内部的色彩变化相对连续，而不同的部件的交界处色彩往往有突变。下面是一个简化的植物细胞的例子。
从细胞的平面图来看，该细胞大致是由四个“部件”构成的，细胞壁、细胞核、液泡和细胞质。为了方便起见，我们对部件的概念做如下的规定：
1．如果一个像素属于某部件，则或者该像素至少与该部件的一个像素相邻，或者该像素单独组成一个部件。（说明：每一个像素与前后、左右、上下的
6 个像素相邻） 2．同一个部件内部，相邻两个像素的灰度差不超过正整数M。M 决定了程序识别部件的灵敏度。
你的任务是，对于给定的物体，判断该物体是由几个部件组成的。
【输入文件】scan.in
输入第一行是三个正整数L,W,H()，表示物体的长、宽、高。
第二行是一个整数M，表示识别部件的灵敏度。
接下来是L×W×H 个0~255 的非负整数，按照空间坐标从小到大的顺序依次给出每个像素的灰度。
说明：对于空间两点 P1(x1,y1,z1)和 P2(x2,y2,z2)，P1<P2 当且仅当(x1<x2)或者
(x1=x2 且y1<y2)或者(x1=x2 且y1=y2 且z1<z2)。
Feb
【输出文件】scan.out
输出一个整数N，表示一共识别出几个部件。
【样例输入】
2 2 2 0 1 1 1 1 2 2 2 2
【样例输出】 2

【数据范围】
数据按梯度分布。
对于100%的数据，满足L,W,H<=50，0<=M<=255。
Feb
食人鱼 （piranhas）
【题目描述】
BG 喜欢养鱼！为此，他买了一个鱼缸。
鱼缸是长条形的，可以从左到右划分成n 块区域，编号1 到n。 BG 在鱼缸里养了k 条食人鱼，从左到右第i
条鱼初始在区域pi。这些鱼不喜欢到处乱跑，所以在没有外界干涉的情况下，只会一直在初始所在的区域里游动。
BG 想给这些鱼拍个照。BG 发现，从左到右第i 条鱼在区域di 是最佳的拍照位置。 当BG
将手指伸进一个没有鱼的区域时，每过1
秒，这个区域左边最近的鱼和右边最近的鱼会朝手指的方向移动一个区域。为了防止手指被咬伤，BG
需要保证鱼移动后不会到手指所在的区域．．．．．．．．．．．．．。 BG
想知道，将所有鱼调整到最佳的拍照位置需要多少秒。手指拿出鱼缸、改变位置和伸进鱼缸的时间忽略不计。
【输入文件】piranhas.in
输入包含多组测试数据．．．．．．．．．．。
第一行两个整数C,T，表示测试点编号和数据组数。每组数据格式如下：
第一行两个整数n,k，分别表示区域数量和鱼的数量。
第二行k 个整数p1,p2,...,pk，表示鱼的初始位置。
第三行k 个整数d1,d2,...,dk，表示给鱼拍照的最佳位置。
【输出文件】piranhas.out
每组数据输出一行，若不存在合法的方案，输出一个字符串impoBGible，否则输出一个整数，表示最少需要多少秒。
【样例输入1】
0 2 9 3 3 7 9 3 5 9 8 3 1 5 8 2 4 7

【样例输出1】
4 impoBGible

【样例1 解释】
对于第一组数据，手指分别在区域1,4,1,4 停留1 秒即可。
【样例2】
Feb
见选手目录下的piranhas/piranhas2.in 与piranhas/piranhas2.ans。
该样例满足测试点4~6 的限制。
【数据规模】
对于 100% 数据，1≤T≤10，1≤n≤1000，1≤k≤n，∑k≤3000，
1≤p1 <p2 <⋯<p𝑘 ≤𝑛，1≤d1 <d2 <⋯<d𝑘 ≤𝑛。
各测试点的附加限制如下表所示：
测试点编号 n<= 特殊性质 1~3 8 无 4~6 20 7~11 200 ∑k≤100 12~15 1000 保证存在方案 16~20 无
Feb
奇怪的等式 （equation）
【题目描述】
BG 有一个正整数序列 a1,a2,...,an，以及一个正整数 P。BG
认为一个整数三元组(i,j,k)是好的，当且仅当同时满足．．．．一下条件： ·1≤i<j<k≤n； ·P=𝑎𝑖
×2⌊log2𝑎𝑗⌋+⌊log2𝑎𝑘⌋+2 +𝑎𝑗 ×2⌊log2𝑎𝑘⌋+1 +𝑎𝑘。 请你帮BG 求出好的三元组数量。 【输入文件】equation.in
本题有多组数据。第一行一个整数T，表示数据组数。每组数据格式如下：
第一行两个整数n,P，表示序列长度和好的三元组判定条件中的参数。
第二行n 个整数a1,a2,...,an，表示BG 的序列。
【输出文件】equation.out
对于每组数据，输出一行，一个整数，表示答案。
【样例输入1】
1 3 94 5 3 2

【样例输出1】
1

【样例1 解释】
唯一的一组好的三元组为(1,2,3)。
【样例2】
见选手目录下equation/equation2.in 与equation/equation2.ans。

【数据范围】
下面用∑𝑛表示单个测试点内所有n 的总和。
对于20%的数据，∑𝑛≤100；
对于40%的数据，∑𝑛≤500；
对于60%的数据，∑𝑛≤3000；
对于70%的数据，∑𝑛≤105；
对于另外10%的数据，𝑎1 =𝑎2 =⋯=𝑎𝑛。
对于另外10%的数据，1≤𝑎𝑖 <512。
对于100%的数据，1≤T≤103,1≤n≤105,∑𝑛≤106,1≤𝑎𝑖 <220,1≤
𝑃<260。
*/