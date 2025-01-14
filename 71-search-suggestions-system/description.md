# Search Suggestions System

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after
each character of searchWord is typed. Suggested products should have common
prefix with searchWord. If there are more than three products with a common
prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of
searchWord is typed.

## Example 1

Input:
products = `["mobile","mouse","moneypot","monitor","mousepad"]`,
searchWord = "mouse"
Output:

```text
[
  ["mobile","moneypot","monitor"],
  ["mobile","moneypot","monitor"],
  ["mouse","mousepad"],
  ["mouse","mousepad"],
  ["mouse","mousepad"]
]
```

Explanation: products sorted lexicographically = `["mobile","moneypot","monitor","mouse","mousepad"]`.
After typing m and mo all products match and we show user `["mobile","moneypot","monitor"]`.
After typing mou, mous and mouse the system suggests `["mouse","mousepad"]`.

## Example 2

Input: products = `["havana"]`, searchWord = "havana"
Output:

```text
[
  ["havana"],
  ["havana"],
  ["havana"],
  ["havana"],
  ["havana"],
  ["havana"]
]
```

Explanation: The only word "havana" will be always suggested while typing the search word.

## Constraints

    1 <= products.length <= 1000
    1 <= products[i].length <= 3000
    1 <= sum(products[i].length) <= 2 * 10^4
    All the strings of products are unique.
    products[i] consists of lowercase English letters.
    1 <= searchWord.length <= 1000
    searchWord consists of lowercase English letters.

## Solution

0. bruteforce，数据集较小，可以直接用排序
1. trie，更符合应用场景，但需要为每一个字符重新构建树结构
2. binary search tree，数据集较大时搜索树占用的空间比 trie 更多，但可以让树节点直接指向数据集
