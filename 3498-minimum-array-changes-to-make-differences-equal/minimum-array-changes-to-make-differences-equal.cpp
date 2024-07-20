
class Solution {
public:
    int minChanges(std::vector<int>& nums, int k) {
        int length = nums.size();
        std::map<int, std::vector<int>> diffMap;
        std::vector<int> maxValues;

        // Iterate through the pairs and populate the map and vector
        for (int i = 0; i < length / 2; ++i) {
            int startVal = nums[i];
            int endVal = nums[length - i - 1];
            int difference = std::abs(startVal - endVal);
            int maxPossible = std::max({startVal, endVal, k - startVal, k - endVal});
            
            diffMap[difference].push_back(maxPossible);
            maxValues.push_back(maxPossible);
        }

        // Sort the maxValues for efficient querying
        std::sort(maxValues.begin(), maxValues.end());
        int minChangesRequired = length / 2;

        // Custom binary search function
        auto binarySearch = [&](const std::vector<int>& vec, int target) -> int {
            int low = 0;
            int high = vec.size();
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (vec[mid] >= target) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        };

        // Calculate the minimum number of changes needed
        for (const auto& entry : diffMap) {
            int currentDiff = entry.first;
            int index = binarySearch(maxValues, currentDiff);
            int changes = index * 2 + (length / 2 - index);

            for (const auto& value : entry.second) {
                if (value < currentDiff) {
                    changes -= 2;
                } else {
                    changes -= 1;
                }
            }

            minChangesRequired = std::min(minChangesRequired, changes);
        }

        return minChangesRequired;
    }
};
