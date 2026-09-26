class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;

        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);
            count[sub]++;
            if (count[sub] == 2) {
                result.push_back(sub);
            }
        }

        return result;
    }
};