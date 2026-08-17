# P9444 [ICPC 2021 WF] Islands from the Sky

## 题目描述

你可能从未听说过 Iceepeecee 群岛，但这正是他们的居民所希望的。位于南太平洋的一个偏远地区，它们真正远离人迹罕至的地方，没有任何定期的空中或海上交通，仍然是一个未受破坏的热带天堂，拥有未受破坏的当地动植物。

当你不想被成群的游客淹没时，远离地图是很好的，但当你确实需要地图时就不太理想了。最近出现了一个这样的原因：Iceepeecee 的中央政府需要一个精确的岛屿地图来分配政府资金。即使是热带天堂也需要钱，所以 Iceepeecee 需要一张地图！

创建地图的最简单方法是航空测量。在认为包机太贵、建造气球太危险、给信鸽装上相机对动物太残忍之后，他们有了一个绝妙的主意。即使在这个偏远的地方，仍然有很多商业飞机飞过 Iceepeecee 上空。如果在已经计划飞行的航班上安装相机呢？这将是一个解决问题的廉价方案！

Iceepeecee 的计划是在飞机上安装线扫描相机。这些相机垂直向下拍摄，每次收集一条线段的图像，与飞行路径正交。拍摄的线段将由飞机的飞行高度和相机的光圈角度 $\theta$ 决定（见图 F.1）。更大的角度 $\theta$ 意味着相机可以看到更多，但也意味着相机更贵。

此外，Iceepeecee 希望确保每个岛屿都能被至少一次航班完整观察到。这意味着不够仅仅通过多次航班部分拍摄到一个岛屿，即使这些照片的组合覆盖了整个岛屿。

图 F.1：飞机的正面视图。其相机向下拍摄，可以看到飞机下方的绿色部分。可见的范围取决于光圈角度 $\theta$。

飞行路径在三维空间中沿直线段，即 ($x_1, y_1, z_1$) $-$ ($x_2, y_2, z_2$)（见图 F.2），其中 $z$ 坐标给出飞机的高度。照片仅在这些线段上拍摄。

给定他们的岛屿和航班的位置，Iceepeecee 想要找到允许成功测量的最小光圈角度 $\theta$。你能帮忙吗？

图 F.2：三个岛屿（以黑色显示）和两条飞行路径（红色和绿色）。未显示高度。阴影区域表示在最佳选择的 $\theta$ 下两条飞行路径上可见的地面。这对应于第一个样例输入。

## 输入格式

输入描述了一组岛屿和飞行路径。首先是一行包含两个整数 $n$ 和 $m$，分别表示岛屿的数量 $n$ 和飞行路径的数量 $m$（$1 \leq n,m \leq 100$）。接下来是 $n$ 个岛屿的描述。每个岛屿描述以一行开始，包含一个整数 $n_i$，表示描述第 $i$ 个岛屿的多边形的顶点数（$3 \leq n_i \leq 100$）。接下来是 $n_i$ 行，每行包含两个整数 $x_{ij}$，$y_{ij}$（$|x_{ij}|, |y_{ij}| \leq 10^6$），按逆时针顺序指定第 $i$ 个岛屿的顶点。每个岛屿的多边形是简单的，即其顶点是不同的，且多边形的边不相交或接触，除了相邻的边在其公共顶点处接触。不同的岛屿不相交或接触。

输入以另外 $m$ 行结束，每行描述一条飞行路径。每行包含六个整数 $x_1$，$y_1$，$z_1$，$x_2$，$y_2$，$z_2$（$|x_i|, |y_i|, |z_i| \leq 10^6$，$z_i > 0$ 且 ($x_1, y_1$) $
eq$ ($x_2, y_2$)）。它们指定了一次从 ($x_1, y_1, z_1$) 到 ($x_2, y_2, z_2$) 的飞行。

## 输出格式

输出允许使用给定航班对岛屿进行完整测量的最小角度 $\theta$（以度为单位）。答案应精确到绝对或相对误差 $10^{-6}$。如果没有这样的角度，则输出 $\texttt{impossible}$。输入被选择为，如果岛屿顶点的坐标最多改变 $\pm 10^{-8}$，则答案不会超过允许的舍入误差。

## 输入输出样例 #1

### 输入 #1

```
3 2
3
20 30
50 50
10 50
4
40 20
60 10
75 20
60 30
4
45 60
55 55
60 60
55 65
0 30 20 78 70 5
55 0 20 70 60 10

```

### 输出 #1

```
48.031693036

```

## 输入输出样例 #2

### 输入 #2

```
1 1
4
0 0
10 0
10 10
0 10
5 5 10 15 5 10

```

### 输出 #2

```
impossible

```

## 说明/提示

题面翻译由 ChatGPT-4o 提供。

---

# P9444 [ICPC 2021 WF] Islands from the Sky

## 题目描述

You might never have heard of the island group of Iceepeecee, but that suits their inhabitants just fine. Located in a remote part of the South Pacific, they are truly off the beaten track, without any regular air or sea traffic, and they have remained a tropical paradise with unspoiled local fauna and flora.

Being off the map is great when you don't want to be overrun by hordes of tourists, but not so ideal when you actually do need a map for some reason. One such reason came up recently: Iceepeecee's central government needs an exact map of the islands to apportion government funds. Even tropical paradises need money, so Iceepeecee needs a map!

The easiest way to create a map would be an aerial survey. After dismissing chartering planes as too expensive, building an air balloon as too dangerous, and fitting carrier pigeons with cameras as too cruel to animals, they had a brilliant idea. Even with its remote location, there are still plenty of commercial airplanes crossing the skies above Iceepeecee. What if one mounted cameras on flights that are already scheduled to fly anyway? That would be a cheap solution to the problem!

Iceepeecee's plan is to install line-scan cameras on the planes. These cameras point straight downwards and collect images one line segment at a time, orthogonal to the flight path. The photographed line segment will be determined by the altitude that the plane is flying at, and the camera's aperture angle $\theta$ (see Figure F.1). Greater angles $\theta$ mean that the camera can see more, but also that the camera is more expensive.

Moreover, Iceepeecee wants to make sure that each island is observed in its entirety by at least one flight. That means it is not sufficient that an island is only partially photographed by multiple flights, even if the combination of the photographs covers the whole island.

![](https://cdn.luogu.com.cn/upload/image_hosting/99wwtofi.png)

Figure F.1: A view of the plane, shown head-on. Its camera points downward and can see the part of the ground underneath the plane that is shown in green. How much is visible depends on the aperture angle $\theta$.
  
Flight paths follow straight line segments in three-dimensional space, that is, ($x_1, y_1, z_1$) $-$ ($x_2, y_2, z_2$) (see Figure F.2), where the $z$-coordinates give the altitude of the plane. Photographs are taken only along these line segments.

Given the location of their islands and flights, Iceepeecee wants to find the smallest aperture angle $\theta$ that allows for a successful survey. Can you help?

![](https://cdn.luogu.com.cn/upload/image_hosting/3pdn3q1b.png)

Figure F.2: Three islands (shown in black) and two flight paths (red and green). Altitudes are not shown. The shaded areas represent the ground visible on the two flight paths for an optimally chosen $\theta$. This corresponds to the first sample input.Three islands (shown in black) and two flight paths (red and green). Altitudes are not shown. The shaded areas represent the ground visible on the two flight paths for an optimally chosen $\theta$. This corresponds to the first sample input.

## 输入格式

The input describes a set of islands and flight paths. It starts with a line containing two integers $n$ and $m$, the number $n$ of islands, and the number $m$ of flight paths, respectively ($1 \leq n,m \leq 100$). This is followed by descriptions of the $n$ islands. Each island description starts with a line containing a single integer $n_i$, the number of vertices of the polygon describing the $i^{th}$ island ($3 \leq n_i \leq 100$). It is followed by $n_i$ lines, each containing two integers $x_{ij}$, $y_{ij}$ ($|x_{ij}|, |y_{ij}| \leq 10^6$), specifying the vertices for the $i^{th}$ island in counterclockwise order. Each island's polygon is simple, that is, its vertices are distinct and no two edges of the polygon intersect or touch, other than consecutive edges which touch at their common vertex. Different islands do not intersect or touch.

The input concludes with another $m$ lines, each describing a flight path. Each such line contains six integers $x_1$, $y_1$, $z_1$, $x_2$, $y_2$, $z_2$ ($|x_i|, |y_i|, |z_i| \leq 10^6$, $z_i \gt 0$ and ($x_1, y_1$) $\neq$ ($x_2, y_2$)). They specify that a flight takes place from ($x_1, y_1, z_1$) to ($x_2, y_2, z_2$).

## 输出格式

Output the smallest angle $\theta$ (in degrees) that allows for a complete survey of the islands with the given flights. The answer should be exact to an absolute or relative error of $10^{-6}$. If there is no such angle, then output $\texttt{impossible}$. The input is chosen such that if the coordinates of the island vertices are changed by at most $\pm 10^{-8}$, then the answer will not change more than the allowed rounding error.

## 输入输出样例 #1

### 输入 #1

```
3 2
3
20 30
50 50
10 50
4
40 20
60 10
75 20
60 30
4
45 60
55 55
60 60
55 65
0 30 20 78 70 5
55 0 20 70 60 10

```

### 输出 #1

```
48.031693036

```

## 输入输出样例 #2

### 输入 #2

```
1 1
4
0 0
10 0
10 10
0 10
5 5 10 15 5 10

```

### 输出 #2

```
impossible

```