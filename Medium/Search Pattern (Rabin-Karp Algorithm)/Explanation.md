## Summary
This code snippet is a class called `Solution` that contains a method called `search`. The method takes two string inputs, `pat` and `txt`, and returns a vector of integers. The `search` method implements the Rabin-Karp algorithm to find all occurrences of the pattern `pat` in the text `txt`.

## Example Usage
```cpp
Solution obj;
string pattern = "abc";
string text = "ababcabc";
vector<int> result = obj.search(pattern, text);
// result = [3, 4, 5]
```

## Code Analysis
### Inputs
- `pat` (string): The pattern to search for in the text.
- `txt` (string): The text in which to search for the pattern.
___
### Flow
1. Initialize variables `q` as 101 (a prime number), `d` as 26 (the number of possible characters), `M` as the size of the pattern, `N` as the size of the text, `p` as 0 (hash value of the pattern), `t` as 0 (hash value of the current window in the text), and `h` as 1 (d^(M-1) % q).
2. Calculate the hash value of the pattern and the first window in the text.
3. Iterate through each window in the text and compare its hash value with the hash value of the pattern.
4. If the hash values match, compare each character in the window with the corresponding character in the pattern to confirm the match.
5. If the match is confirmed, add the starting index of the window to the result vector.
6. Update the hash value of the next window by subtracting the hash value of the first character in the current window and adding the hash value of the next character.
7. Return the result vector.
___
### Outputs
A vector of integers representing the starting indices of all occurrences of the pattern in the text.
___
