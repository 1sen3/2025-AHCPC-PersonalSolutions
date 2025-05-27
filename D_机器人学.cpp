#include <bits/stdc++.h>
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 21;

struct Point {
    double x, y;
};

struct Line {
    Point origin; // 原点坐标
    double angle; // 与 x 轴夹角
};

// 计算直线斜率 k = tanθ
double getSlope(Line& l) {
    return tan(l.angle);
}

// 计算直线的截距 b = y - k * x
double getIntercept(Line& l) {
    double k = getSlope(l);
    return l.origin.y - k * l.origin.x;
}

// 检查两条直线是否相交
bool areLinesIntersecting(Line& L1, Line& L2) {
    double k1 = getSlope(L1);
    double k2 = getSlope(L2);
    return (k1 != k2);  // 斜率不等则相交
}

// 计算两条直线的交点
Point findIntersection(Line& L1, Line& L2) {
    double A1 = getSlope(L1);
    double B1 = -1;
    double C1 = getIntercept(L1);

    double A2 = getSlope(L2);
    double B2 = -1;
    double C2 = getIntercept(L2);

    double D = A1 * B2 - A2 * B1;
    if (D == 0) {
        return {NAN, NAN};  // 平行或重合，无交点
    }

    double x = (B1 * C2 - B2 * C1) / D;
    double y = (A2 * C1 - A1 * C2) / D;
    return {x, y};
}

// 计算三角形面积
double computeTriangleArea(Point A, Point B, Point C) {
    double area = 0.5 * std::abs(
        (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)
    );
    return area;
}

// 计算三条直线围成的面积
double computeAreaFromThreeLines(Line& L1, Line& L2, Line& L3) {
    Point P12 = findIntersection(L1, L2);
    Point P13 = findIntersection(L1, L3);
    Point P23 = findIntersection(L2, L3);

    return computeTriangleArea(P12, P13, P23);
}

void solve() {
    int n;
    double r;
    cin >> n >> r;
    double area_ball = M_PI * r * r * 1.5;
    Line robots[N];
    for (int i = 1; i <= n; ++i) {
        double x, y, vec, pos;
        cin >> x >> y >> vec >> pos;
        robots[i].origin = {x, y};
        robots[i].angle = vec + pos;
        robots[i].angle = robots[i].angle * M_PI / 180.0; // 转换为弧度
        // cout << x << " " << y << " " << vec << " " << pos << endl;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (areLinesIntersecting(robots[i], robots[j]) &&
                    areLinesIntersecting(robots[i], robots[k]) &&
                    areLinesIntersecting(robots[j], robots[k])) {
                    double area = computeAreaFromThreeLines(robots[i], robots[j], robots[k]);
                    // cout << area << " " << area_ball << endl;
                    if (area < area_ball) {
                        YES;
                        return;
                    }
                }
            }
        }
    }
    NO;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}