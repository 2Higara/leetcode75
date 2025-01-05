# Reorder Routes to Make All Paths Lead to the City Zero

```
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is
only one way to travel between two different cities (this network form a tree).
Last year, The ministry of transport decided to orient the roads in one
direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents
a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people
want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the
city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
```

## Example 1

```
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node
can reach the node 0 (capital).
```

## Example 2

```
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node
can reach the node 0 (capital).
```

## Example 3

```
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
```

## Constraints

```
2 <= n <= 5 * 10^4
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
```

## 思路

问题分析：
给定了一个 n 节点，(n-1) 条边的有向图，选取一个节点，通过反转边的方向，使所有边指向它，统计反转的次数；

- 连通图的边数为 n-1，因此图中不存在回路，通往节点的路径唯一，只有一种反转方法
- 另外由于不存在回路(节点之间的遍历路径唯一)，只需保证不递归来时的节点，即可避免死循环，因此无需使用标记数组
