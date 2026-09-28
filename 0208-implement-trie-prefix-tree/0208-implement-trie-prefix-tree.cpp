class Trie {
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Node* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct Node {
        Node* children[26];
        bool isEnd;
        Node() : isEnd(false) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    Node* root;

    Node* find(const string& s) {
        Node* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!curr->children[idx]) return nullptr;
            curr = curr->children[idx];
        }
        return curr;
    }
};