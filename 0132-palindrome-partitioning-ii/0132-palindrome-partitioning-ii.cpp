class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) isPalin[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    isPalin[i][j] = (len == 2) || isPalin[i + 1][j - 1];
                }
            }
        }

        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            if (isPalin[0][i]) {
                dp[i] = 0;
                continue;
            }

            for (int j = 1; j <= i; j++) {
                if (isPalin[j][i] && dp[j - 1] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};