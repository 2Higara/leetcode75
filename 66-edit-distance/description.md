# Edit Distance

Given two strings word1 and word2, return the minimum number of operations
required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

## Example 1

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

## Example 2

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

## Constraints

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

## Solution

最小编辑距离问题， A(i,j) 代表 word1 的前 i 个字符转换为 word2 的前 j 个字符的最小距离

|     | 0   | r   | o   | s   |
| --- | --- | --- | --- | --- |
| 0   | 0   | 1   | 2   | 3   |
| h   | 1   | 1   | 2   | 3   |
| o   | 2   | 2   | 1   | 2   |
| r   | 3   | 2   | 2   | 2   |
| s   | 4   | 3   | 3   | 2   |
| e   | 5   | 4   | 4   | 3   |

1. word1(i) == word2(j) 时, A(i,j) = A(i-1,j-1)
2. word1(i) != word2(j) 时, A(i,j) = min(A(i-1,j-1),A(i-1,j),A(i,j-1))+1
