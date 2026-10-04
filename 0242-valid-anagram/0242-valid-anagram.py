class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = Counter(s)
        count.subtract(Counter(t))

        return all(v == 0 for v in count.values())