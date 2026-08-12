class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;   // farthest index reachable with 'jumps' jumps so far
        int farthest = 0;     // farthest index reachable by exploring one more step

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // If we've reached the boundary of the current jump's reach,
            // we must take another jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};