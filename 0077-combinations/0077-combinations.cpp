class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int n, int k) {
        // If we have k numbers, save the combination
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            current.push_back(i);

            backtrack(i + 1, n, k);

            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return result;
    }
};