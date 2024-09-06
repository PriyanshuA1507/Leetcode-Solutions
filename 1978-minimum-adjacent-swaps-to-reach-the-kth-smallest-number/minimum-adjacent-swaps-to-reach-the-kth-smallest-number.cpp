class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;

        while (k-- > 0) {
            next_permutation(target.begin(), target.end());
        }

        int swaps = 0;
        string original = num;

        for (int i = 0; i < num.size(); i++) {
            if (original[i] != target[i]) {
            
                int j = i;
                while (original[j] != target[i]) {
                    j++;
                }

                while (j > i) {
                    swap(original[j], original[j - 1]);
                    j--;
                    swaps++;
                }
            }
        }

        return swaps;
    }
};
