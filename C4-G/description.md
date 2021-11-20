## 题目描述

$Serein$、$Alex$、$Matrix53$ 想要合作做一个单周期 $CPU$。

$Serein$ 想用 $Logisim$ 画 $CPU$，但是 $Matrix53$ 不喜欢用 $Logisim$。

$Serein$：$emm$...这样吧，我给你们出一道题，你们做出来了我们就用 $Verilog$ 来写 $CPU$。

$Serein$(自顾自地说)：有两个正整数数列 $A$ 和 $B$，每个数列都有 $n$ 个互不相同的元素，不妨假设为$a\_1,a\_2...a\_n$和$b\_1,b\_2...b\_n$。可以任意次交换数列 $A$ 中两个元素的位置，求$\Pi\_{i=1}^{n}(a\_i^{b\_i})$的**最大**值。

$Matrix53$(一段时间后)：我已经交换好了，先去买瓶可乐，等我回来就给你们讲思路和证明。

其实 $Alex$ 也想用 $Logisim$，于是他趁着 $Matrix53$ 买饮料的时候做了一件事，他重新排列了数列 $B$ 中的元素，现在$\Pi\_{i=1}^{n}(a\_i^{b\_i})$的值是**最小**的了，而 $Serein$ 对此睁一只眼闭一只眼。

你能看透 $Alex$ 重新排列数列 $B$ 后，数列 $B$ 的样子吗？

## 输入

第一行一个正整数，为 $n$

第二行 $n$ 个正整数，为 $b\_1,b\_2...b\_n$

## 输出

输出一行，为$b\_1,b\_2...b\_n$，两个数之间以空格分隔

**注意**：这里输出的数列 $B$，为 $Alex$ 重新排列后的数列 $B$

## 输入样例

    3
    1 2 3

## 输出样例

    3 2 1

## 数据范围

$3\leq n \leq 10^5$

$1\leq b\_i \leq 10^7$