# Minimum Flips to Make a OR b Equal to c

Given 3 positives numbers a, b and c. Return the minimum flips required in
some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0
to 1 in their binary representation.

## Example 1

Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

## Example 2

Input: a = 4, b = 2, c = 7
Output: 1

## Example 3

Input: a = 1, b = 2, c = 3
Output: 0

## Constraints

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9

## Solution

逐位判断是否一致，若不一致，统计翻转数目

- b(c) = 1, b(a|b) = 0

  - b(a) = 0, b(b) = 0，翻转 1 位即可
  - count+=1

- b(c) = 0, b(a|b) = 1

  - b(a) = 1, b(b) = 0, 翻转 1 位
  - b(a) = 1, b(b) = 1, 翻转 2 位
  - count+=b(a)+b(b)

- 用 check = (a|b)^c 来标注哪些位需要修改
  | num | num_b |
  | ---------- | ----- |
  | a | 1000 |
  | b | 1011 |
  | c | 0101 |
  | rs=a\|b | 1011 |
  | check=rs^c | 1110 |
