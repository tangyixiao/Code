# P12104 [NERC2024] Managing Cluster

## 题目描述

你打算开发一个集群管理扩展，以提升产品性能。你的产品包含 $n$ 个服务（编号从 $1$ 到 $n$），运行在一个拥有 $2n$ 台机器（编号从 $1$ 到 $2n$）的集群上。每个服务运行恰好两个副本，每个副本部署在某台机器上。每台机器恰好运行一个服务的副本。

这个集群性能的关键因素之一是网络结构。一些机器之间存在直接连接，能够高效传输数据。一共存在 $2n - 1$ 条直接连接，并且任意两台机器之间都可以通过这些连接实现通信。换句话说，这些直接连接构成了一棵树。

部署过程中，$2n$ 个副本已分配到机器。你的扩展程序将获取所有直接连接的信息，以及一个长度为 $2n$ 的序列 $a_1,a_2,\ldots,a_{2n}$，其中 $a_i$ 表示第 $i$ 台机器上运行的服务编号。

你的程序可以对副本进行交换操作。一次交换操作选定两台机器 $i$ 和 $j$，交换 $a_i$ 和 $a_j$ 的值。每台机器最多参与一次交换操作。

你需要设计一组交换操作，以使集群性能最大化。

由于同一服务的两个副本之间的数据交换最为频繁，集群性能定义为：有多少个服务的两个副本位于一对直接连接的机器上。

请你编写程序，输出一组交换操作，使得集群性能最大。

## 输入格式

第一行包含一个整数 $T\;(1 \leq T \leq 10^5)$，表示测试用例的数量。

每组测试用例包括如下内容：

- 第一行一个整数 $n\;(1 \leq n \leq 10^5)$，表示服务数量；
- 第二行 $2n$ 个整数 $a_1,a_2,\ldots,a_{2n}$（$1 \leq a_i \leq n$），表示每台机器当前运行的服务编号。保证每个服务编号出现恰好两次；
- 接下来的 $2n - 1$ 行，每行两个整数 $u,v$（$1 \leq u,v \leq 2n$，$u \ne v$），表示第 $u$ 台机器与第 $v$ 台机器之间存在直接连接。保证这些连接构成一棵树。

保证所有测试用例中 $n$ 的总和不超过 $10^5$。

## 输出格式

对于每组测试用例：

- 第一行输出一个整数 $k\;(0 \leq k \leq n)$，表示进行的交换操作次数；
- 接下来的 $k$ 行，每行输出两个整数 $i$ 和 $j$（$1 \leq i,j \leq 2n$，$i \ne j$），表示将第 $i$ 台机器和第 $j$ 台机器上的服务副本进行交换。注意，每台机器至多参与一次交换。

交换操作的顺序无关紧要。交换完成后，集群性能必须达到最大。输出任意一组满足条件的解均可。

## 输入输出样例 #1

### 输入 #1

```
3
2
1 2 2 1
1 2
2 3
3 4
4
4 3 1 3 2 4 1 2
1 2
3 1
3 4
5 1
5 6
2 7
2 8
3
1 1 2 2 3 3
1 2
1 3
1 4
1 5
1 6
```

### 输出 #1

```
1
1 3
3
1 5
8 3
4 7
0
```

## 说明/提示

在第一个测试用例中，只有服务 $2$ 的两个副本处于相邻的机器上，因此性能为 $1$。通过交换机器 $1$ 和 $3$ 上的副本，可以使服务 $1$ 和服务 $2$ 的副本都位于相邻机器上，性能提升至 $2$。

![](https://cdn.luogu.com.cn/upload/image_hosting/6cp342uy.png)

在第二个测试用例中，没有任何服务的副本处于相邻机器上，初始性能为 $0$。通过交换 $(1,5)$，$(8,3)$ 和 $(4,7)$ 三对机器，可以让服务 $2$、$3$ 和 $4$ 的副本分别配对，从而性能提升到 $3$。可以证明此时无法再提升至 $4$。

![](https://cdn.luogu.com.cn/upload/image_hosting/ljhz2pf2.png)

在第三个测试用例中，只有服务 $1$ 的两个副本在相邻机器上，性能为 $1$，且无法进一步提升。

![](https://cdn.luogu.com.cn/upload/image_hosting/ss4oj9ok.png)

---



# P12104 [NERC2024] Managing Cluster

## 题目描述

You want to write a cluster manager extension that will improve your product performance. Your product has $n$ services (numbered from $1$ to $n$) and is hosted on a cluster with $2n$ machines (numbered from $1$ to $2n$). Each service is running in exactly two replicas. Each replica is run on some machine. Each machine runs exactly one replica of some service.

One of the key factors of this cluster's performance is the network. Some pairs of machines are connected directly and can transfer data between them very efficiently. There are exactly $2n-1$ direct connections, and it is possible to transfer data between any two machines using direct connections. In other words, direct connections form a tree.

During the deployment, all $2n$ replicas were assigned to machines. Your extension gets the direct connections list and the sequence $a_1, a_2, \ldots, a_{2n}$, where $a_i$ is the number of the service that will be running on machine $i$. Your extension can swap some replicas between machines. The swap operation takes two machines $i$, $j$ and swaps values $a_i$ and $a_j$. Each machine is allowed to participate in at most one swap operation. Your extension should make some swap operations that maximize the cluster performance.

Due to the fact that most data will be transferred between two replicas of the same service, the cluster performance is measured as the number of services that have two replicas running on machines connected directly. Help to write the extension that will maximize the cluster performance.

## 输入格式

The first line contains a single integer $T$ ($1 \leq T \leq 10^5$) --- the number of test cases. Descriptions of test cases follow.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$).

The second line contains $2n$ integers $a_1, a_2, \ldots, a_{2n}$ ($1 \leq a_i \leq n$). It is guaranteed that each value from $1$ to $n$ appears exactly twice in this sequence.

Each of the next $2n-1$ lines contains two integers $u$ and $v$ ($1 \leq u, v \leq 2n$, $u \neq v$), meaning that machines $u$ and $v$ are connected directly. Direct connections are guaranteed to form a tree.

It is guaranteed that the sum of $n$ for all test cases does not exceed $10^5$.

## 输出格式

For each test case on the first line print a single integer $k$ ($0 \leq k \leq n$) --- the number of swap operations the extension wants to make.

Each of the next $k$ lines should contain two integers $i$, $j$ ($1 \leq i, j \leq 2n$, $i \neq j$) --- swap operations. Each number from $1$ to $2n$ should appear at most once.

Note that the order of operations is not important. After applying swap operations, the cluster performance should be the maximum possible. You can print any answer that satisfies the requirements.

## 输入输出样例 #1

### 输入 #1

```
3
2
1 2 2 1
1 2
2 3
3 4
4
4 3 1 3 2 4 1 2
1 2
3 1
3 4
5 1
5 6
2 7
2 8
3
1 1 2 2 3 3
1 2
1 3
1 4
1 5
1 6
```

### 输出 #1

```
1
1 3
3
1 5
8 3
4 7
0
```

## 说明/提示

In the first test case only replicas of service 2 run on directly connected machines, so the performance is 1. The performance can be increased to 2 by swapping replicas between machines 1 and 3.

![](https://cdn.luogu.com.cn/upload/image_hosting/6cp342uy.png)

In the second test case no two replicas run on directly connected machines, so the performance is zero. The performance can be increased to 3 by performing swaps $1-5$, $8-3$, and $4-7$ so that replicas of services 2, 3, and 4 run on directly connected machines. It can be shown that it is impossible to get performance 4 here. 

![](https://cdn.luogu.com.cn/upload/image_hosting/ljhz2pf2.png)

In the third test case only replicas of service 1 run on directly connected machines, so the performance is 1. It is obvious that here the performance cannot be made any bigger.

![](https://cdn.luogu.com.cn/upload/image_hosting/ss4oj9ok.png)




