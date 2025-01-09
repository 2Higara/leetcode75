# Total Cost to Hire K Workers

```md
You are given a 0-indexed integer array costs where costs[i] is the cost of
hiring the ith worker.

You are also given two integers k and `candidates`. We want to hire exactly k
workers according to the following rules:

- You will run k sessions and hire exactly one worker in each session.
  - In each hiring session, choose the worker with the lowest cost from either the
    first `candidates` workers or the last `candidates` workers. Break the tie by the
    smallest index.
  - For example, if costs = [3,2,7,7,1,2] and `candidates` = 2, then in the first
    hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
- In the second hiring session, we will choose 1st worker because they have
  the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2].
  Please note that the indexing may be changed in the process.
- If there are fewer than `candidates` workers remaining, choose the worker with
  the lowest cost among them. Break the tie by the smallest index.
  A worker can only be chosen once.

Return the total cost to hire exactly k workers.
```

## Example 1

```md
Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, `candidates` = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.

- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
  The total hiring cost is 11.
```

## Example 2

```md
Input: costs = [1,2,4,1], k = 3, `candidates` = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.

- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three `candidates`. We choose the worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
  The total hiring cost is 4.
```

## Constraints

```md
1 <= costs.length <= 10^5
1 <= costs[i] <= 10^5
1 <= k, `candidates` <= costs.length
```

## 问题分析

每轮在 costs 序列的前 candidates 个和后 candidates 个成员中找出最小值并剔除，重复执行 k 次

### 解决方案

1. 构建两个 candidates 长度的最小优先队列，用于快速搜索最小值
2. 构建一个邻接标记数组，标记已被剔除的值
3. 用双下标分别记录 candidates 序列在 costs 序列上的边界

### 新解决方案

- 首先判断前后两个 candidates 长度的队列是否会重叠
  - 若重叠，则直接构建一个长度为 costsSize 的优先队列，返回 k 个最小值即可
  - 若不重叠，用 i_l 代表左队列的边界，i_r 代表右队列的边界，i_l 和 i_r 会逐渐靠拢，在 i_l 和 i_r 重合前比较返回两个队列的最小值
    - 当 i_l + 1 == i_r 时边界重合，将两个对列合二为一，继续返回剩余的最小值即可

该方案无需记录被剔除值的下标

### 更节省空间的解决方案(还未实施) - 直接在 costs 上建堆，但是会打乱原数组

- 首先判断前后两个 candidates 长度的队列是否会重叠
  - 若重叠，直接在 costs 上建堆，返回 k 个最小值
  - 若不重叠，在前、后建两个堆，用 i_l 代表左队列的边界，i_r 代表右队列的边界，i_l 和 i_r 会逐渐靠拢，在 i_l 和 i_r 重合前比较返回两个队列的最小值
    - 当 i_l + 1 == i_r 时边界重合，i_l 和 i_r 不再更新位置，继续比较返回两个队列的最小值即可
