class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        // dp[i][j] = does s[:i] match p[:j]?
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Handle patterns like "*", "**", "***" matching empty string
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // '*' matches empty sequence OR one more character of s
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // else dp[i][j] stays false
            }
        }

        return dp[m][n];
    }
};