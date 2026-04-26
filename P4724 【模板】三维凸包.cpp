#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const double eps = 1e-9;

struct Point3 {
    double x, y, z;
    Point3() : x(0), y(0), z(0) {}
    Point3(double x, double y, double z) : x(x), y(y), z(z) {}
    Point3 operator-(const Point3 &b) const { return Point3(x - b.x, y - b.y, z - b.z); }
    Point3 operator+(const Point3 &b) const { return Point3(x + b.x, y + b.y, z + b.z); }
    Point3 operator*(double k) const { return Point3(x * k, y * k, z * k); }
    double dot(const Point3 &b) const { return x * b.x + y * b.y + z * b.z; }
    Point3 cross(const Point3 &b) const { return Point3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); }
    double len() const { return sqrt(x * x + y * y + z * z); }
    void read() { cin >> x >> y >> z; }
};

struct Face {
    int v[3];
    Point3 normal; // 法向量，不一定是单位
    bool del;
    Face() : del(false) {}
    Face(int a, int b, int c, const Point3 &n) : del(false) {
        v[0] = a;
        v[1] = b;
        v[2] = c;
        normal = n;
    }
};

// 判断点 p 是否在面 f 的外侧（正方向）
bool outside(const Point3 &p, const Face &f, const vector<Point3> &pts) {
    return f.normal.dot(p - pts[f.v[0]]) > eps;
}

// 计算三角形 (a,b,c) 的法向量（方向与顶点顺序成右手系）
Point3 getNormal(int a, int b, int c, const vector<Point3> &pts) {
    return (pts[b] - pts[a]).cross(pts[c] - pts[a]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point3> pts(n);
    Point3 center(0, 0, 0);
    for (int i = 0; i < n; ++i) {
        pts[i].read();
        center = center + pts[i];
    }
    center = center * (1.0 / n); // 重心，一定在凸包内部

    if (n < 4) {
        cout << "0.000\n";
        return 0;
    }

    // 寻找不共面的四个点
    int p0 = 0;
    int p1 = -1;
    for (int i = 1; i < n; ++i)
        if ((pts[i] - pts[p0]).len() > eps) {
            p1 = i;
            break;
        }
    if (p1 == -1) {
        cout << "0.000\n";
        return 0;
    } // 所有点重合

    int p2 = -1;
    for (int i = 0; i < n; ++i) {
        if (i == p0 || i == p1)
            continue;
        if ((pts[p1] - pts[p0]).cross(pts[i] - pts[p0]).len() > eps) {
            p2 = i;
            break;
        }
    }
    if (p2 == -1) {
        cout << "0.000\n";
        return 0;
    } // 所有点共线

    int p3 = -1;
    Point3 baseNormal = getNormal(p0, p1, p2, pts);
    for (int i = 0; i < n; ++i) {
        if (i == p0 || i == p1 || i == p2)
            continue;
        if (fabs(baseNormal.dot(pts[i] - pts[p0])) > eps) {
            p3 = i;
            break;
        }
    }
    if (p3 == -1) { // 所有点共面，这里简单返回 0（题目数据不会出现）
        cout << "0.000\n";
        return 0;
    }

    vector<Face> faces;

    // 根据重心将面转为朝向外部
    auto addFace = [&](int a, int b, int c) {
        Face f(a, b, c, getNormal(a, b, c, pts));
        if (f.normal.dot(center - pts[a]) > 0) {
            swap(f.v[1], f.v[2]);
            f.normal = f.normal * -1.0;
        }
        faces.push_back(f);
    };

    // 初始四面体（保证体积为正）
    double vol = getNormal(p0, p1, p2, pts).dot(pts[p3] - pts[p0]);
    if (vol < 0)
        swap(p1, p2);
    addFace(p0, p1, p2);
    addFace(p0, p2, p3);
    addFace(p0, p3, p1);
    addFace(p1, p3, p2);

    // 增量构建
    for (int i = 0; i < n; ++i) {
        if (i == p0 || i == p1 || i == p2 || i == p3)
            continue;
        bool vis = false;
        for (auto &f : faces) {
            if (f.del)
                continue;
            if (outside(pts[i], f, pts)) {
                f.del = true;
                vis = true;
            }
        }
        if (!vis)
            continue; // 点在凸包内部

        // 统计边界边
        map<pair<int, int>, int> cnt;
        for (const auto &f : faces) {
            if (!f.del)
                continue;
            int a = f.v[0], b = f.v[1], c = f.v[2];
            cnt[{min(a, b), max(a, b)}]++;
            cnt[{min(b, c), max(b, c)}]++;
            cnt[{min(c, a), max(c, a)}]++;
        }

        vector<pair<int, int>> border;
        for (const auto &e : cnt)
            if (e.second == 1)
                border.push_back(e.first);

        // 删除标记的面
        faces.erase(remove_if(faces.begin(), faces.end(),
                              [](const Face &f) { return f.del; }),
                    faces.end());

        // 为新点创建新面
        for (const auto &e : border) {
            int u = e.first, v = e.second;
            Face f(v, u, i, getNormal(v, u, i, pts)); // 尝试顺序
            if (f.normal.dot(center - pts[f.v[0]]) > 0) {
                swap(f.v[1], f.v[2]);
                f.normal = f.normal * -1.0;
            }
            faces.push_back(f);
        }
    }

    // 计算表面积
    double ans = 0.0;
    for (const auto &f : faces)
        if (!f.del)
            ans += 0.5 * getNormal(f.v[0], f.v[1], f.v[2], pts).len();

    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}