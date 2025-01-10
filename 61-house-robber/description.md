# House Robber

```text
You are a professional robber planning to rob houses along a street. Each
house has a certain amount of money stashed, the only constraint stopping you
from robbing each of them is that adjacent houses have security systems
connected and it will automatically contact the police if two adjacent houses
were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.
```

## Example 1

```text
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

## Example 2

```text
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

## Constraints

```text
1 <= nums.length <= 100
0 <= nums[i] <= 400
```

## 问题分析

用 sum(n) 代表到达第 n 个点前最大的收益,
则 sum(n) = max(sum(n-2)+nums(n-2), sum(n-3)+nums(n-3))，且 sum(0)= 0, sum(1) = 0, sum(2) = nums(0)
最大值存在于 sum(numsSize-1)+nums(numsSize-1) 和 sum(numsSize-2)+nums(numsSize-2) 之间

此算法无法处理总长度小于 4 的情况，需要专门讨论
