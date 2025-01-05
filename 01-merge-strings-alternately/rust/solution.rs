pub mod Solution;
impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        word1
            .chars()
            .zip(word2.chars())
            .flat_map(|(c1, c2)| [c1, c2])
            .chain(word1.chars().skip(word2.len()))
            .chain(word2.chars().skip(word1.len()))
            .collect()
    }
}
//  word1.chars() and word2.chars() convert the strings into iterators of characters.
//  zip combines the characters from word1 and word2 into pairs.
//  flat_map applies a closure to each pair of characters, flattening the resulting iterator of characters into a single iterator.
//  [c1, c2] creates an array with the two characters from each pair.
//  chain is used to append the remaining characters from word1 and word2.
//  word1.chars().skip(word2.len()) takes the characters of word1 starting from the length of word2.
//  word2.chars().skip(word1.len()) takes the characters of word2 starting from the length of word1.
//  collect collects the characters into a String, resulting in the merged string.
