# Daily Temperatures

Given an array of integers `temperatures` represents the daily temperatures,
return an array `answer` such that `answer[i]` is the number of days you have to
wait after the `ith` day to get a warmer temperature. If there is no future day
for which this is possible, keep `answer[i]` == 0 instead.

## Example 1

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

## Example 2

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

## Example 3

Input: temperatures = [30,60,90]
Output: [1,1,0]

## Constraints:

    1 <= temperatures.length <= 10^5
    30 <= temperatures[i] <= 100

## Solution

### 直觉

从后向前遍历, 用 `i_max` 记录目前的最大值下标, 遍历至 `s[i]` 时:

- 若 `s[i]` >= `s[i_max]`, i_max = i
- 否则, 比较 `s[i]` 和 `s[i+1~imax]`

但是无法通过倒数第二个 100000 长度的极限情况测试用例

### 单调栈

构建一个长度为 71 的单调栈(因为值范围是 30~100, 因此栈的最大长度不超过 71) 来处理此问题

单调栈存储温度下标, 下标对应的温度是递减的

从后向前遍历温度序列, 将温度插入单调栈, 栈尾和栈尾之前元素之差即结果
