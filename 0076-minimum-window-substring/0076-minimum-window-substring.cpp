class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        vector<int> count(128, 0);

        // Count characters required from t
        for (char c : t) {
            count[c]++;
        }

        int left = 0;
        int required = t.length();

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            // If this character is still needed
            if (count[s[right]] > 0) {
                required--;
            }

            count[s[right]]--;

            // Window contains all characters of t
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                // Remove left character
                count[s[left]]++;

                if (count[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};