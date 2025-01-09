# Letter Combinations of a Phone Number

```text
Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent. Return the answer in any
order.

A mapping of digits to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.
```

## Example 1

```text
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

## Example 2

```text
Input: digits = ""
Output: []
```

## Example 3

```text
Input: digits = "2"
Output: ["a","b","c"]
```

## Constraints

```text
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
```

## 问题分析

给定 `nums[n]` 序列，序列中的每个 `num` 可对应 `num2char[num]` 中的任意字符，要求把全排列结果保存到 `char **` 数据结构中

- 空间分配

  - 字符串长度 `len`，字符串数量 `rs_size`
  - 构建 `char **rs` 时，先为 `char **rs` 分配 `rs_size * sizeof(char *)`的空间，这是为 `rs_size` 个字符串指针提供的空间，
    再为每个指针分配 `(len+1) * sizeof(char)` 的空间，`len + 1` 是因为包含了字符串结尾的`\0`

- 递归遍历所有字符组合，并保存数据

  - 递归深度通过数值传参实现，第 i 层递归遍历第结果字符串 i 个字符的所有可能情况，并将字符存到 `char *s` 的第 i 位
  - 当递归深度达到字符串长度时，停止递归，并将 s 写入 `rs[(*i_rs)++]` 中

- 注意 `len` 为 0 的边界情况
