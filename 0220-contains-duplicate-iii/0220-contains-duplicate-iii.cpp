class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        map<long long, long long> buckets;
        long long width = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {
            long long id = floorDiv((long long)nums[i], width);

            if (buckets.count(id)) return true;

            if (buckets.count(id - 1) && abs(nums[i] - buckets[id - 1]) <= valueDiff) return true;
            if (buckets.count(id + 1) && abs(nums[i] - buckets[id + 1]) <= valueDiff) return true;

            buckets[id] = nums[i];

            if (i >= indexDiff) {
                long long oldId = floorDiv((long long)nums[i - indexDiff], width);
                buckets.erase(oldId);
            }
        }

        return false;
    }

private:
    long long floorDiv(long long a, long long b) {
        long long d = a / b;
        if ((a % b != 0) && ((a < 0) != (b < 0))) d--;
        return d;
    }
};