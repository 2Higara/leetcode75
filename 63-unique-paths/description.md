## Unique Paths

There is a robot on an `m x n` grid. The robot is initially located at the
top-left corner (i.e., `grid[0][0]`). The robot tries to move to the bottom-right
corner (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or
right at any point in time.

Given the two integers `m ` and `n`, return the number of possible unique paths
that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to
`2 * 10^9`.

## Example 1

Input: m = 3, n = 7
Output: 28

## Example 2

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:

1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

## Constraints

    1 <= m, n <= 100

## Solution

- use `sum[i][j]` to represent unique paths total count to `grid[i][j]`，it's easy to find out following rules:

  - all `sum[i][0]` = 1, robot can only move right to get to `(i,0)`
  - all `sum[0][j]` = 1, robot can only move down to get to `(0,j)`
  - `sum[i][j]` = `sum[i][j-1]` + `sum[i-1][j]`(i,j != 0),
    a normal point's path count = its left point's path count + its above point's path count

- either construct a 2-dimension array or a 1-dimension list to keep track of path counts
