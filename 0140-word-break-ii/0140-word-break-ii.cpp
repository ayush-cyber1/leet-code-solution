class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;

        return solve(s, 0, wordSet, memo);
    }

private:
    vector<string> solve(string& s, int start, unordered_set<string>& wordSet,
                          unordered_map<int, vector<string>>& memo) {
        if (start == s.size()) return {""};

        if (memo.count(start)) return memo[start];

        vector<string> result;

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);

            if (wordSet.count(word)) {
                vector<string> rest = solve(s, end, wordSet, memo);

                for (string& r : rest) {
                    result.push_back(word + (r.empty() ? "" : " " + r));
                }
            }
        }

        memo[start] = result;
        return result;
    }
};