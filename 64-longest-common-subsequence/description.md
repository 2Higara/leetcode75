# Longest Common Subsequence

Given two strings `text1` and `text2`, return the length of their longest
common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative
order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both
strings.

## Example 1

Input: `text1` = "abcde", `text2` = "ace"
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

## Example 2

Input: `text1` = "abc", `text2` = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

## Example 3

Input: `text1` = "abc", `text2` = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

## Constraints

1 <= `text1.length`, `text2.length` <= 1000
`text1` and `text2` consist of only lowercase English characters.

## Solution

## 二维数组

A(i,j) 代表 “text1 的前 i 个字符和 text2 的前 j 个字符的最大匹配长度”

更新时:

- 如果 text1[i] == text2[j], 则 A(i,j) = A(i-1,j-1)+1
- 否则，A(i, j) = max(A(i,j-1), A(i-1,j))

|     | 0   | a   | a   | a   |
| --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   |
| a   | 0   | 1   | 1   | 1   |
| a   | 0   | 1   | 2   | 2   |
| a   | 0   | 1   | 2   | 3   |

这种做法空间复杂度很大 O(m\*n)，因此要考虑节省空间的算法

### 单个 1 维数组代替二维数组

顺序遍历：

- 理想情况
  | | 0 | a | b | c |
  | --- | --- | --- | --- | --- |
  | 0 | 0 | 0 | 0 | 0 |
  | a | 0 | 1 | 1 | 1 |
  | b | 0 | 1 | 2 | 2 |
  | c | 0 | 1 | 2 | 3 |
- 串扰情况

  |     | 0   | a   | a   | a   |
  | --- | --- | --- | --- | --- |
  | 0   | 0   | 0   | 0   | 0   |
  | a   | 0   | 1   | 2   | 3   |

因此，为了避免遍历时的数据串扰，只能反向遍历:

- 理想情况

  |     | 0   | a   | c   | e   |
  | --- | --- | --- | --- | --- |
  | 0   | 0   | 0   | 0   | 0   |
  | a   | 0   | 1   | 0   | 0   |
  | b   | 0   | 1   | 1   | 0   |
  | c   | 0   | 1   | 2   | 1   |
  | d   | 0   | 1   | 2   | 2   |
  | e   | 0   | 1   | 2   | 3   |

- 但如果 text1 长度较小，每行中前面的结果可能还没更新到后面，后面的未更新数据就被新遍历使用了

|     | 0   | a   | b   | c   | d   | e   |
| --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| a   | 0   | 1   | 0   | 0   | 0   | 0   |
| c   | 0   | 1   | 1   | 1   | 0   | 0   |
| e   | 0   | 1   | 1   | 1   | 1   | 1   |

在用例比较严格的情况下，这种方法并不适用

### 两个 1 维数组

由于每轮遍历只需要参考上一次遍历的结果，对更早的遍历结果不作要求，因此可以使用两个一维数组模拟二维数组：
一个数组存储上一轮的结果，一个数组存储本轮的结果，一轮遍历结束后，交换两个数组即可

这种方法空间复杂度为 O(2\*n)，显然更优
