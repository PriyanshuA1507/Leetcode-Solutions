class Solution {
public:
    vector<vector<map<int, int>>> dp;

    int solverec(vector<vector<int>>& books, int shelfWidth, int cw, int ch, int idx) {
        if (idx >= books.size()) {
            return ch;
        }

        if (dp[cw][ch].count(idx)) {
            return dp[cw][ch][idx];
        }

        int op1 = INT_MAX;
        if (books[idx][0] + cw <= shelfWidth) {
            op1 = solverec(books, shelfWidth, cw + books[idx][0],max(books[idx][1], ch), idx + 1);
        }

        int op2 = ch + solverec(books, shelfWidth, books[idx][0], books[idx][1], idx + 1);
        
        return dp[cw][ch][idx] = min(op1, op2);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp = vector<vector<map<int, int>>>(shelfWidth + 1,vector<map<int, int>>(1001));
        return solverec(books, shelfWidth, 0, 0, 0);
    }
};