# Min Cost Climbing Stairs

```text
You are given an integer array cost where cost[i] is the cost of ith step on a
staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
```

## Example 1

```text
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.

- Pay 15 and climb two steps to reach the top.
  The total cost is 15.
```

## Example 2

```text
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.

- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
  The total cost is 6.
```

## Constraints

```text
2 <= cost.length <= 1000
0 <= cost[i] <= 999
```

## 问题分析

设第 n 个点的最小总花费为 `sum[n]`，则 `sum[n]` = min(`sum[n-1]`+`cost[n-1]`, `sum[n-2]` + `cost[n-2]`)

从后向前递推直至 0 和 1，而 `sum[0] = 0`，`sum[1] = 0`，因为这两个点可以直接取到

- 反推递归会超时，需要正推+构建邻接数组减少运算
- 正推不使用邻接数组也可以，用两个变量分别保存前两个的最小花费即可
