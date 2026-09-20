class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxCount = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int duplicates = 0;
            int localMax = 0;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy);
                }

                string key = to_string(dx) + "_" + to_string(dy);
                slopeCount[key]++;
                localMax = max(localMax, slopeCount[key]);
            }

            maxCount = max(maxCount, localMax + duplicates + 1);
        }

        return maxCount;
    }

private:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            b = a ^ b ^ (a = b);
        }
        return a;
    }
};