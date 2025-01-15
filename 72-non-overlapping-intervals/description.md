# Non-overlapping Intervals

Given an array of intervals where `intervals[i] = [starti, endi]`,
return the minimum number of intervals you need to remove to make the rest of
the intervals non-overlapping.

**Note that intervals which only touch at a point are non-overlapping.**
For example, `[1, 2]` and `[2, 3]` are non-overlapping.

## Example 1

Input: intervals = `[[1,2],[2,3],[3,4],[1,3]]`
Output: 1
Explanation: `[1,3]` can be removed and the rest of the intervals are non-overlapping.

## Example 2

Input: intervals = `[[1,2],[1,2],[1,2]]`
Output: 2
Explanation: You need to remove two `[1,2]` to make the rest of the intervals non-overlapping.

## Example 3

Input: intervals = `[[1,2],[2,3]]`
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

## Constraints

    1 <= intervals.length <= 10^5
    intervals[i].length == 2
    -5 * 10^4 <= starti < endi <= 5 * 10^4

## Solution

### 直觉

- 区间可视为节点，重叠区间可视为相连，题目是在要求删除最少的节点，让所有节点都不相连
  - 优先删除重叠数最大的区间，但此思路不适用于 `[[0,2],[1,3],[1,3],[2,4],[3,5],[3,5],[4,6]]`，
    因为 `[2,4]` 是重叠最多的，按此思路应优先删除，但正确的结果却是 `[[0,2],[2,4],[4,6]]`，
    这说明`优先删除重叠数最大的区间`并非正确删除方案
  - 思路可转变为：优先构造孤立节点，首先找到边数最小的节点的所有相邻节点，然后优先删除其中边数最多的节点，
    这种思路符合直觉，但实现起来会很复杂

> 由于数值区间本身还包含了顺序信息，抽象为节点会导致这一层信息被忽略，看来不太合适

### leetcode 方案

该问题可等效为寻找最大不重叠区间数，在最优解中，先出现的区间应当让自己的 end 值尽可能小，以给后面的区间留出充足的可选空间

为什么需要 end 值尽可能小？好问题，这不是第一直觉能导出的结论，而是在第一直觉导出结论的基础上，进一步得出的结论

首先根据实际问题要建立一个毫无漏洞的第一直觉:
这道题需要我们通过删除最少的区间来建立一个不重叠的区间列表

实现方法：  
按 end 值从小到大对所有区间排序，从 end 值最小的区间向后迭代，寻找下一个 start 值大于当前 end 的区间，
找到后，该区间的 end 值必然是所有与当前区间不重叠的区间的最小 end 值，将此 end 值更新为当前 end 值，然后再寻找下一个不重叠 start

依此方案，可找出最大的不重叠区间数，而 `最大不重叠区间数 + 最小删除数 = 区间总数`，用区间总数减去最大不重叠区间数即题目所需的结果

此方案的时间复杂度为 O(n+nlogn)，排序算法的复杂度取 O(nlogn)，排序后只需要一次遍历便可统计出结果，因此复杂度为 O(n)
