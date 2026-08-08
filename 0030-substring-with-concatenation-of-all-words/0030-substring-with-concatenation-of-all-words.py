from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []

        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        n = len(s)

        if n < total_len:
            return []

        word_count = Counter(words)
        result = []

        # Try each possible starting offset within the first word_len characters
        for offset in range(word_len):
            left = offset
            count = 0
            window_count = Counter()

            for right in range(offset, n - word_len + 1, word_len):
                word = s[right:right + word_len]

                if word in word_count:
                    window_count[word] += 1
                    count += 1

                    # If a word appears too many times, shrink from the left
                    while window_count[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        window_count[left_word] -= 1
                        count -= 1
                        left += word_len

                    # Found a valid full window
                    if count == num_words:
                        result.append(left)
                        # Shrink by one word from the left to look for the next window
                        left_word = s[left:left + word_len]
                        window_count[left_word] -= 1
                        count -= 1
                        left += word_len
                else:
                    # Current word isn't in words at all — reset window entirely
                    window_count.clear()
                    count = 0
                    left = right + word_len

        return result