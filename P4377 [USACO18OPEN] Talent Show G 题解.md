# P4377 [USACO18OPEN] Talent Show G 题解

二分整数答案 $x=\lfloor1000T/W\rfloor$。把每头牛的贡献改成 $1000t_i-xw_i$，用背包判断能否选出总重量至少为 $W$ 且新贡献和非负的集合；重量超过 $W$ 后统一压到 $W$。时间复杂度 $O(NW\log 10^6)$。
