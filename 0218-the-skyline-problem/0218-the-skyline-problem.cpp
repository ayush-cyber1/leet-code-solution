class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<tuple<int, int, int>> events;

        // Create start and end events for each building
        for (auto& b : buildings) {
            events.push_back({b[0], 0, b[2]}); // Start
            events.push_back({b[1], 1, b[2]}); // End
        }

        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0); // Ground level

        vector<vector<int>> result;
        int prevHeight = 0;

        int i = 0;
        while (i < events.size()) {
            int x = get<0>(events[i]);

            // Process all events at the same x-coordinate
            while (i < events.size() && get<0>(events[i]) == x) {
                int type = get<1>(events[i]);
                int h = get<2>(events[i]);

                if (type == 0) {
                    heights.insert(h);
                } else {
                    auto it = heights.find(h);
                    if (it != heights.end()) {
                        heights.erase(it);
                    }
                }

                i++;
            }

            int currHeight = *heights.rbegin();

            // Add a key point if the skyline height changes
            if (currHeight != prevHeight) {
                result.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return result;
    }
};