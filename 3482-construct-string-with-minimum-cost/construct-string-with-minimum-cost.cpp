#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    pair<bool, int> isTerminal;

    TrieNode() : isTerminal(false, INT_MAX) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}

    int ispresent(string &word) {
        TrieNode *temp = root;
        for (char c : word) {
            if (temp->children.count(c)) {
                temp = temp->children[c];
            } else {
                return INT_MAX;
            }
        }
        if (temp->isTerminal.first) {
            return temp->isTerminal.second;
        } else {
            return INT_MAX;
        }
    }

    void insert(string &word, int cost) {
        TrieNode *temp = root;
        for (char c : word) {
            if (!temp->children.count(c)) {
                temp->children[c] = new TrieNode();
            }
            temp = temp->children[c];
        }
        temp->isTerminal.first = true;
        temp->isTerminal.second = min(cost, temp->isTerminal.second);
    }
};

class Solution {
public:
    int minimumCost(string &target, vector<string>& words, vector<int>& costs) {
        Trie wordlist;
        for (int i = 0; i < words.size(); ++i) {
            wordlist.insert(words[i], costs[i]);
        }

        int n = target.length();
        vector<long long> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) continue;
            TrieNode* temp = wordlist.root;
            for (int j = i; j < n; ++j) {
                if (!temp->children.count(target[j])) break;
                temp = temp->children[target[j]];
                if (temp->isTerminal.first) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + temp->isTerminal.second);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : (int)dp[n];
    }
};
