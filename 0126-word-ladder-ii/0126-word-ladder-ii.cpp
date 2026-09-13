class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) return result;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel = {beginWord};
        wordSet.erase(beginWord);
        bool found = false;

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            unordered_set<string> toRemove;

            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        temp[i] = c;

                        if (wordSet.count(temp)) {
                            nextLevel.insert(temp);
                            toRemove.insert(temp);
                            parents[temp].push_back(word);

                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }

            for (const string& w : toRemove) {
                wordSet.erase(w);
            }

            currentLevel = nextLevel;
        }

        if (!found) return result;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);

        return result;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                    unordered_map<string, vector<string>>& parents,
                    vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> fullPath(path.rbegin(), path.rend());
            result.push_back(fullPath);
            return;
        }

        for (const string& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};