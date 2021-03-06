## 题目描述

有一块圆形镜子，有一束不消失的光。

![](https://s3.bmp.ovh/imgs/2021/11/6321867ea980ce01.png)

光从圆 O 上一点 A 出发，在镜子内部不断沿逆时针反射，圆内有一点为 K。

$Matrix53$ 想知道：光能经过点 K 吗？

**P.S.**两个浮点数之差的绝对值小于 1e-6 时，认为两个浮点数相等

## 输入

第一行两个数，为圆心 O 的坐标$(x\_O,y\_O)$

第二行三个数，为点 A 的坐标$(x\_A,y\_A)$，以及弦 AB 的弦切角$\alpha$(B 为光第一次发生反射时的入射点，单位：角度)

第三行两个数，为点 K 的坐标$(x\_K,y\_K)$

## 输出

若光能经过点 K，输出第一次经过点 K 时光的反射次数，若不能则输出-1

## 输入样例

    0 0
    0 -1 45
    0.5 0.5

## 输出样例

    1

## 数据范围

$1 \leq \alpha \leq 90 $，且为整数
