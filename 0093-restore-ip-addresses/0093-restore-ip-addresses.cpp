class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> current;

        backtrack(s, 0, current, result);

        return result;
    }

private:
    void backtrack(string& s, int start, vector<string>& current,
                    vector<string>& result) {
        if (current.size() == 4) {
            if (start == s.size()) {
                string ip = current[0] + "." + current[1] + "." + current[2] + "." + current[3];
                result.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
            string segment = s.substr(start, len);

            if (!isValid(segment)) continue;

            current.push_back(segment);
            backtrack(s, start + len, current, result);
            current.pop_back();
        }
    }

    bool isValid(string& segment) {
        if (segment.size() > 1 && segment[0] == '0') return false;

        int value = stoi(segment);
        return value >= 0 && value <= 255;
    }
};