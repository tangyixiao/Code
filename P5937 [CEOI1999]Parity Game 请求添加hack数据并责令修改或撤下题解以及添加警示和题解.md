$\tt{root}$，虽然这个题目是 1999 年的 CEOI 的比赛题，数据可能比较水，这是可以理解的。

但是，作为一种比较重要的数据结构，并查集或某篇题解中提到的二分图，和重要的技巧离散化，在竞赛中比较常用，所以不能根据其历史价值而忽视了训练价值。

---

在校内模拟赛考到，用人肉原题机搜到了这题，本着求真探索的念头，我测试题解如下：

![](https://cdn.luogu.com.cn/upload/image_hosting/vmjm5vx5.png)

这是使用 LemonLime 测评的结果，我怀疑不准，又到洛谷评测机上测试未通过的题解：

![](https://cdn.luogu.com.cn/upload/image_hosting/gkqzcn70.png)

发现结果同上。

综上，我们得出结果：

- @[EternalEpic](luogu://user/50925) 有两种解法，但是他在剪贴板中只提供了一种，这种解法是不正确的，另一种是代码片段。

- @[liangbowen](luogu://user/367488)、@[二狗子](luogu://user/86437) 的两种解法都无法通过，@[_Rain](luogu://user/833476)、@[Eleven谦](luogu://user/145205) 也无法通过。

- 其余人的题解没什么大问题。

我还观察发现 @[bellmanford](luogu://user/116015) 的题解中，有一处错误：时间复杂度应为 $O(m^2 \log^2 m)$，而非 $O(n^2 \log^2 n)$，不过相信大众可以理解所以并不是大问题。

---

接下来是 hack 数据的添加。

详见 [U653053 P5937 [CEOI 1999] Parity Game（加强版）](https://www.luogu.com.cn/problem/U653053) 的附件。

---

最后，我申请添加我自己的题解。

[https://www.luogu.com.cn/article/v6qkt4c5](https://www.luogu.com.cn/article/v6qkt4c5)

