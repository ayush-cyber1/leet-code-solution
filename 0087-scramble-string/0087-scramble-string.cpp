class Solution {
public:
    bool isScramble(string s1, string s2) {
        memo.clear();
        return solve(s1, s2);
    }

private:
    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.size();
        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) {
            memo[key] = false;
            return false;
        }

        for (int i = 1; i < n; i++) {
            string s1left = s1.substr(0, i);
            string s1right = s1.substr(i);

            string s2left = s2.substr(0, i);
            string s2right = s2.substr(i);
            if (solve(s1left, s2left) && solve(s1right, s2right)) {
                memo[key] = true;
                return true;
            }

            string s2left2 = s2.substr(0, n - i);
            string s2right2 = s2.substr(n - i);
            if (solve(s1left, s2right2) && solve(s1right, s2left2)) {
                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
};