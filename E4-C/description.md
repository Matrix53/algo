## 题目描述

$Matrix53$ 喜欢在微信群里潜水，他只会发表情包。

$Matrix53$ 有 $n$ 个表情可以发送，这 $n$ 个表情拥有严格递增的正整数标号，分别为 $s\_1,s\_2...s\_n$。

在发送表情的前一刻，$Matrix53$ 会灵机一动，从脑海里找到表情的标号。

但是 $Matrix53$ 的记忆不一定是正确的，他有可能想到错误的标号，这时由于 $Matrix53$ 找不到对应标号的表情，所以这时他不会发表情包。

$Matrix53$ 想到正确的标号 $s\_1,s\_2...s\_n$ 的频率分别为 $f\_1,f\_2...f\_n$。

$Matrix53$ 想到错误的标号的频率分别为 $p\_0,p\_1...p\_n$，设 $Matrix53$ 想到的标号为 $t$，有：

$p\_0=P(t < s\_1)，p\_n=P(t > s\_n)，p\_i(0 < i < n)=P(s_i < t < s\_{i+1})$，其中 $P(x)$表示事件发生的频率。

$Matrix53$ 上过算法课，他将这 $n$ 个表情以标号为键构建了一颗二叉搜索树。

也就是说，对于这棵树的任意一颗子树，若记子树树根为 $x$，则：

$x$ 的标号大于 $x$ 的左子树的所有结点的标号，$x$ 的标号小于 $x$ 的右子树的所有结点的标号。

对于一次搜索，$Matrix53$ 会用标号从树根开始检索表情，当他找到表情或者能够判定找不到表情时，他会结束这次搜索，本次搜索的搜索代价为搜索的深度。

**搜索的深度定义为：**

- 若要搜索的标号是树根结点的标号，则搜索深度为 $1$，即树根结点的搜索深度为 $1$
- 若要搜索的标号为结点 $x$ 的某个子结点的标号，则搜索深度为结点 $x$ 的搜索深度加 $1$
- 若搜索到了结点 $x$ 处，但是想要搜索的结点编号比$x$大(小)，且$x$没有右(左)子树，则判定找不到表情，搜索深度为结点 $x$ 的搜索深度

$Matrix53$ 所构建的这棵树具有这样的性质，即在上述搜索频率下，搜索代价之和最小，记该最小值为 $Ans$。

求 $Ans$。

## 输入

第一行为一个正整数，表示 $n$

第二行 $n$ 个正整数，分别表示 $f\_1,f\_2...f\_n$

第三行 $n+1$ 个正整数，分别表示 $p\_0,p\_1...p\_n$

## 输出

输出一行，$Ans$ 的值

## 输入样例

    3
    1 2 3
    1 2 3 4

## 输出样例

    29

## 数据范围

$3\leq n \leq 500$

$1\leq f_i \leq 10^8$

$1\leq p_i \leq 10^8$

## Hint

1. 最优二叉搜索树
2. 仔细看搜索深度的定义
3. 本题的数据削弱过