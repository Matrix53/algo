## 题目描述

Alex 送了 Matrix53 一张有$n$个点，$m$条边的无向联通图作为生日礼物。

但是 Matrix53 不喜欢这张平平无奇的图，他比较喜欢树，于是他决定从图中取出一棵生成树$T$。

Matrix53 取出第$i$条边会耗费他$a\_i$点体力，同时会收获$b\_i$点愉悦值，Matrix53 希望他取出来的树满足树中各边的愉悦值之和除以体力之和，即$\sum\_{i \in T} b\_i$ 与 $ \sum\_{i \in T} a_i$的比值最大。

但是 Matrix53 忙着做实验，于是把这个问题拜托给了聪明的你。

## 输入

第一行两个整数$n, m(1 \leq n, m \leq 10^5)$，表示这张图有$n$个点$m$条边。

接下来的$m$行描述$m$条边，每行四个整数$u, v, a, b(1 \leq u, v \leq n, u \ne v, 1 \leq a, b \leq 10^4)$，表示点$u$和点$v$之间存在一条取出来会耗费$a$点体力并收获$b$点愉悦值的边。可以有重边。

## 输出

一个浮点数，为最大的比值，保留到小数点后三位。

## 输入样例

    4 6
    1 2 1 3
    1 3 1 4
    1 4 1 5
    2 3 2 3
    2 4 2 4
    3 4 3 3

## 输出样例

    4.000

## 输入样例 2

    6 10
    2 1 5 5
    3 1 7 5
    4 2 2 9
    5 2 8 1
    6 4 5 10
    3 2 5 6
    6 5 3 6
    5 1 7 6
    4 2 10 3
    5 1 1 7

## 输出样例 2

    2.375