# Domino and Tromino Tiling

```text
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You
may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since
the answer may be very large, return it modulo 10^9 + 7.

In a tiling, every square must be covered by a tile. Two tilings are
different if and only if there are two 4-directionally adjacent cells on the
board such that exactly one of the tilings has both squares occupied by a tile.
```

## Example 1

```text
Input: n = 3
Output: 5
Explanation: The five different ways are show above.
```

## Example 2

```text
Input: n = 1
Output: 1
```

## Constraints

```text
1 <= n <= 1000
```

## 问题分析

这道题的难点(趣味)在于分析、归纳 n 之间的递推关系
| n | 1 | 2 | 3 | 4 | 5 |
| ---- | --- | --- | --- | --- | --- |
| s[n] | 1 | 2 | 5 | 11 | 24 |

规律：`s[n]=2*s[n-1]+s[n-3]`
