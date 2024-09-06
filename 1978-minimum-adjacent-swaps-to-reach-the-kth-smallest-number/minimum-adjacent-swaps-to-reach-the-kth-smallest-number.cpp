class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;

        // Generate the k-th permutation
        while (k-- > 0) {
            next_permutation(target.begin(), target.end());
        }

        int swaps = 0;
        string original = num;

        // Process each character in the original string and compare it to the target
        for (int i = 0; i < num.size(); i++) {
            if (original[i] != target[i]) {
                // Find where the target[i] is in the original string starting from i
                int j = i;
                while (original[j] != target[i]) {
                    j++;
                }

                // Perform adjacent swaps to bring original[j] to position i
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
