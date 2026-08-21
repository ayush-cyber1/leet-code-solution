class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<long long> factorial(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            factorial[i] = factorial[i - 1] * i;
        }

        k--;

        string result;
        for (int i = n; i >= 1; i--) {
            int idx = k / factorial[i - 1];
            k %= factorial[i - 1];

            result += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }

        return result;
    }
};