# Keys and Rooms

There are n rooms labeled from 0 to n - 1 and all the rooms are locked except
for room 0. Your goal is to visit all the rooms. However, you cannot enter a
locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key
has a number on it, denoting which room it unlocks, and you can take all of
them with you to unlock the other rooms.

Given an array `rooms` where `rooms[i]` is the set of keys that you can obtain if
you visited room i, return true if you can visit all the rooms, or false
otherwise.

## Example 1

Input: rooms = `[[1],[2],[3],[]]`
Output: true
Explanation:
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

## Example 2

Input: rooms = `[[1,3],[3,0,1],[2],[0]]`
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.

## Constraints

    n == rooms.length
    2 <= n <= 1000
    0 <= rooms[i].length <= 1000
    1 <= sum(rooms[i].length) <= 3000
    0 <= rooms[i][j] < n
    All the values of rooms[i] are unique.

## 思路

问题分析：
给了一个数组 `rooms[n]`，数组成员存放数组成员下标，访问数组成员后获得对应下标数组成员的访问权限，最初只能访问 `rooms[0]`，问能否访问所有数组成员；

解决方法：

- 使用深度优先搜索处理，访问一个成员后，递归访问其中存储的所有下标
- 用全局一维数组 `entered[n]` 记录是否访问过成员，递归函数不会在已访问过的成员上调用(注意是已访问过仅仅是访问，并非完成其中所有下标的遍历，否则会出现死循环)
