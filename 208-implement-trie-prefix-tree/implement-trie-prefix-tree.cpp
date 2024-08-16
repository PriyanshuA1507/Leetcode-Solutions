class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');  // Initialize root with a null character
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption: word will be in lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        // recursive call
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWithUtil(TrieNode* root, string prefix) {
        // base case
        if (prefix.length() == 0) {
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        // recursive call
        return startsWithUtil(child, prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};
