# Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each
i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

## Example 1

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

## Example 2

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
6 --> 110
7 --> 111
8 --> 100

## Constraints

0 <= n <= 10^5

## Follow up

It is very easy to come up with a solution with a runtime of O(n log n). Can
you do it in linear time O(n) and possibly in a single pass?

Can you do it without using any built-in function (i.e., like \_\_builtin_popcount in C++)?

## Solution

根据 `count_1(n) = (n & 1) + count_1(n >> 1)`，从小到大遍历

并且对于 n > 0 来说, (n+1)/2 <= n，因此每个数的一半必然已经遍历过，
可以直接查询结果表，无需额外判断是否需要重新计数:
`rs[n] = (n&1) + rs[n>>1]`
